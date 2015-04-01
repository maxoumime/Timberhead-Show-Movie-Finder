#pragma once

#include <string>

using namespace std;

enum class EnumRole {Director, Writer, Producer, Assistant, Actor};


class Personne
{
private:
    string firstName;
    string lastName;
    EnumRole role;

public:
    Personne(void);
    ~Personne(void);
    Personne(string firstName, string lastName, EnumRole const &role)
            : firstName(firstName), lastName(lastName), role(role) {
    }

    string getFirstName() const {
        return firstName;
    }

    void setFirstName(string firstName) {
        Personne::firstName = firstName;
    }

    string getLastName() const {
        return lastName;
    }

    void setLastName(string lastName) {
        Personne::lastName = lastName;
    }

    EnumRole const &getRole() const {
        return role;
    }

    void setRole(EnumRole const &role) {
        Personne::role = role;
    }

};




