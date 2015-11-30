#ifndef WALL_H_
#define WALL_H_

#include "WallPost.h"
#include<vector>
using std::vector;

class Wall{
private:
	vector<WallPost> posts;
	string user;
public:
	Wall() :  user("") {}
	Wall(const Wall& w);
	Wall(string u) :  user(u) {}
	Wall(string u, vector<WallPost> p);
	~Wall();
	void addPost(WallPost post);
	bool removePost(string author, string date, string &contents);
	string getUser();
	void updateUser(string userName);
	string Print();
	string PrintForSave();
	bool ReadWall(string givenWall);
	Wall operator= (const Wall& w);
	vector<WallPost>& GetPosts() { return posts; }
	int FindIndexOfPost(string author, string date, string contents);
	void RemovePostAtindex(int index);
	//Add respone to its post
	bool AddResponse(string name, string contents, string author, string time, string partial, string commentTime);
	bool RemoveResponseAtIndex(int index, string author, string partial);
};



#endif