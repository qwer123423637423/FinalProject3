#pragma once
# include <iostream>
using namespace std;

class User
{
public:
	// ???????? ??????? ???????
	User(string name, string password);
	void Info() const;
	void ShowMesages();
	void SendMesage(string name, string text);
	void SeeGeneral();
	void SendGeneral(string text);
	~User();

private:
	string UserName;
	string UserPassword;
};