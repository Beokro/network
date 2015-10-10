#include "User.h"

User::User(string information){

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




string User::Print(){
	string result = "";
	result+=("User: "+userName+"\n");
	result+=("Birthday: "+birthday+"\n");
	result+=("Password "+password+"\n"+"\n");
	result+=personalWall->Print();
	return result;
}








