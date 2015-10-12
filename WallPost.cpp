#include "WallPost.h"

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

WallPost::~WallPost(){
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
	temp+=("Author: "+this->userName+"\n");
	temp+=("Date: "+ this->timePosted+"\n");
	temp+=(formating(contents,40)+"\n");
	return temp;
}

bool operator==(WallPost & lfs, WallPost & rhs) {
	return(lfs.GetUserName() == rhs.GetUserName() && lfs.GetTime() == rhs.GetTime() && lfs.GetContents() == rhs.GetContents());
}