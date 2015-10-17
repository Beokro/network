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

bool UserNetwork::CheckUserName(string userName) {
	Node<User>* u = users->GetHead();
	while (u != NULL) {
		if (u->GetData().GetUserName() == userName)
			return true;
		u = u->GetNext();
	}
	return false;
}

bool UserNetwork::AddUser(User user){
	if (CheckUserName(user.GetUserName()))
		return false;
	this->users->AppendElement(user);
	return true;
}


bool UserNetwork::RemoveUser(string userName){
	Node<User>* user = users->GetHead();
	while(user!=NULL){
		if(user->GetData().GetUserName() == userName){
			if (user->GetPrev() != NULL) {
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


User* UserNetwork::GetUser(string userName, string password) {
	Node<User>* u = users->GetHead();
	while (u != NULL) {
		if (u->GetData().GetUserName() == userName && u->GetData().CheckPassword(password))
			return &u->GetData();
		u = u->GetNext();
	}
	return NULL;
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

string GetParagraph(string & contents, int &index) {
	int size = contents.size();
	if (index >= size) return "";
	string temp = "";
	while ((contents[index] == '\n'|| contents[index] == ' ') && index < (size - 1))
		index++;
	for (index; index < size; index++) {
		if (contents[index] == '\n') {
			if (++index < size) {
				if (contents[index] == '\n')
					break;
				else if (contents[index - 2] != ' '&&contents[index] != ' ')
					temp += ' ';
			}
			else break;

		}
		if (contents[index] != ' ') {
			if (contents[index] == '-'&&(index+1)<size&&contents[index + 1] == '\n')
				continue;
			temp += contents[index];
		}

		else temp += ' ';
		
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

	string holder = "";

	User  * u = new User("stub", "stub", "stub");

	input = " " + input;
	for (int i = 0; i < size; i++) {
		//std::cout << "index =" <<i<<std::endl;
		holder = GetNextWord(input, i);
		if (holder == "User:") {
			//std::cout << "I get in here" << std::endl;
			userName = GetNextWord(input, i);
			GetNextWord(input, i);
			birthday = GetNextWord(input, i);
			GetNextWord(input, i);
			password = GetNextWord(input, i);
			if (u->GetUserName()!= "stub") {
				AddUser(*u);
			}
				delete u;
				u = new User(userName, password, birthday);
			
		}
		else if (holder == "Author:") {
			//std::cout << "I get in author" << std::endl;
			author = GetNextWord(input, i);
			GetNextWord(input, i);
			date = GetNextWord(input, i);
			contents = GetParagraph(input, i);

			//std::cout << "author is" <<author<< std::endl;
			u->AddPost(WallPost(contents, date, author));

		}
	}
	if (u->GetUserName() != "stub") {
		AddUser(*u);
	}


}









