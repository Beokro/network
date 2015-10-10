#include "UserNetwork.h"


UserNetwork::~UserNetwork(){
	delete users;
}


bool UserNetwork::AddUser(string userName, string password, string birthday){
	Node<User>* user = users->GetHead();
	while(user!=NULL){
		if(user->GetData().GetUserName()==userName)
			return false;
		user = user->GetNext();
	}
	this->users->AppendElement(User(userName, password, birthday));
	return true;
}


bool UserNetwork::AddUser(User user){
	Node<User>* u = users->GetHead();
		while(u != NULL){
			if(u->GetData().GetUserName()==user.GetUserName())
				return false;
			u=u->GetNext();
	}
	this->users->AppendElement(user);
	return true;
}


bool UserNetwork::RemoveUser(string userName){
	std::cout << "I got into the remove function\n";
	Node<User>* user = users->GetHead();
	while(user!=NULL){
		std::cout<<"In remove ths username is " << user->GetData().GetUserName() << std::endl;
		if(user->GetData().GetUserName() == userName){
			if (user->GetPrev() != NULL) {
				std::cout << "The prev is not NULL\n";
				user->GetPrev()->SetNext(user->GetNext());
			}
			else
				users->SetHead(user->GetNext());
			delete user;
			return true;
		}
		user = user->GetNext();
	}
	return false;
}

int UserNetwork::NumberOfUser() {
	if (users == NULL)return 0;
	Node<User>* u = users->GetHead();
	int count = 0;
	while (u != NULL) {
		count++;
		u = u->GetNext();
	}
	return count;
}

void UserNetwork::SaveInFile(){
	
}

void UserNetwork::ReadFromFile(string filename){

}







