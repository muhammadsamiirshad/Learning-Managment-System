#pragma once
#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

class user {
protected:
	int id;
	string name, email, phoneno;
public:
	// Constructor
	user(int id = 0, const string& name = "", const string& email = "", const string& phoneno = "");
	
	// Accessors
	int getId() const;
	string getName() const;
	string getEmail() const;
	string getPhoneNo() const;
	
	// Mutators
	void setId(int id);
	void setName(const string& name);
	void setEmail(const string& email);
	void setPhoneNo(const string& phoneno);
};

#endif
