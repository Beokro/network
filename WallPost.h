#ifndef WALLPOST_H_
#define WALLPOST_H_
#include <string>
#include <vector> 
using std::vector;
using std::string;

struct Response {
	string name;
	string contents;
	string time;
	Response(string n, string t, string c) { name = n; time = t;  contents = c; }
};

class WallPost{
private:
	string contents;
	string timePosted;
	string userName;
	vector<Response> responses;
public:
	WallPost(string contents, string timePosted, string userName);
	WallPost(string contents, string timePosted, string userName, vector<string> commentName, vector<string> commentTime, vector<string> commentResponse);
	WallPost() : contents(""), timePosted(""), userName("") {}
	~WallPost();
	void updateTime(string time);
	void updateContents(string newContents);
	void changeUserName(string newUserName);
	string GetUserName() const {return userName;}
	string GetTime() const {return timePosted;}
	string GetContents() const {return contents;}
	string Print();
	string PrintForSave();
	void AddResponse(string name, string time, string response);
	bool RemoveResponse(string author, string partial);
	friend bool operator==(const WallPost & lfs, const WallPost & rhs) ;
	friend bool operator!=(const WallPost & lfs, const WallPost & rhs) { return !(lfs == rhs); };
};



#endif