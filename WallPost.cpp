#include "WallPost.h"

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
	temp+=("	"+this->contents+"\n");
	return temp;
}

bool operator==(WallPost & lfs, WallPost & rhs) {
	return(lfs.GetUserName() == rhs.GetUserName() && lfs.GetTime() == rhs.GetTime() && lfs.GetContents() == rhs.GetContents());
}