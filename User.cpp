#include "User.h"

User::User(string information){

}


User::User(string userName, string password, string birthday){
	this->userName = userName;
	this->password = password;
	this->bitrhday = birthday;
	this->personalWall = new Wall(userName);
}


User::~User(){
	delete personalWall;
}


void User::UpdateUser(string userName){
	this->userName = userName;
}


void UpdatePassword(string password){
	this->password = password;
}


void UpdateBirthday(string birthday){
	this->birthday = birthday;
}


void AddPost(WallPost post){
	personalWall->addPost(post);
}


bool RemovePost(string timePosted, string author, string& contents){
	return this->personalWall->removePost(author,timePosted,contents);
}


string Print(){
	string result = "";
	result+=("User: "+userName+"\n");
	result+=("Birthday: "+birthday+"\n");
	result+=("Password "+password+"\n");
	result+=personalWall->Print();
}








