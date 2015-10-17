#ifndef USERNETWORK_H_
#define USERNETWORK_H_
#include "User.h"
#include <iostream>
#include <fstream>

class UserNetwork{
private:
	DLinkedList<User> *users;

public:
	UserNetwork() : users(new DLinkedList<User>()) {}
	~UserNetwork(); 
	bool AddUser(string userName, string password, string birthday);
	bool AddUser(User user);
	bool RemoveUser(string userName);
	bool CheckUserName(string userName);
	User* GetUser(string userName, string password);
	void SaveInFile(string fileName);
	void ReadFromFile(string filename);
	string print();
	int NumberOfUser();
};

#endif