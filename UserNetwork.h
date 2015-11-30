#ifndef USERNETWORK_H_
#define USERNETWORK_H_
#include "User.h"
#include <iostream>
#include <fstream>
#include <list>
#include <map>
using std::list;
using std::map;

class UserNetwork{
private:
	map<string, User*> userMap;
public:
	UserNetwork() {}
	~UserNetwork(); 
	bool AddUser(string userName, string password, string birthday);
	bool AddUser(User user);
	bool RemoveUser(string userName);
	bool CheckUserName(string userName);
	User* GetUser(string userName, string password);
	User* GetUser(string userName);
	void SaveInFile(string fileName);
	void ReadFromFile(string filename);
	string print();
	string PrintForSave();
	int NumberOfUser();

	void SendRequest(string user1,string User2);
	void ApproveReq(User * u1, int indexOfApp);
	void DenyReq(User * u1, int indexOfDen);
	vector<string> GetMatchName(string partial, string currentName);
	int FindIndexOfPost(string author, string date, string firstWord, User &currentUser);
	void DeleteAllFriendof(string name);

	//Delte the friendship between user1 and user2
	void DelteFriend(User  *user1, string name2);

	//Add the friend pointer to all of the user
	void AddFriendPointer();

	//DisplayALlPointer Names of all the users
	/*void DisplayALlPointerInfor() {
		for (User & u : users) {
			u.PrintFriendPointerName() ;
		}
	}*/

	//Set All visted to false
	void AllVistedToFalse() {
		map<string, User*>::iterator it = userMap.begin();
		map<string, User*>::iterator ed = userMap.end();
		while (it != ed) {
			it->second->SetVistedFalse();
			it++;
		}
	}

	//Find out the degree of separation and shortest path
	int FindDegreeOfSeparation(User * u,string name, list<string> &sPath);
	list<string> shortestPath(User * u,string name, list<string> &sPath);

	//Find all friends in a certain number of degree away
	vector<string>AllUserInNDegreeAway(User* u,int n);

	//Directly add two user as friend
	void ForceBecomeFriend(int index1, int index2);

	//Check user at two index is friend
	bool CheckFriendAtIndex(int index1, int index2);
};

#endif