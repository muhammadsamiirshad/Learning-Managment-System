#include "user.h"

user::user(int id, const string& name, const string& email, const string& phoneno)
    : id(id), name(name), email(email), phoneno(phoneno) {
}

int user::getId() const {
    return id;
}

string user::getName() const {
    return name;
}

string user::getEmail() const {
    return email;
}

string user::getPhoneNo() const {
    return phoneno;
}

void user::setId(int id) {
    this->id = id;
}

void user::setName(const string& name) {
    this->name = name;
}

void user::setEmail(const string& email) {
    this->email = email;
}

void user::setPhoneNo(const string& phoneno) {
    this->phoneno = phoneno;
}

