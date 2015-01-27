#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>
#include <stdarg.h>
#include <string.h>

#include "future.h"

int prev = 0;

future* future_create(void *(*start_routine) (void *)) {
  future* f = malloc(sizeof(future));

  pthread_attr_init(&f->attr);
  pthread_attr_setdetachstate(&f->attr, PTHREAD_CREATE_JOINABLE);

  f->func = start_routine;

  return f;
}

void* future_func_wrapper(void *arg) {
  //msg("WRAP");
  future_arg* f = (future_arg*) arg;
  void* res = f->func(f->arg);
  free(f);
  //msg("WRAPPED");
  pthread_exit(res);
  return res;
}
void future_start(future* f, void* arg) {
  future_arg* farg = malloc(sizeof(future_arg));
  farg->func = f->func;
  farg->arg = arg;
  pthread_create(&f->thread, &f->attr, future_func_wrapper, farg);
}

void future_stop(future* f) {
  pthread_cancel(f->thread);
}

void future_close(future* f) {
  void * status;
  int rc = pthread_join(f->thread, &status);
  pthread_attr_destroy(&f->attr);
  free(f);
}

promise* promise_create() {
  promise* p = malloc(sizeof(promise));
  pthread_mutex_init(&p->mutex, NULL);
  pthread_cond_init(&p->cond, NULL);
  srand(time(NULL));
  p->id = rand() + prev;
  prev = p->id;
  msg("P(%d) created", p->id);

  return p;
}

void promise_set(promise* p, int res) {
  msg("P(%d) set LOCK", p->id);
  pthread_mutex_lock(&p->mutex);
  p->result = res;
  p->done = true;
  pthread_cond_broadcast(&p->cond);
  msg("P(%d) set UNLOCK", p->id);
  pthread_mutex_unlock(&p->mutex);
}

int promise_get(promise* p) {
  msg("P(%d) get LOCK", p->id);
  pthread_mutex_lock(&p->mutex);
  while(!p->done) {
    msg("P(%d) get WAIT", p->id);
    pthread_cond_wait(&p->cond, &p->mutex);
  }
  msg("P(%d) get UNLOCK", p->id);
  pthread_mutex_unlock(&p->mutex);
  return p->result;
}

int promise_get_and_reset(promise* p) {
  msg("P(%d) get LOCK", p->id);
  pthread_mutex_lock(&p->mutex);
  while(!p->done) {
    msg("P(%d) get WAIT", p->id);
    pthread_cond_wait(&p->cond, &p->mutex);
  }
  int result = p->result;
  p->done = false;
  msg("P(%d) get UNLOCK", p->id);
  pthread_mutex_unlock(&p->mutex);
  return result;
}

bool promise_done(promise* p) {
  pthread_mutex_lock(&p->mutex);
  bool done = p->done;
  pthread_mutex_unlock(&p->mutex);
  return done;
}

void promise_close(promise* p) {
  pthread_mutex_destroy(&p->mutex);
  pthread_cond_destroy(&p->cond);
  free(p);
}

node* node_create(int val, node* next) {
  node* n = malloc(sizeof(node));
  n->val = val;
  n->next = next;
  return n;
}

void node_close(node* n) {
  node* n1 = n;
  while(n1 != NULL) {
    node* n2 = n1;
    n1 = n2->next;
    free(n2);
  }
}

node* node_append(node* n, int val) {
  if(n == NULL) {
    //printf("n(%d) is null\n", (int)n);
    return node_create(val, NULL);
  } else if(n->next == NULL) {
    //printf("n(%d)->next(%d) is null\n", (int)n, (int)n->next);
    n->next = node_create(val, NULL);
    return n;
  } else {
    //printf("n(%d)->next(%d) recurse\n", (int)n, (int)n->next);
    node_append(n->next, val);
    return n;
  }
}

int node_count(node* n) {
  if(n == NULL) {
    return 0;
  } else {
    return 1 + node_count(n->next);
  }
}

channel* channel_create() {
  channel* ch = malloc(sizeof(channel));
  pthread_mutex_init(&ch->mutex, NULL);
  pthread_cond_init(&ch->cond, NULL);
  ch->n = NULL;
  srand(time(NULL));
  ch->id = rand()+prev;
  msg("C(%d) created", ch->id);

  return ch;
}

void channel_close(channel* ch) {
  node_close(ch->n);
  pthread_mutex_destroy(&ch->mutex);
  pthread_cond_destroy(&ch->cond);
  free(ch);
}

void channel_add(channel* ch, int val) {
  msg("C(%d) set LOCK", ch->id);
  pthread_mutex_lock(&ch->mutex);
  //node* n = node_create(val, ch->n);
  //msg("C(%d) set(%d) before", ch->id, node_count(ch->n));
  //msg("before node_append: %d", (int)ch->n);
  ch->n = node_append(ch->n, val);
  //msg("after node_append: %d", (int)ch->n);
  msg("C(%d) set(%d) added: %d", ch->id, node_count(ch->n), val);
  pthread_cond_signal(&ch->cond);
  msg("C(%d) set UNLOCK", ch->id);
  pthread_mutex_unlock(&ch->mutex);
}

int channel_get(channel* ch) {
  msg("C(%d) get LOCK", ch->id);
  pthread_mutex_lock(&ch->mutex);
  while(ch->n == NULL) {
    pthread_cond_wait(&ch->cond, &ch->mutex);
  }
  int result = ch->n->val;
  node* n = ch->n;
  ch->n = ch->n->next;
  msg("C(%d) get(%d) val==%d", ch->id, node_count(ch->n), result);
  free(n);
  msg("C(%d) get UNLOCK", ch->id);
  pthread_mutex_unlock(&ch->mutex);
  return result;

}

