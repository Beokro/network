#include "Wall.h"
#include "User.h"
#include<iostream>
#include<string>
#include "UserNetwork.h"
using namespace std;

int main() {
	/*cout << "Fcuntion is running" << endl;

	List<int> * test = new List<int>();
	test->AppendElement(5);
	test->AppendElement(6);
	test->AppendElement(7);
	test->AppendElement(8);
	test->AppendElement(9);
	cout << "after appending, the length of list is " << test->GetLength() << endl;

	List<int>::Iterator it(*test, 0);
	++it;
	cout << "using * operation " << *it << endl;
	cout << "value of the begin is " << *test->begin() << endl;
	cout << "vaue of the end is " << *test->end() << endl;*/


	Wall * sampleWall = new Wall("JACk");
	sampleWall->addPost(WallPost("it is a test", "now", "JJACK"));
	sampleWall->addPost(WallPost("it is a test", "now", "JJACKa"));
	string temp = "it is a test";
	//sampleWall->removePost("JJACK", "now", temp);
	//cout << "It is Ok Until Here" << endl;
	cout <<"AFter adding one the length of the posts is"<< sampleWall->GetPosts()->GetLength() << endl;
	cout << sampleWall->Print() << endl;

	User * tempuser = new User("xujia", "qq503748283", "08/13/1996");
	string username = "JJACK";
	tempuser->AddPost(WallPost("it is a test", "now", "JJACKa"));
	cout << tempuser->Print() << endl;

	UserNetwork * network = new UserNetwork();
	network->AddUser(*tempuser);
	cout << network->NumberOfUser() << endl;
	cout << "ALL of the user inside network" << endl;
	cout<<network->print();


}