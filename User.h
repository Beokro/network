#ifndef USER_H_
#define USER_H_

#include "Wall.h"

class User{
private:
	Wall *personalWall;
	string userName;
	string password;
	string birthday;

public:
	User(string information);
	User(string userName, string password, string birthday);
	User(const User& cuser);
	~User();
	void UpdateUser(string userName);
	void UpdatePassword(string password);
	void UpdateBirthday(string birthday);
	void AddPost(WallPost post);
	bool RemovePost(string timePosted, string author, string& contents);
	string Print();
	string GetUserName(){return userName;}
	bool CheckPassword(string pass) { return pass == password; }

};



#endif