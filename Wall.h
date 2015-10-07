#ifndef WALL_H_
#define WALL_H_

#include "DLinkList.h"
#include "WallPost.h"

class Wall(){
private:
	DLinkList<WallPost> *posts;
	string user;
public:
	DLinkList(string u) : user(u){};
	~DLinkList();
	void addPost(WallPost post);
	bool removePost(string author, string date, string contents);
	string getUser();
	string updateUser(string userName);
	string Print();
	bool ReadWall(string givenWall);
}


#endif