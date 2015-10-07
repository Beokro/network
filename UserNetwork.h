#ifndef USERNETWORK_H_
#define USERNETWORK_H_
#include "User.h"


class UserNetwork(){
private:
	DLinkedList<User*> users;

public:
	UserNetwork(string userName, string password, string birthday);
	~UserNetwork();
	bool AddUser(string userName, string password, string birthday);
	bool AddUser(User user);
	bool RemoveUser(string userName);
	void SaveInFile();
	void ReadFromFile(string filename);
}

#endif