#include<iostream>
#include "UserNetwork.h"
using namespace std;


int main(){
	DLinkedList<int> *test = new DLinkedList<int>(5);
	Node<int> * temp = new Node<int>(5);
	test->AppendElement(6);
	test->RemoveElement(5);
	//cout<<test->GetHead()->GetData()<<endl;

	string longstring = "i am not saying you are stupid, it will be a long string, but I really don;t know hat can I write here, so you know";
	
	WallPost wp(longstring,"05/13/2015","Jack");
	WallPost wp2(longstring, "05/13/2015", "Jackkk");
	//cout<<wp.Print()<<endl<<endl;


	User testUser("JJACK", "q503748283", "08/13/1996");
	testUser.AddPost(wp);
	testUser.AddPost(wp2);
	//cout<<testUser.Print();
	User testUser2("JJACK2", "q503748283", "08/13/1996");
	
	cout << "ht" << endl;
	UserNetwork * testnetWork = new UserNetwork();
	testnetWork->AddUser(testUser);
	testnetWork->AddUser(testUser2);

	testnetWork->SaveInFile("NetworkData.txt");

	cout << testnetWork->print() << endl;

	testnetWork->ReadFromFile("NetworkData.txt");


	/*cout << "After add, there are "<<testnetWork->NumberOfUser() << endl;
	if(testnetWork->RemoveUser(testUser.GetUserName())) cout<<"remove success\n";
	else cout << "remove failed\n";
	cout << "After remove, there are " << testnetWork->NumberOfUser() << endl;
	cout<<testnetWork->print();
	cout << "reach here";

	fstream myfile;
	myfile.open("NetworkData.txt");
	myfile << "hi";
	myfile.write("hhhh",5);
	myfile.close();*/
	return 0;
}

