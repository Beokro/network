#include<iostream>
#include<time.h>
#include "UserNetwork.h"

using std::cin;
using std::cout;
using std::endl;


int main(){


	cout << "Initalizing the program.....\n";
	UserNetwork  netWork ;
	string command="";
	string userName = "", password = "", birthsday = "";
	string author = "", time = "", contents = "";
	string response = "";
	char timec[9];
	string  tempname = "";
	User * tempUser = NULL;
	User  *currentUser = NULL;
	netWork.ReadFromFile("NetworkData.txt");
	list<string>shortestpath;
	vector<string>FriendNAway;
	cout << "Size of this network is" << netWork.NumberOfUser() << endl;

	menu:
	cout << "1.To create a user, Enter C.\n2.To log in, Enter L.\n3.To Log Out, enter q\n";
	cin >> command;

	//User want to create a account
	if (command == "C" || command == "c") {
		cout << "Please Choose your UserName\n";
		cin >> userName;
		while (netWork.CheckUserName(userName)) {
			cout << "UserName has exist, please enter antother one, enter q to Log Out\n";
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
			cout << "birthday format is wrong, it should be mm/dd/yyyy. Please Enter Again. \n(Enter Q to Log Out, B to main menu): \n";
			cin >> birthsday;
			if (birthsday == "Q" || birthsday == "q")
				goto exit;
			if (birthsday == "B" || birthsday == "b")
				goto menu;
		}

		netWork.AddUser(User(userName, password, birthsday));
		cout << "You have succesefully create your account\n";
		netWork.SaveInFile("NetworkData.txt");

		cout<<netWork.print();
		goto menu;

	}








	//User want to log in
	else if (command == "L" || command == "l") {
		cout << "Enter your UserName:\n";
		cin >> userName;
		while (!netWork.CheckUserName(userName)) {
			cout << "UserName is not valid, Please try again.(Enter Q to Log Out)\n";
			cin >> userName;
			if ( userName == "Q" || userName == "q")
				goto exit;
		}
		cout << "Enter your password:\n";
		cin >> password;

		currentUser = netWork.GetUser(userName, password);

		if (currentUser==NULL) cout << "incorrect" << endl;

		while (currentUser==NULL) {
			cout << "Password is not correct. Please try again. (Enter Q to Log Out, B to beck to MainMenu: )";
			cin >> password;
			if (toupper(password[0]) == 'q' )
				goto exit;
			if (toupper(password[0]) == 'B')
				goto menu;
			currentUser = netWork.GetUser(userName, password);
		}

		cout << "\nCurrent user is " << currentUser->GetUserName() << endl;
		cout << currentUser->PrintFriendReq() << endl;

		currentMenu:
		cout << "1.To display your Wall, Enter D.\n2.To add a Wallpost to your wall, Enter A.\n3.To search for friends, Enter S  \n4.To Add Friend, Enter F\n";
		cout << "5.To display your friends, Enter W\n6.To Approve or Deny the friend Requests, Enter O \n7.To Delete a friend, Enter G\n8.To delte your account, Enter U";
		cout << "\n9.To Delete a post, Enter P\n10.To change password, Enter X\n11.To change birthsday, Enter Y\n12.To add a post at friend's wall, Enter M\n";
		cout << "13.To delete your post on your friends wall, Enter H\n14.To add a response on your or your friend's wall, Enter N\n15.To display you friend's wall, Enter I\n";
		cout << "16.To delete a response in your or you friend's Wall, Enter R\n17.To find out the degree of separation between you and another User, Enter E\n";
		cout << "18.To Find out the friend at N Degree away, Enter V\n";
		cout << "Enter Q to Log Out\n";
		cin >> command;
		while (toupper(command[0]) != 'D'&& toupper(command[0]) != 'Q'&&toupper(command[0])!='A'&&toupper(command[0]) != 'F'&&toupper(command[0]) != 'S'&&toupper(command[0]) != 'W'&&toupper(command[0]) != 'O'&&toupper(command[0]) != 'P'&&toupper(command[0]) != 'U'&&toupper(command[0]) != 'G'&&toupper(command[0]) != 'X'&&toupper(command[0]) != 'Y'&&toupper(command[0]) != 'M'&&toupper(command[0]) != 'H'&&toupper(command[0]) != 'N'&&toupper(command[0]) != 'I'&&toupper(command[0]) != 'R'&&toupper(command[0]) != 'E'&&toupper(command[0]) != 'V') {
			cout << "Command invalid. Please try again:\n";
			cin >> command;
		}
		
		 if (toupper(command[0]) == 'D') {
			cout << currentUser->PrintPost();
			goto currentMenu;
		}
		 if (toupper(command[0]) == 'X') {
			 cout << "Please enter your password here\n";
			 cin >> password;
			 currentUser->UpdatePassword(password);
			 goto currentMenu;
		 }

		 if (toupper(command[0]) == 'Y') {
			 cout << "Please Enter your date of Birth in follwing format mm/dd/yyyy\n";
			 cin >> birthsday;

			 while (birthsday.length() != 10 || birthsday[2] != '/' || birthsday[5] != '/' || !isdigit(birthsday[0]) || !isdigit(birthsday[1])
				 || !isdigit(birthsday[3]) || !isdigit(birthsday[4]) || !isdigit(birthsday[6]) || !isdigit(birthsday[7]) || !isdigit(birthsday[8])
				 || !isdigit(birthsday[9])) {
				 cout << "birthday format is wrong, it should be mm/dd/yyyy. Please Enter Again. \n(Enter Q to Log Out, B to main menu): \n";
				 cin >> birthsday;
				 if (birthsday == "Q" || birthsday == "q")
					 goto exit;
				 if (birthsday == "B" || birthsday == "b")
					 goto currentMenu;
			 }
			 currentUser->UpdateBirthday(birthsday);
			 goto currentMenu;
		 }

		 if (toupper(command[0]) == 'W') {
			 cout << currentUser->PrintFriendsAsList();
			 cout << endl;
			 goto currentMenu;
		 }

		 if (toupper(command[0]) == 'M') {
			 string friendName = "";
			 cout << "Enter the name of your friend" << endl;
			 cin >> friendName;

			 while (!currentUser->CheckFriendShip(friendName)) {
				 cout << friendName + " is not your friend. Please enter the Name again: (Enter B to back to Main Menu)\n";
				 cin >> friendName;
				 if (friendName == "B" || friendName == "b")
					 goto currentMenu;
			 }
			 cout << "Enter the Current Date as mm/dd/yy";
			 cin >> time;
			 cin.ignore();
			 cout << "Enter the contents of post below\n";
			 getline(cin, contents);
			 tempUser = netWork.GetUser(friendName);

			 if (tempUser== NULL) {
				 cout << "Your friend is not exist in the network\n";
				 goto currentMenu;
			 }
			 if (!tempUser->CheckFriendShip(currentUser->GetUserName())) {
				 cout << "You do not exist on your friend's friend list" << endl;
				 goto currentMenu;
			 }
			 tempUser->AddPost(WallPost(contents, time, currentUser->GetUserName()));
			 cout << "You have successfully post on your friend's wall\n";
			 netWork.SaveInFile("NetworkData.txt");
			 goto currentMenu;
			 
		 }

		 if (toupper(command[0]) == 'P') {
			 string author = "";
			 string date = "";
			 string contents = "";
			 cout << "Enter the name of the author" << endl;
			 cin >> author;
			 cout << "Enter the date you created this post" << endl;
			 cin >> date;
			 cin.ignore();
			 cout << "Enter first couple words of the post you want to delete\n";
			 getline(cin, contents);
			 int index = netWork.FindIndexOfPost(author, date, contents,*currentUser);
			 if (index == -1) {
				 cout << "The post does not exist, plese check what you have enter\n";
				 goto currentMenu;
			 }
			 else {
				 currentUser->RemovePostAtIndex(index);
				 cout << "You have succesfully delete the post\n\n";
			 }
			 goto currentMenu;

		 }

		 if (toupper(command[0]) == 'A') {
			author = currentUser->GetUserName();
			cout << "Enter the Current Date as mm/dd/yy";
			cin >> time;
			cin.ignore();
			cout << "Enter your contents here: \n";
			getline(cin, contents);
			currentUser->AddPost(WallPost(contents, time, author));
			cout << "Your Post has been added to the wall\n";
			netWork.SaveInFile("NetworkData.txt");
			goto currentMenu;
		}
		 if (toupper(command[0]) == 'I') {
			 cout << "Enter your friend's name\n";
			 cin >> tempname;
			 while (!currentUser->CheckFriendShip(tempname)) {
				 cout << "You are not friend of " << tempname << endl;
				 cout << "Please enter the correct friend name\n";
				 cin >> tempname;
			 }
			 tempUser= netWork.GetUser(tempname);

			 if (tempUser == NULL) {
				 cout << "Your friend does not exist in the network\n\n";
				 goto currentMenu;
			 }
			 cout << tempUser->PrintPost() << endl;
			 goto currentMenu;
		 }

		if (toupper(command[0]) == 'S') {
			string partial = "";
			cout << "Please enter a partial string of names to begin search\n";
			cin >> partial;
			//get the list of the match names
			vector<string>Match =netWork.GetMatchName(partial,currentUser->GetUserName());
			if (Match.size() == 0) {
				cout << "There aren't any result found\n";
			}
			else {
				int index = 0;
				cout << "Following is the list of names that mathch your input\n";
				for (string name : Match) {
					cout << index << ".";
					cout << name << endl;
					index++;
				}
				cout << endl;
			}
			goto currentMenu;
		}

		if (toupper(command[0]) == 'F') {
			cout << "Enter the exact name of the name of the user that you want to add. (You can use search to get the exact name)\n";
			string name2 = "";
			cin >> name2;
			if (netWork.GetUser(name2)==NULL) {
				cout << "This User does not exist, Please Enter the name again. (Enter Q to exist, B to back to main menu)";
				cin >> name2;
				if (name2 == "Q" || name2 == "q")
					goto exit;
				if (name2 == "B" || name2 == "b")
					goto currentMenu;
			}
			if (name2 == currentUser->GetUserName()) {
				cout << "You can not add yourself as a friend\n\n";
				goto currentMenu;
			}
			netWork.SendRequest(currentUser->GetUserName(), name2);
			cout << "Request sent" << endl;
			netWork.SaveInFile("NetworkData.txt");
			goto currentMenu;
		}

		if (toupper(command[0]) == 'O') {
			cout << endl;
			cout << "To Approve friend Request, Enter 1. To Delete Friend Request, Enter 0";
			cin >> command;
			while (command != "1"&&command != "0") {
				cout << "Commnad invalid, Enter 1 to apprive, 0 to delete. B to main menu";
				if (command == "B" || command == "b")
					goto currentMenu;
			}
			if (command == "1") {
				int indexOfApp = 0;
				cout << "Plase Ente the index of the friendReq you want to add\n";
				cin >> indexOfApp;
				netWork.ApproveReq(currentUser, indexOfApp);
				cout << "You have approved this request" << endl;
			}
			else if (command == "0") {
				int indexOfDen = 0;
				cout << "Plase Ente the index of the friendReq you want to delete\n";
				cin >> indexOfDen;
				netWork.DenyReq(currentUser, indexOfDen);
			}
			netWork.SaveInFile("NetworkData.txt");
			cout << endl;
			goto currentMenu;
		}

		if (toupper(command[0]) == 'U') {
			cout << "Are you sure you want to delete the whole account?\n";
			cout << "Enter yes to confirm your choice, Enter anythingelse to back to main menu\n";
			cin >> command;
			if (command != "yes"&&command != "YES" && command != "Yes")
				goto currentMenu;
			else {
				netWork.DeleteAllFriendof(currentUser->GetUserName());
				netWork.RemoveUser(currentUser->GetUserName());
			}
			goto exit;
		}
		if (toupper(command[0]) == 'G'){
			cout << "Enter the name of the friend you want to delete\n";
			string name2 = "";
			cin >> name2;
			netWork.DelteFriend(currentUser, name2);
			goto currentMenu;
		}

		if (toupper(command[0]) == 'H') {
			cout << "Enter the name of your friend\n";
			cin >> tempname;

			tempUser = netWork.GetUser(tempname);
			
			while (tempUser == NULL) {
				cout << "The name your enter does not correnspond to anyone in the network. Please enter the name again (Enter Q to back to main menu)\n";
				cin >> tempname;
				if (tempname == "B" || tempname == "b")
					goto currentMenu;
				tempUser = netWork.GetUser(tempname);
			}
			if (tempname == currentUser->GetUserName()) {
				cout << "You shouldn't enter your own name, if you want to delete a post in your own wall, You can choose it from main menu.\n\n";
				goto currentMenu;
			}
			cout << "Enter the date you created this post" << endl;
			cin >> time;
			cin.ignore();
			cout << "Enter first couple words of the post you want to delete\n";
			getline(cin,contents);
			int index = netWork.FindIndexOfPost(currentUser->GetUserName(), time, contents, *tempUser);
			if (index == -1) {
				cout << "The post does not exist, plese check what you have enter\n";
				goto currentMenu;
			}
			else {
				cout << "Index is " << index << endl;
				tempUser->RemovePostAtIndex(index);
				cout << "You have succesfully delete the post\n\n";
			}
			goto currentMenu;

		}

		if (toupper(command[0]) == 'N') {
			tempname = "";
			cout << "Enter 0 to Add Response on your own Wall, Enter 1 to Add Response on your friends' Wall\n";
			cin >> command;
			while (command != "0"&&command != "1") {
				cout << "Invalid Command. Enter 0 to Add Post on your own Wall, Enter 1 to Add Post on your friends' Wall\nEnter B to back to Main Menu\n";
				cin >> command;
				if (command == "B" || command == "b") {
					goto currentMenu;
				}
			}
			if (command == "0")
				tempname = currentUser->GetUserName();
			else {
				cout << "Enter the name of your friend";
				cin >> tempname;
				while (!currentUser->CheckFriendShip(tempname)) {
					cout << "You are not freind with " << tempname << ". Please enter the name of your again. Enter B to back to Main Menu\n";

					cin >> tempname;
					if (tempname == "B" || tempname == "b") {
						goto currentMenu;
					}
				}
			}
			string PostTime = "";
			tempUser = netWork.GetUser(tempname);
			cout << "THe user I am going to look at is " << tempUser->GetUserName() << endl;
			cout << "Enter the name of the author of the post" << endl;
			cin >> author;
			cout << "Enter the date that post was created\n";
			cin >> PostTime;
			cin.ignore();
			cout << "Enter the first couple words of the posts\n(If there are more than one post has the same author and same date, you will need to be more specificy about the contents)";
			getline(cin, contents);
			cout << "Enter the response you want to add" << endl;
			getline(cin, response);

			cout << "Enter the Current Date as mm/dd/yy";
			cin >> time;

			//cout << "THe response I get is " << response << endl;
			//cout << "THe contents I get is " << contents << endl;
			if(tempUser->AddResponse(currentUser->GetUserName(), response, author, PostTime, contents, time))
				cout << "You have successfully add the comment" << endl;
			goto currentMenu;
		}

		if (toupper(command[0]) == 'R') {
			cout << "If you wannt to delete a response at your own wall, Enter 1,\n If you want to delete a response at your friend's wall, enter 2\n Enter B to back to main menu";
			cin >> command;
			if (command == "b" || command == "B")
				goto currentMenu;
			while (command != "1"&&command != "2") {
				cout << "INvalid command\n\n";
				cout << "If you wannt to delete a response at your own wall, Enter 1,\nIf you want to delete a response at your friend's wall, enter 2\nEnter B to back to main menu";
				cin >> command;
				if (command == "b" || command == "B")
					goto currentMenu;
			}
			if (command == "1") {
				tempUser = currentUser;
			}
			else {
				cout << "Enter your friend's name:\n";
				cin >> tempname;
				while (!currentUser->CheckFriendShip(tempname)) {
					cout << "You are not friend of " << tempname << endl;
					cout << "PLease etner the name again. (Enter B to back to main menu)";
					cin >> tempname;
					if (tempname == "B" || tempname == "b")
						goto currentMenu;
				}
				tempUser = netWork.GetUser(tempname);
			}
			if (tempUser == NULL) {
				cout << "Your friend does not exist in the network\n\n";
				goto currentMenu;
			}
			
			cout << "Enter the author of the post\n";
			cin >> author;
			
			cout << "Etner the date that post is created\n";
			cin >> time;
			cin.ignore();
			cout << "Enter the first couple words of the posts\n";
			getline(cin, contents);
			int index = tempUser->FindIndexOfPost(author, time, contents);
			cout << "The index I get is " << index << endl;
			if (index == -1) {
				cout << "The post does not exist\n\n";
				goto currentMenu;
			}
			cout << "I have find the Wall you describe\n";
			if (currentUser->GetUserName() != tempUser->GetUserName()) {
				author = currentUser->GetUserName();
			}
			else {
				cout << "Please enter the name of the commenter you want to delete\n";
				cin >> author;
				cin.ignore();
			}
			cout << "Enter the first couple word of the comment\n";
			
			getline(cin, contents);
			//cout << "THe author I get is " << author << endl;
			//cout << "The comment content I get is " << contents << endl;
			if (tempUser->RemoveResponse(index, author, contents)) {
				cout << "You have succesfully delete the response\n";
			}
			else {
				cout << "somehow I can't delete the response\n";
			}
			goto currentMenu;
		}

		if (toupper(command[0]) == 'E') {
			cout << "Enter the name of the user\n";
			cin >> tempname;
			while (!netWork.CheckUserName(tempname)) {
				cout << "The user with the name you enter does not exist in the network\nPlease enter tha name again\n(Enter B to back to main menu)\n";
				cin >> tempname;
				if (tempname == "B" || tempname == "b")
					goto currentMenu;
			}
			shortestpath.clear();
			int length = netWork.FindDegreeOfSeparation(currentUser, tempname,shortestpath);
			cout << "The degree of separation between you and " << tempname << " is" << length << endl;
			cout << "If you want to see the complete path, Enter 1, Otherwise you will go to the main menu";
			cin >> command;
			if (command == "1") {
				cout << "Shortest path is   ";
				for (string na : shortestpath)
					cout << na << " ";
				cout << endl<<endl;
			}

			goto currentMenu;
		}

		if (toupper(command[0]) == 'V') {
			cout << "Enter the degree N you want to find\n";
			int n;
			cin >> n;
			FriendNAway.clear();
			FriendNAway = netWork.AllUserInNDegreeAway(currentUser, n);
			for (string name : FriendNAway)
				cout << name << " ";
			cout << endl;
			goto currentMenu;
		}


		if (toupper(command[0]) == 'Q')
			goto exit;
	}

exit:
	netWork.SaveInFile("NetworkData.txt");
	return 0;
}

