#ifndef WALLPOST_H_
#define WALLPOST_H_
#include <string>
using std::string;

class WallPost{

private:
	string contents;
	string timePosted;
	string userName;
public:
	WallPost(string contents, string timePosted, string userName, string password);
	~WallPost();
	void updateTime(string time);
	void updateContents(string newContents);
	void changeUserName(string newUserName);
	string Print();
}

#endif