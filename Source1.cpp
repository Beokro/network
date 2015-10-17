#include<iostream>
#include "UserNetwork.h"

using std::cin;
using std::cout;
using std::endl;


int main(){


	
	UserNetwork * netWork = new UserNetwork();
	string command="";
	string userName = "", password = "", birthsday = "";
	User * currentUser = NULL;
	netWork->ReadFromFile("NetworkData.txt");

	cout<<netWork->print(); 

	menu:
	cout << "To create a user, Enter C. To log in, Enter L. To quit, enter q\n";
	cin >> command;
	if (command == "C" || command == "c") {
		cout << "Please Choose your UserName\n";
		cin >> userName;
		while (netWork->CheckUserName(userName)) {
			cout << "UserName has exist, please enter antother one, enter q to quit\n";
			cin >> userName;
			if (userName == "q" || userName == "Q")
				goto exit;
		}
		cout << "Please Enter your Password\n";
		cin >> password;
		cout << "Please Enter your date of Birth in follwing format mm/dd/yyyy\n";
		cin >> birthsday;

		while (birthsday.length() != 10 || birthsday[2] != '/' || birthsday[5] != '/' || !isdigit(birthsday[0]) || !isdigit(birthsday[1])
			|| !isdigit(birthsday[3]) || !isdigit(birthsday[4]) || !isdigit(birthsday[6]) || !isdigit(birthsday[7]) || !isdigit(birthsday[8])
			|| !isdigit(birthsday[9])) {
			cout << "birthday format is wrong, it should be mm/dd/yyyy. Please Enter Again. (Enter Q to quit): \n";
			cin >> birthsday;
		}

		netWork->AddUser(User(userName, password, birthsday));
		cout << "You have succesefully create your account\n";

		cout<<netWork->print();
		goto menu;

	}

	else if (command == "L" || command == "l") {
		cout << "Enter your UserName:\n";
		cin >> userName;
		while (!netWork->CheckUserName(userName)) {
			cout << "UserName is not valid, Please try again.(Enter Q to Exit)\n";
			cin >> userName;
			if ( userName == "Q" || userName == "q")
				goto exit;
		}
		cout << "Enter your password:\n";
		cin >> password;

		currentUser = netWork->GetUser(userName, password);

		if (currentUser == NULL) cout << "incorrect" << endl;

		while (currentUser == NULL) {
			cout << "Password is not correct. Please try again. (Enter Q to Exit, B to beck to MainMenu: )";
			cin >> password;
			if (toupper(password[0]) == 'q' )
				goto exit;
			if (toupper(password[0]) == 'B')
				goto menu;
			currentUser = netWork->GetUser(userName, password);
		}

		cout << "Current user is " << currentUser->GetUserName() << endl;

		currentMenu:
		cout << "To display your Wall, Enter D. Enter Q to quit\n";
		cin >> command;
		while (toupper(command[0]) == 'D'&& toupper(command[0]) == 'Q') {
			cout << "Command invalid. Please try again:\n";
			cin >> command;
		}
		
		if (toupper(command[0]) == 'D') {
			cout << currentUser->Print();
			goto currentMenu;
		}
		if (toupper(command[0]) == 'Q')
			goto exit;
	}

	exit:


	return 0;
}

