#include "User.h"


User::User(string information){
	information = "same function has been implemt in userNetWork.cpp";
}


User::User(string userName, string password, string birthday){
	this->userName = userName;
	this->password = password;
	this->birthday = birthday;
	this->personalWall = new Wall(userName);
}

User::User(const User& cuser) {
	this->userName = cuser.userName;
	this->birthday = cuser.birthday;
	this->password = cuser.password;
	this->personalWall = new Wall(userName,cuser.personalWall->GetPosts());
	for (string name : cuser.friends)
		friends.push_back(name);
	for (string name : cuser.friendReq)
		friendReq.push_back(name);
}


User::~User(){
	//std::cout<<"Delte from User" << userName << std::endl;
	delete personalWall;
}


void User::UpdateUser(string userName){
	this->userName = userName;
}


void User::UpdatePassword(string password){
	this->password = password;
}


void User::UpdateBirthday(string birthday){
	this->birthday = birthday;
}


void User::AddPost(WallPost post){
	personalWall->addPost(post);
}


bool User::RemovePost(string timePosted, string author, string& contents){
	return this->personalWall->removePost(author,timePosted,contents);
}

User& User::operator=(const User& u) {
	if(this->personalWall!=NULL)
		delete this->personalWall;
	this->userName = u.userName;
	this->birthday = u.birthday;
	this->password = u.password;
	this->personalWall = new Wall(*u.personalWall);
	this->parent = u.parent;
	for (string name : u.friends)
		friends.push_back(name);
	for (string name : u.friendReq)
		friendReq.push_back(name);
	for (User * u : friendPointer)
		friendPointer.push_back(u);

	return *this;
}




string User::Print(){
	string result = "";
	result += PrintPost();
	result += PrintFriends();
	return result;
}

string User::PrintForSave() {
	string result = "";
	result += ("User: " + userName + "\n");
	result += ("Birthday: " + birthday + "\n");
	result += ("Password: " + password + "\n" + "\n");
	result += personalWall->PrintForSave();
	result += PrintFriends();
	return result;
}

string User::PrintPost() {
	string result = "\n";
	result += ("User: " + userName + "\n\n");
	result += personalWall->Print();
	return result;
}

string User::PrintFriends() {
	string result = "";
	result += "Friends: ";
	for (string name : friends) {
		result += name;
		result += " ";
	}
	result += ".\n";

	result += "FriendsReq ";
	for (string name : friendReq) {
		result += name;
		result += " ";
	}
	result += ".\n";
	return result;
}

string User::PrintFriendsAsList() {
	string result="";
	int size = friends.size();
	result += "Here are your friends\n";
	for (int i = 0; i < size; i++) {
		result += (to_string(i) + ". ");
		result += friends[i];
		result += "\n";
	}
	return result;
}
string User::PrintFriendReq() {
	string result = "";
	int size = friendReq.size();
	if (size == 0)
		return result;
	result += "You have some pending friend requests\n";
	for (int i = 0; i < size; i++) {
		result += (to_string(i) + ". ");
		result += friendReq[i];
		result += "\n";
	}
	return result;
}


void User::DisplayFriendList() {
	cout << "Following is the list of your friends" << endl;
	for (string name : friends) {
		cout << name << endl;
	}
	cout << endl;
}

void User::DisplayFriendReq() {
	cout << "Following is the list of your friend request\n";
	for (string name : friendReq) {
		cout << name << endl;
	}
	cout << endl;
}


//add the friend at index of request to friends and return the name of this friend
string User::ApproveRequest(int index) {
	if (index < 0 || index >= friendReq.size())
		return "IndexOurOfRange";
	cout << "WHY didn't I change JJACK?\n";
	friends.push_back(friendReq[index]);
	friendReq.erase(friendReq.begin() + index);
	return friends[friends.size() - 1];
}

//delete the friend Request
void User::DenyRequest(int index) {
	if (index < 0 || index >= friendReq.size()) {
		cout << "index of delte is incorrect\n\n";
		return;
	}
	friendReq.erase(friendReq.begin() + index);
}

//check if friend Request already exist or they are already friends
bool User::CheckFriendReq(string name) {
	int size = friendReq.size();
	for (int i = 0; i < size; i++) {
		if (friendReq[i] == name)
			return true;
	}

	size = friends.size();
	for (int i = 0; i < size; i++) {
		if (friends[i] == name)
			return true;
	}

	return false;
}

//delete all of the friend information of 
void User::DeleteAllFriendof(string name) {
	int size = friends.size();
	for (int i = 0; i < size; i++) {
		if (friends[i] == name)
			friends.erase(friends.begin() + i);
	}
	size = friendReq.size();
	for (int i = 0; i < size; i++) {
		if (friendReq[i] == name)
			friendReq.erase(friendReq.begin() + i);
	}
}

//delete a friend
void User::DeleteFriend(string name) {
	int size = friends.size();
	for (int i = 0; i < size; i++) {
		if (friends[i] == name) {
			friends.erase(friends.begin() + i);
			return;
		}
	}
	cout << name << " is not your friend\n";
}

//Check if someone is your friend
bool User::CheckFriendShip(string name) {
	for (string f : friends) {
		if (f == name)
			return true;
	}
	return false;
}

//Add respone to its wall
bool User::AddResponse(string name, string contents, string author, string time, string partial, string commentTime) {
	if (!CheckFriendShip(name) && name!=userName) {
		cout << "You are not friend of " << this->userName << endl;
		return false;
	}
	return personalWall->AddResponse( name,  contents,  author,  time,  partial, commentTime);
}

//remove the response from the wallpost on the wall
bool User::RemoveResponse(int index, string author, string partialComment) {
	return personalWall->RemoveResponseAtIndex(index, author, partialComment);
}

//check if user has add another user as frienda as pointer
bool User::CheckFriendPointer(string name) {
	for (User* u : friendPointer) {
		if (name == u->GetUserName())
			return true;
	}
	if (name == userName)
		return true;
	return false;
}
