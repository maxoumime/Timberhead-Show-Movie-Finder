#pragma once

#include <string>

using namespace std;

namespace Role{
    enum EnumRole {Director = 0, Writer, Producer, Assistant, Actor, SIZE};
    static const char* RolesString[EnumRole::SIZE] = { "Directeur", "Scénariste", "Producteur", "Assistant", "Acteur" };

}

class Personne
{
private:
    string firstName;
    string lastName;
    Role::EnumRole role;

public:
    Personne(void);
    ~Personne(void);
    Personne(string firstName, string lastName, Role::EnumRole const &role)
            : firstName(firstName), lastName(lastName), role(role) {
    }

    string getFirstName() {
        return firstName;
    }

    void setFirstName(string firstName) {
        Personne::firstName = firstName;
    }

    string getLastName() {
        return lastName;
    }

    void setLastName(string lastName) {
        Personne::lastName = lastName;
    }

    Role::EnumRole const &getRole() const {
        return role;
    }

    void setRole(Role::EnumRole const &role) {
        Personne::role = role;
    }
    
    string toString(){
        
    }

};




