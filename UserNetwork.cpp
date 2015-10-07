#include "UserNetwork.h"

UserNetwork::UserNetwork(string userName, string password, string birthday){
	this->users = new User(userName, password, birthday);
}


UserNetwork::~UserNetwork(){
	delete users;
}


bool UserNetwork::AddUser(string userName, string password, string birthday){
	for(user : users){
		if(user.GetUserName()==userName)
			return false;
	}
	this->users->AppendElement(User(userName, password, birthday));
	return true;
}


bool UserNetwork::AddUser(User user){
	for(User* u : users){
		if(user->GetUserName()==u.GetUserName())
			return false;
	}
	this->users->AppendElement(user);
	return true;
}


bool UserNetwork::RemoveUser(string userName){
	for(User* user : users){
		if(user->GetUserName() == userName){
			if(user->GetPrev()!=NULL){
				user->GetPrev()->SetNext(user->GetNext());
			}
			delete user;
			return true;
		}
	}
	return false;
}



void UserNetwork::SaveInFile(){

}

void UserNetwork::ReadFromFile(string filename){

}







