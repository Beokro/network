#include "Wall.h"

void Wall::addPost(WallPost post){
	this->posts->AppendElement(post);
}


bool Wall::removePost(string author, string date, string &contents){
	return posts->RemoveElement(WallPost(contents,date,author));
}


string Wall::getUser(){
	return this->user;
}



void Wall::updateUser(string userName){
	this->user =userName;
}



string Wall::Print(){
	string result="";
	Node<WallPost> * post = posts->GetHead();
	while(post!=NULL){
		result+=post->GetData()->Print();
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

Wall Wall::operator= (const Wall& w) {
	posts = new DLinkedList<WallPost>();
	Node<WallPost> *tempNode = w.posts->GetHead();
	while (tempNode != NULL) {
		this->addPost(*tempNode->GetData());
		tempNode = tempNode->GetNext();
	}
	return *this;
}