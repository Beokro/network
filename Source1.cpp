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
	User testUser2("JJACK2", "q503748283", "08/13/1996");
	
	cout << "ht" << endl;
	UserNetwork * testnetWork = new UserNetwork();
	if(testnetWork->AddUser(testUser)) cout<<"Add Success\n";
	testnetWork->AddUser(testUser2);
	cout << "After add, there are "<<testnetWork->NumberOfUser() << endl;
	if(testnetWork->RemoveUser(testUser.GetUserName())) cout<<"remove success\n";
	else cout << "remove failed\n";
	cout << "After remove, there are " << testnetWork->NumberOfUser() << endl;
	cout<<testnetWork->print();
	cout << "reach here";
	
	return 0;
}