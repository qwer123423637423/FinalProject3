#include "Header.h"
# include <iostream>
#include <fstream>
#include <string>
using namespace std;


User::User(string name, string password)
{
	UserName = name;
	UserPassword = password;
}
void User::Info() const
{
	cout << "Ваш ник " << UserName << endl;
	cout << "Ваш пароль " << UserPassword << endl;
}

User::~User()
{
}

//???????? ???????? ?????????
void User::ShowMesages()
{
	string line;

	ifstream in("mesages.txt");
	if (in.is_open())
	{
		while (getline(in, line))
		{
			int counter = 0;
			if (line.find("To " + UserName) != string::npos)
			{
				counter += 1;
				int size_of_text = line.length() - line.find("*");
				cout << (line.substr(line.find("*") + 1, size_of_text)) << endl;
			}
			if (counter == 0)
			{
				cout << "Сообщений нет" << endl;
			}
		}
	}
	in.close();
}
//????????? ?????????
void User::SendMesage(string name, string text)
{
	ofstream out;
	out.open("mesages.txt", ios::app);
	if (out.is_open())
	{
		out << "To " + name + " " + "*" + text + " " + "From " + UserName;
	}
	out.close();
}
// ?????????? ????????? ???????? ????
void User::SeeGeneral()
{
	string line;
	ifstream in("general_chat.txt");
	if (in.is_open())
	{
		while (getline(in, line))
		{
			cout << line << endl;
			printf("\n");
		}
	}
	in.close();
}
//????????? ????????? ? ??????? ???
void User::SendGeneral(string text)
{
	ofstream out;
	out.open("general_chat.txt", ios::app);
	if (out.is_open())
	{
		out << UserName + " " + "написал: " + text << endl;
	}
	out.close();
}