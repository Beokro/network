#ifndef USERNETWORK_H_
#define USERNETWORK_H_
#include "User.h"


class UserNetwork(){
private:
	DLinkedList<User> *users;

public:
	UserNetwork(string userName);

}

#endif