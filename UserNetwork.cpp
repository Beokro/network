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

string UserNetwork::print() {
	Node<User> *temp = users->GetHead();
	string result = "";
	while (temp != NULL) {
		result += temp->GetData().Print();
		result += "\n";
		temp = temp->GetNext();
	}
	return result;
}

void UserNetwork::SaveInFile(string fileName){
	std::ofstream myfile(fileName);
	myfile << print();
	myfile.close();
}

string GetNextWord(string &contents, int &index) {
	int size = contents.size();
	if (index >= size) return "";
	string temp = "";
	while ((contents[index] == ' ' || contents[index] == '\n') && index < (size - 1))
		index++;
	for (index; index < size; index++) {
		if (contents[index] != ' '&& contents[index] != '\n')
			temp += contents[index];
		else break;
	}
	return temp;
}



void UserNetwork::ReadFromFile(string filename){
	std::ifstream myfile(filename);
	string input ="";
	string temp = "";
	if (myfile.is_open()) {
		while (!myfile.eof()) {
			getline(myfile,temp);
			input += temp;
			input += "\n";
		}
	}
	if (input == "")
		return;

	int size = input.size();

	string userName = "";
	string birthday = "";
	string password = "";

	string author;
	string date;
	string contents;

	User  * u = new User("stub", "stub", "stub");

	input = " " + input;
	for (int i = 0; i < size; i++) {
		if (GetNextWord(input, i) == "User:") {
			userName = GetNextWord(input, i);
			GetNextWord(input, i);
			birthday = GetNextWord(input, i);
			GetNextWord(input, i);
			password = GetNextWord(input, i);
			GetNextWord(input, i);
			author = GetNextWord(input, i);

			
		}
		else if (GetNextWord(input, i) == "Author") {
			author = GetNextWord(input, i);
			GetNextWord(input, i);
			date = GetNextWord(input, i);
			GetNextWord(input, i);
			password = GetNextWord(input, i);
		}
	}
	std::cout<<"username is "<< author << std::endl;


}








