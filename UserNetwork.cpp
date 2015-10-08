#include "UserNetwork.h"

UserNetwork::UserNetwork(string userName, string password, string birthday){
	this->users = new User(userName, password, birthday);
}


UserNetwork::~UserNetwork(){
	delete users;
}


bool UserNetwork::AddUser(string userName, string password, string birthday){
	DLinkedList<User>* user = users->GetHead();
	while(user!=NULL){
		if(user->GetData().GetUserName()==userName)
			return false;
		user = user->GetNext();
	}
	this->users->AppendElement(User(userName, password, birthday));
	return true;
}


bool UserNetwork::AddUser(User user){
	DLinkedList<User>* u = users->GetHead();
		while(u != NULL){
			if(u->GetData().GetUserName()==user.GetUserName())
				return false;
			u=u->GetNext();
	}
	this->users->AppendElement(user);
	return true;
}


bool UserNetwork::RemoveUser(string userName){
	DLinkedList<User>* user = users->GetHead();
	while(user!=NULL){
		if(user->GetData().GetUserName() == userName){
			if(user->GetPrev()!=NULL){
				user->GetPrev()->SetNext(user->GetNext());
			}
			delete user;
			return true;
		}
		user = user->GetNext();
	}
	return false;
}



void UserNetwork::SaveInFile(){

}

void UserNetwork::ReadFromFile(string filename){

}







