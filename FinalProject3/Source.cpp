#include "Header.h"
# include <iostream>
#include <fstream>
#include <string>
using namespace std;


Server::Server() 
{
	
}
void Server::GetUserInfo(string name)
{
	string line;
	int size_name;
	int size_password;
	ifstream in("users.txt");
	if (in.is_open())
	{
		while (getline(in, line))
		{
			if (line.find(name) != string::npos)
			{
				size_name = line.find(" ");
				size_password = line.length() - size_name;
				cout << "Имя аккаунта " + line.substr(0, size_name) << endl;
				cout << "Пароль от аккаунта " + line.substr(size_name + 1, size_password) << endl;
			}
		}
		in.close();
	}
}
void Server::GetMessagesForUser(string name) 
{
	string line;

	ifstream in("mesages.txt");
	if (in.is_open())
	{
		while (getline(in, line))
		{
			int counter = 0;
			if (line.find("To " + name) != string::npos)
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
void Server::WriteMessage(string from, string to, string text)
{
	ofstream out;
	out.open("mesages.txt", ios::app);
	if (out.is_open())
	{
		out << "To " + to + " " + "*" + text + " " + "From " + from;
	}
	out.close();
}
void Server::RegisterUser(string name, string password)
{

}
void Server::Login(string name, string password)
{

}
void Server::GetGeneral() 
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
void Server::SendGeneral(string from, string text) 
{
	ofstream out;
	out.open("general_chat.txt", ios::app);
	if (out.is_open())
	{
		out << from + " " + "написал: " + text << endl;
	}
	out.close();
}

User::User(string name, string password)
{
	UserName = name;
	UserPassword = password;
}
User::~User()
{
}

