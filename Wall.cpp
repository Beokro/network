#include "Wall.h"

void Wall::addPost(WallPost post){
	this->posts->AppendElement(post);
}


bool Wall::removePost(string author, string date, string contents){
	DLinkedList<WallPost> * post = posts;
	while(post!=NULL){
		if(post->GetData().GetUserName == author && post->GetData().GetTime() == date && post->GetData().GetContents() == contents){
			post->GetPrev()->SetNext(post->GetNext());
			delete post;
			return true;
		}
		post = post->GetNext();
	}
	return false;
}


string Wall::getUser(){
	return this->user;
}



string Wall::updateUser(string userName){
	this->user =userName;
}



string Wall::Print(){
	string result="";
	DLinkedList<WallPost> * post = posts;
	while(post!=NULL){
		result+=post->GetData().Print();
		result+="\n";
		post = post->GetNext();
	}
	return result;
}

//need to be fix
bool Wall::ReadWall(string givenWall){
	return true;
}

Wall::~Wall(){
	delete posts;
}







