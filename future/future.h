#include <stdbool.h>
#include <pthread.h>

typedef struct _future {
  pthread_t thread;
  pthread_attr_t attr;
  void *(*func) (void *);
} future;

typedef struct _future_arg {
  void *(*func) (void *);
  void * arg;
} future_arg;

typedef struct _promise {
  int result;
  pthread_mutex_t mutex;
  pthread_cond_t cond;
  bool done;
  int id;
} promise;

future* future_create(void *(*start_routine) (void *));
void future_start(future* f, void* arg);
void future_stop(future* f);
void future_close(future* f);

promise* promise_create();
int promise_get(promise* p);
void promise_set(promise *p, int res);
bool promise_done(promise* p);
void promise_close(promise *p);

#ifdef DEBUG
#define msg(format, ...) printf("T(%d)|" format "\n", (int)pthread_self(), ##__VA_ARGS__)
#else
#define msg(format, ...) 
#endif

typedef struct _node {
    int val;
    struct _node *next;
} node;

node* node_create(int val, node* next);
node* node_append(node* n, int val);
void node_close(node* n);

typedef struct _channel {
  node* n;
  pthread_mutex_t mutex;
  pthread_cond_t cond;
  bool done;
  int id;
} channel;

channel* channel_create();
void channel_close(channel* ch);
void channel_add(channel* ch, int val);
int channel_get(channel* ch);
