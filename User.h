#ifndef USER_H_
#define USER_H_
#include<vector>
#include<iostream>
using namespace std;

#include "Wall.h"

class User{
private:
	Wall *personalWall;
	string userName;
	string password;
	string birthday;
	vector<string> friends;
	vector<string> friendReq;
	vector<User*> friendPointer;
	User* parent = NULL;
	bool visted = false;

public:
	User() : personalWall(new Wall()), userName(""), password(""), birthday("") {}
	User(string information);
	User(string userName, string password, string birthday);
	User(const User& cuser);
	~User();
	void UpdateUser(string userName);
	void UpdatePassword(string password);
	void UpdateBirthday(string birthday);
	void AddPost(WallPost post);
	bool RemovePost(string timePosted, string author, string& contents);
	void RemovePostAtIndex(int index) { personalWall->RemovePostAtindex(index); }
	
	string Print();
	string PrintForSave();
	string PrintPost();
	string PrintFriends();
	string PrintFriendsAsList();
	string PrintFriendReq();

	string GetUserName(){return userName;}
	string GetPassword() { return password;}
	string GetBirthday() { return birthday; }
	bool CheckPassword(string pass) { return pass == password; }
	User& operator=(const User& u);
	void DisplayFriendList();
	void DisplayFriendReq();
	int FindIndexOfPost(string author, string date, string contents) { return personalWall->FindIndexOfPost(author, date, contents); }

	//Someone send the request to you
	void AppendFriendRequest(string name) { friendReq.push_back(name); }

	//add the friend at index of request to friends and return the name of this friend
	string ApproveRequest(int index);

	//delete the requ at index
	void DenyRequest(int index);

	//add the friend because other accept your request
	void AddFriend(string name) { friends.push_back(name); }

	//get friendlist
	vector<string>& GetFriendList() { return friends;}

	//get pending request List
	vector<string>& GetReqList() { return friendReq; }

	//check if the friend request has already exist
	bool CheckFriendReq(string name);

	//delete all friend information of 
	void DeleteAllFriendof(string name);

	//CHheck if someone is your friend
	bool CheckFriendShip(string name);

	//delete a friend
	void DeleteFriend(string name);

	//Add respone to its wall
	bool AddResponse(string name, string contents, string author, string time, string partial, string commentTime);

	//remove the response from the wallpost on the wall
	bool RemoveResponse(int index, string author, string partialComment);

	//check if user has add another user as frienda as pointer
	bool CheckFriendPointer(string name);

	//Add Friend As Pointer
	void AddFriendPointer(User * u) {
		friendPointer.push_back(u);
	}

	//test purpose, show how many frien pointer it have
	int NumberOfFriendPointer() {
		return friendPointer.size();
	}

	//print the name of the freind in friend Pointer lis, testing purpose
	void PrintFriendPointerName() {
		for (User * u : friendPointer) {
			cout << u->GetUserName() << endl;
		}
	}

	//Reset the visted to False
	void SetVistedFalse() { visted = false; }

	//Reset the visted to True
	void SetVistedTrue() { visted = true; }

	//Return the friend pointer List
	vector<User*>& GetFriendPointerList() {
		return friendPointer;
	}

	//Check if this user is visted
	bool CheckVisted() { return visted; }

	//Method to set and get the parent
	void SetParent(User * u) { this->parent = u; }
	User * GetParent() { return parent; }

	//For generating purpose
	void ForceToAddFriend(string name) { friends.push_back(name); }

};



#endif