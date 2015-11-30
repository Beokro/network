#include "Wall.h"
#include<iostream>
using namespace std;

Wall::Wall(string u, vector<WallPost> p) {
	this->user == u;
	for (WallPost w : p) {
		this->posts.push_back(w);
	}
}


void Wall::addPost(WallPost post){
	this->posts.push_back(post);
}


bool Wall::removePost(string author, string date, string &contents){
	WallPost temp(contents, date, author);
	int size = posts.size();
	for (int i = 0; i < size; i++) {
		if (posts[i] == temp) {
			posts.erase(posts.begin() + i);
			return true;
		}
	}
	return false;
}


string Wall::getUser(){
	return this->user;
}



void Wall::updateUser(string userName){
	this->user =userName;
}



string Wall::Print(){
	string result="";
	vector<WallPost>::iterator it = posts.begin();
	vector<WallPost>::iterator end = posts.end();
	while(it!=end){
		result += it->Print();
		result += "\n";
		it++;
	}
	return result;
}

string Wall::PrintForSave() {
	string result = "";
	vector<WallPost>::iterator it = posts.begin();
	vector<WallPost>::iterator end = posts.end();
	while (it != end) {
		result += it->PrintForSave();
		result += "\n";
		it++;
	}
	return result;
}

//need to be fix
bool Wall::ReadWall(string givenWall){
  givenWall = "THis function had been implement in UserNetWork.cpp";
  // posts = new Wall(givenWall);
  return true;
}

Wall::~Wall(){
}

Wall Wall::operator= (const Wall& w) {
	posts.clear();
	vector<WallPost>::const_iterator it = w.posts.begin();
	vector<WallPost>::const_iterator ed = w.posts.end();
	while (it != ed) {
		this->addPost(*it);
		it++;
	}
	return *this;
}

Wall::Wall(const Wall& w) {
	this->user = w.user;
	vector<WallPost>::const_iterator it = w.posts.begin();
	vector<WallPost>::const_iterator ed = w.posts.end();
	while (it != ed) {
		this->posts.push_back(*it);
		it++;
	}
}

int Wall::FindIndexOfPost(string author, string date, string contents) {
	//cout << "THe contents you enter is  " << contents << endl;
	int size = posts.size();
	string tempContents = "";
	bool partialCorrect = false;
	for (int i = 0; i < size; i++) {
		//cout << "what I have in posts are " << posts[i].GetUserName() << endl;
		//cout << "What you enter is " << author << endl;
		//cout << "WHat I have in date is " << posts[i].GetTime()<<endl;
		//cout << "WHat you enter is " << date << endl<<endl;
		if (posts[i].GetUserName() == author&& posts[i].GetTime() == date) {
			partialCorrect = true;
			tempContents = posts[i].GetContents();
			//cout << "Looking at contents" <<contents<< endl;
			//cout << "Actual contents are " << posts[i].GetContents() << endl;
			for (int j = 0; j < contents.size(); j++) {
				if (contents[j] != tempContents[j]) {
					partialCorrect = false;
					break;
				}
			}
		}
		if(partialCorrect)
			return i;
	}
	//cout << "I am going to return -1\n";
	return -1;
	
}

void Wall::RemovePostAtindex(int index) {
	posts.erase(posts.begin() + index);
}

bool Wall::AddResponse(string name, string contents, string author, string time, string partial, string commentTime) {
	int index = FindIndexOfPost(author, time, partial);
	if (index == -1) {
		cout << "post does not exist\n";
		return false;
	}
	if (index >= posts.size()) {
		cout << "Index out of Range\n";
		return false;
	}
	 posts[index].AddResponse(name, commentTime, contents);
	 return true;
}

bool Wall::RemoveResponseAtIndex(int index, string author, string partial) {
	return posts[index].RemoveResponse(author, partial);
}