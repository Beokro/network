#include "WallPost.h"
#include<iostream>

string formating(string origin, int number) {
	int count = 0, index = 0, size = origin.size();
	string formatted = "";
	while (index < size) {
		if (count < (number - 1)) {
			if (count == 0 && origin[index] == ' ') {
				index++;
				continue;
			}
				
			formatted += origin[index];
			count++;
			index++;
		}
		else {
			if (origin[index - 1] != ' '&&origin[index] != ' '&&index < (size - 1) && origin[index + 1] != ' ') {
				formatted += "-";
			}
			else if (origin[index - 1] != ' '&&origin[index] == ' ') {
				formatted += " ";
			}
			else {
				formatted += origin[index++];
			}
			formatted += "\n";
			count = 0;
		}

	}
	return formatted;
}



WallPost::WallPost(string contents, string timePosted, string userName){
	this->contents = contents;
	this->timePosted = timePosted;
	this->userName = userName;
}

WallPost::WallPost(string contents, string timePosted, string userName, vector<string> commentName, vector<string> commentTime, vector<string> commentResponse) {
	int size = commentName.size();
	this->contents = contents;
	this->timePosted = timePosted;
	this->userName = userName;
	if (size != commentResponse.size()) {
		std::cout << "Comment Name and Response's number is different";
		return;
	}
	if (size == 0) return;
	for (int i = 0; i < size; i++) {
		this->responses.push_back(Response(commentName[i],  commentTime[i], commentResponse[i]));
	}
}

WallPost::~WallPost(){
	//std::cout << "I get in delete WallPost" << std::endl;
	return;
}

void WallPost::updateTime(string time){
	this->timePosted = time;
}



void WallPost::updateContents(string newContents){
	this->contents = newContents;
}

void WallPost::changeUserName(string newUserName){
	this->userName = newUserName;
}

string WallPost::Print(){
	string temp = "";
	int size = responses.size();
	temp+=("Author: "+this->userName+"\n");
	temp+=("Date: "+ this->timePosted+"\n");
	temp+=(formating(contents,40)+"\n");
	if (size != 0) {
		temp += "Comments:\n";
		for (int i = 0; i < size; i++) {
			//temp += responses[i].name + ": \n";
			temp += (formating(responses[i].time +" "+responses[i].name + ": "+responses[i].contents, 40) + "\n");
		}
	}
	return temp;
}

string WallPost::PrintForSave() {
	string temp = "";
	int size = responses.size();
	temp += ("Author: " + this->userName + "\n");
	temp += ("Date: " + this->timePosted + "\n");
	if (size != 0) {
		for (int i = 0; i < size; i++) {
			temp += "~Comment ";
			temp += (responses[i].name + " ");
			temp += (responses[i].time+"\n");
			temp+=(formating(responses[i].contents, 40) + "\n\n");
		}
	}
	temp += (formating(contents, 40) + "\n");
	return temp;
}

bool operator==(const WallPost & lfs, const WallPost & rhs) {
	return(lfs.GetUserName() == rhs.GetUserName() && lfs.GetTime() == rhs.GetTime() && lfs.GetContents() == rhs.GetContents());
}


void WallPost::AddResponse(string name, string time, string response) {
	responses.push_back(Response(name, time,response));
}

bool WallPost::RemoveResponse(string author,  string partial) {
	//std::cout << "Partial I get is " << partial << std::endl << std::endl;
	//std::cout << "author I get is " << author << std::endl << std::endl;
	int size = responses.size();
	bool correct = true;
	for (int i = 0; i < size; i++) {
		//std::cout << "Author I have is " << responses[i].name << std::endl << std::endl;
		if (responses[i].name == author) {
			//std::cout << "True I have is " << responses[i].contents << std::endl << std::endl;
			if (partial.size() > responses[i].contents.size())
				continue;
			for (int j = 0; j < partial.size(); j++) {
				if (partial[j] != responses[i].contents[j]) {
					correct = false;
					break;
				}
			}
			if (correct) {
				responses.erase(responses.begin() + i);
				return true;
			}
			correct = true;
		}
	}
	return false;
}