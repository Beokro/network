#include "UserNetwork.h"


UserNetwork::~UserNetwork(){
}


bool UserNetwork::AddUser(string userName, string password, string birthday){
	if (CheckUserName(userName)) {
		return false;
	}

	userMap.insert(pair<string,User*>(userName, new User(userName, password, birthday)));
	return true;
}

bool UserNetwork::CheckUserName(string userName) {
	if (userMap.find(userName) != userMap.end()) {
		return true;
	}
	return false;
}


bool UserNetwork::AddUser(User user){
	if (CheckUserName(user.GetUserName()))
		return false;
	cout << "Adding user " << user.GetUserName() << endl;
	userMap.insert(pair<string, User*>(user.GetUserName(), new User(user)));
	return true;
}


bool UserNetwork::RemoveUser(string userName){
	
	map<string, User*>::iterator it;
	it = userMap.find(userName);
	if (it == userMap.end())
		return false;
	userMap.erase(it);
	return true;
	
}


User* UserNetwork::GetUser(string userName, string password) {
	if (userMap.find(userName) != userMap.end()) {
		User * temp = userMap[userName];
		if (temp->GetPassword() == password)
			return temp;
	}

	return NULL;
}

User* UserNetwork::GetUser(string userName) {
	if (userMap.find(userName) != userMap.end())
		return userMap[userName];

	cout << "User does not exist\n" << endl;
	return NULL;
}


int UserNetwork::NumberOfUser() {
	return userMap.size();
	//return users.size();
}

string UserNetwork::print() {
	map<string, User*>::iterator it = userMap.begin();
	map<string, User*>::iterator ed = userMap.end();
	string result = "";
	while (it != ed) {
		result += it->second->Print();
		result += "\n";
		it++;
	}
	return result;
}

string UserNetwork::PrintForSave() {
	map<string, User*>::iterator it = userMap.begin();
	map<string, User*>::iterator ed = userMap.end();
	string result = "";
	while (it != ed) {
		result += it->second->PrintForSave();
		result += "\n";
		it++;
	}
	return result; 
	/*vector<User>::iterator it = users.begin();
	vector<User>::iterator ed = users.end();
	string result = "";
	while (it != ed) {
		result += it->PrintForSave();
		result += "\n";
		it++;
	}
	return result;*/
}

void UserNetwork::SaveInFile(string fileName){
	std::ofstream myfile(fileName);
	myfile << PrintForSave();
	myfile.close();
}

string GetNextWord(string &contents, int &index) {
	int size = contents.size();
	if (index >= size) return "";
	string temp = "";
	while ((contents[index] == ' ' || contents[index] == '\n') && index < (size - 1))
		index++;
	for (; index < size; index++) {
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
	for (; index < size; index++) {
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

	vector<string> commentName;
	vector<string> commentContents;
	vector<string> commentTime;
	string checkComm;

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
			commentName.clear();
			commentContents.clear();
			author = GetNextWord(input, i);
			GetNextWord(input, i);
			date = GetNextWord(input, i);
			checkComm = GetNextWord(input, i);
			while (checkComm == "~Comment") {
				commentName.push_back(GetNextWord(input, i));
				commentTime.push_back(GetNextWord(input, i));
				commentContents.push_back(GetParagraph(input, i));
				checkComm = GetNextWord(input, i);
			}
			contents = "";
			contents += (checkComm+" ");
			contents += GetParagraph(input, i);

			//std::cout << "author is" <<author<< std::endl;
			u->AddPost(WallPost(contents, date, author,commentName, commentTime,commentContents));

		}

		else if (holder == "Friends:") {
			holder = GetNextWord(input, i);
			while (holder != ".") {
				u->AddFriend(holder);
				holder = GetNextWord(input, i);
			}
			holder = GetNextWord(input, i);
			holder = GetNextWord(input, i);
			while (holder != ".") {
				u->AppendFriendRequest(holder);
				holder = GetNextWord(input, i);
			}

		}
	}
	if (u->GetUserName() != "stub") {
		AddUser(*u);
		//std::cout << this->NumberOfUser() << endl; 
		delete u;
	}

	//cout << "THe size of user is " << users.size();
	AddFriendPointer();
	
}
 
void UserNetwork::SendRequest(string user1, string User2) {
	User*  u = GetUser(User2);
	if (u==NULL) {
		cout << "UserNmae does not exist\n\n";
		return;
	}
	if (u->CheckFriendReq(user1)) {
		return;
	}
	u->AppendFriendRequest(user1);
}

void UserNetwork::ApproveReq(User * u1, int indexOfApp) {
	//apprve the request and get the name at the idnexofAPP
	if (u1 == NULL) {
		cout << "User does not exist";
		return;
	}
	string name2 = u1->ApproveRequest(indexOfApp);

	if (name2 == "IndexOurOfRange") {
		cout << "Index of Approve is incorrect\n\n";
		return;
	}

	//User2 add the user1 as friend becuase user1 approve the request
	//cout << "It is fine before getuser function\n";
	//cout << GetUser(name2)->GetUserName() << endl;
	GetUser(name2)->AddFriend(u1->GetUserName());

}
void UserNetwork::DenyReq(User * u1, int indexOfDen) {


	u1->DenyRequest(indexOfDen);
	
}

string Upper(string s) {
	string result = "";
	for (int i = 0; i < s.length(); i++) {
		result += toupper(s[i]);
	}
	return result;
}

vector<string> UserNetwork::GetMatchName(string partial, string currentName) {
	vector<string> result;
	User * u;
	string name = "";
	map<string, User*>::iterator it = userMap.begin();
	map<string, User*>::iterator ed = userMap.end();
	while (it != ed) {
		u = it->second;
		name = u->GetUserName();
		if (name == currentName)
			continue;
		if (Upper(name).find(Upper(partial)) <= name.length())
			result.push_back(name);
		it++;
	}
	return result;




	/*for (int i = 0; i < length; i++) {
		u = users[i];
		name = u.GetUserName();
		if (name == currentName)
			continue;

		if (Upper(name).find(Upper(partial)) <= name.length())
			result.push_back(name);
	}
	return result;*/
}

int UserNetwork::FindIndexOfPost(string author, string date, string firstWord, User &currentUser) {
	return currentUser.FindIndexOfPost(author, date, firstWord);
}

void UserNetwork::DeleteAllFriendof(string name) {
	map<string, User*>::iterator it = userMap.begin();
	map<string, User*>::iterator ed = userMap.end();
	while (it != ed) {
		it->second->DeleteAllFriendof(name);
		it++;
	}
}

void UserNetwork::DelteFriend(User  *user1, string name2) {
	user1->DeleteFriend(name2);
	User * u2 = GetUser(name2);
	if (u2 == NULL ) {
		cout << "Name is invalid\n\n";
		return;
	}
	u2->DeleteFriend(user1->GetUserName());
}


void UserNetwork::AddFriendPointer() {
	map<string, User*>::iterator it = userMap.begin();
	map<string, User*>::iterator ed = userMap.end();
	vector<string>friends;
	User * u, *u2;
	while (it != ed) {
		cout << "Adding friend for " << it->second->GetUserName() << endl;
		u = it->second;
		friends = u->GetFriendList();
		for (string name : friends) {
			if (CheckUserName(name) ) {
				u2 = userMap[name];
				if (u->CheckFriendPointer(u2->GetUserName()))
					continue;
				u->AddFriendPointer(u2);
				u2->AddFriendPointer(u);
			}
		}
		it++;
	}


	
}


int UserNetwork::FindDegreeOfSeparation(User * u,string name, list<string> &sPath) {
	 sPath = shortestPath(u,name, sPath);
	 if (sPath.size() == 0)
		 cout << "There is no path between you and " << name << endl;
	 return sPath.size();
}

list <string> UserNetwork::shortestPath(User * u, string name, list<string> &shortestPath) {
	list<string> path;
	vector<User *> friendPointerList;
	bool found = false;
	AllVistedToFalse();
	list<User*> blist;
	blist.push_back(u);
	User * holder = NULL;
	User * targetUser = NULL;
	while (blist.size() != 0) {
		holder = blist.front();
		blist.pop_front();
		if (holder->GetUserName() == name) {
			targetUser = holder;
			break;
		}
		friendPointerList = holder->GetFriendPointerList();
		for (User *v : friendPointerList) {
			if (v->CheckVisted())
				continue;
			v->SetParent(holder);
			v->SetVistedTrue();
			blist.push_back(v);
		}
		
	}
	

	if (targetUser != NULL) {
		while (targetUser != u) {
			path.push_front(targetUser->GetUserName());
			targetUser = targetUser->GetParent();
		}
	}


	return path;
}

vector<string> UserNetwork::AllUserInNDegreeAway(User* u, int n) {
	vector<string> freindNAway;
	vector<User *> friendPointerList;
	list<int> friendDegree;
	AllVistedToFalse();
	list<User*> blist;
	blist.push_back(u);
	friendDegree.push_back(0);
	User * holder = NULL;
	int currentDegree = 0;
	u->SetVistedTrue();
	while (blist.size() != 0) {
		holder = blist.front();
		currentDegree = friendDegree.front();
		blist.pop_front();
		friendDegree.pop_front();
		if (currentDegree == n) {
			freindNAway.push_back(holder->GetUserName());
			continue;
		}
		friendPointerList = holder->GetFriendPointerList();
		for (User *v : friendPointerList) {
			if (v->CheckVisted())
				continue;
			v->SetParent(holder);
			v->SetVistedTrue();
			blist.push_back(v);
			friendDegree.push_back(currentDegree + 1);
		}

	}


	return freindNAway;
}

/*void UserNetwork::ForceBecomeFriend(int index1, int index2) {
	string name1 = users[index1].GetUserName();
	string name2 = users[index2].GetUserName();
	if(!users[index1].CheckFriendShip(name2))
		users[index1].ForceToAddFriend(name2);
	if (!users[index2].CheckFriendShip(name1))
		users[index2].ForceToAddFriend(name1);
}

bool UserNetwork::CheckFriendAtIndex(int index1, int index2) {
	return users[index1].CheckFriendShip(users[index2].GetUserName());
}

*/





