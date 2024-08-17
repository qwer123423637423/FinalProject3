#pragma once
# include <iostream>
using namespace std;

class User
{
public:
	User(string name, string password);
	~User();

private:
	string UserName;
	string UserPassword;
};

class Server 
{
public:
	Server();
	void GetUserInfo(string name);
	void GetMessagesForUser(string name);
	void WriteMessage(string from, string to, string text);
	void GetGeneral();
	void SendGeneral(string from, string text);
};