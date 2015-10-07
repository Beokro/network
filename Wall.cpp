#include "Wall.h"


void Wall::addPost(WallPost post){
	this->posts->AppendElement(post);
}


bool Wall::removePost(string author, string date, string contents){
	for(WallPost post :posts){
		if(post.userName == author && post.timePosted == data && post.contents == contents){
			post.GetPrev().SetNext(post.GetNext());
			delete post;
			return true;
		}
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
	for(WallPost post : this->posts){
		result+=post.Print();
		result+="\n";
	}
	return result;
}

//need to be fix
bool Wall::ReadWall(string givenWall){
	return true;
}

Wall::~DLinkList(){
	delete posts;
}







