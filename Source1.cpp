#include<iostream>
#include "DLinkList.h"
#include "WallPost.h"
#include "Wall.h"
using namespace std;

int main(){
	DLinkedList<int> *test = new DLinkedList<int>(5);
	Node<int> * temp = new Node<int>(5);
	test->AppendElement(6);
	test->RemoveElement(5);
	cout<<test->GetHead()->GetData()<<endl;
	
	WallPost wp("hello","05/13/2015","Jack");
	WallPost wp2("hello2", "05/13/2015", "Jackkk");
	cout<<wp.Print();

	Wall u("Jack");
	u.addPost(wp);
	u.addPost(wp2);
	u.removePost(wp.GetUserName(),wp.GetTime(),wp.GetContents());
	cout << u.Print() << endl;
	cout << "I left" << endl;
	return 0;
}