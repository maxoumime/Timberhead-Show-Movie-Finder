#pragma once

enum class EnumRole {Director, Writer, Producer, Assistant, Actor};


class Personne
{
    Personne(void);
    ~Personne(void);

private:
    String firstName;
    String lastName;
    EnumRole role;

public:
    Personne(String firstName, String lastName, EnumRole const &role)
            : firstName(firstName), lastName(lastName), role(role) {
    }

    Personne() {
    }

    String getFirstName() const {
        return firstName;
    }

    void setFirstName(String firstName) {
        Personne::firstName = firstName;
    }

    String getLastName() const {
        return lastName;
    }

    void setLastName(String lastName) {
        Personne::lastName = lastName;
    }

    EnumRole const &getRole() const {
        return role;
    }

    void setRole(EnumRole const &role) {
        Personne::role = role;
    }

};




