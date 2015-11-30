#include<iostream>
#include<time.h>
#include "UserNetwork.h"

using std::cin;
using std::cout;
using std::endl;


int main() {
	cout << "What" << endl;
	UserNetwork network;
	string nameF[20] = { "EVA","ALgorithms", "Macbook", "System", "Surface", "Jack", "AGRAWAL", "AMIRI", "KUMAR", "TESSARO", "Vam", "Dam", "GIBOU","CONRAD", "COSTANZO", "Ben", "Gaucho", "UCSB", "Complier", "Apple" };
	string nameL[50] = { "Bomb", "Lol", "-.-", "QAQ", "Nice", "Baka", ">.<", "=_-", "Bug", "Header", "Windows", "OSX", "Linux", "PT", "Git", "Ls", "Cd","Pwd","Saber", "Lancer", "Caster", "Archer", "True", "False", "Bool", "Int", "Double", "Enter", "No", "Aha", "USB", "Thunder", "Charger", "Dell", "K702", "Void", "StarCraft", "Halo", "Wow", "OverWatch", "This", "Is", "Too", "Much", "I", "Can", "Not", "Come" "Up", "With", "More" };
	string name3[10] = { "0","1","2","3","4","5","6","7","8","9" };
	string name = "";
	string password = "";
	string BirthDay = "";
	User  u;

	for (int i = 0; i < 20; i++) {
		cout << "i = " << i << endl;
		for (int j = 0; j < 50; j++) {
			for (int k = 0; k < 10; k++) {
			
			name = (nameF[i] + "_" + nameL[j] + name3[k]);
			password = (name + "1234");
			BirthDay = "11/14/2015";
			u = User(name, password, BirthDay);
			//WallPost(string contents, string timePosted, string userName);
			u.AddPost(WallPost((name + " is trying to write something"), "11/14/15", name));
			u.AddPost(WallPost((name + " is trying to write somethingelse"), "11/14/15", name));
			u.AddPost(WallPost((name + " is tired"), "11/14/15", name));
			network.AddUser(u);
		}
		}
	}
	for (int i = 0; i <10000 ; i++) {
		for (int j = (i + 1); j < (i + 75); j++) {
			if (j >= 10000) break;
			cout << "I = " << i << " j = " << j << endl;
			if (!network.CheckFriendAtIndex(i, j))
				network.ForceBecomeFriend(i, j);
		}
	}

	network.SaveInFile("1000User.txt");
	cout << "Done\n";
}