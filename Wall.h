#ifndef WALL_H_
#define WALL_H_

#include "WallPost.h"
#include "DLinkList.h"

class Wall{
private:
	DLinkedList<WallPost> *posts;
	string user;
public:
	Wall(string u) : user(u), posts(new DLinkedList<WallPost>()) {}
	~Wall();
	void addPost(WallPost post);
	bool removePost(string author, string date, string &contents);
	string getUser();
	void updateUser(string userName);
	string Print();
	bool ReadWall(string givenWall);
};




#endif