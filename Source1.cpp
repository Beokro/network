#include<iostream>
#include "UserNetwork.h"
using namespace std;

int main(){
	DLinkedList<int> *test = new DLinkedList<int>(5);
	Node<int> * temp = new Node<int>(5);
	test->AppendElement(6);
	test->RemoveElement(5);
	cout<<test->GetHead()->GetData()<<endl;
	
	WallPost wp("hello","05/13/2015","Jack");
	WallPost wp2("hello2", "05/13/2015", "Jackkk");
	cout<<wp.Print()<<endl<<endl;


	User testUser("JJACK", "q503748283", "08/13/1996");
	testUser.AddPost(wp);
	testUser.AddPost(wp2);
	cout<<testUser.Print();

	
	cout << "ht" << endl;
	UserNetwork * testnetWork = new UserNetwork();
	testnetWork->AddUser(testUser);
	cout << "reach here";
	//testnetWork->RemoveUser(testUser.GetUserName());
	cout<<testnetWork->print();
	cout << "reach here";
	
	return 0;
}