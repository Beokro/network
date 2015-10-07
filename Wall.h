#ifndef WALL_H_
#define WALL_H_

#include "DLinkList.h"
#include "WallPost.h"

class Wall{
private:
	DLinkedList<WallPost> *posts;
	string user;
public:
	DLinkedList(string u) : user(u){};
	~Wall();
	void addPost(WallPost post);
	bool removePost(string author, string date, string contents);
	string getUser();
	string updateUser(string userName);
	string Print();
	bool ReadWall(string givenWall);
}


#endif