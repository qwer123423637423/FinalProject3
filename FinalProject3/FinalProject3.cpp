
#include <iostream> 
#include "Header.h"
#include <fstream>
#include <string>
using namespace std;


int main()
{
    setlocale(LC_ALL, "");
    string _log;
    string _pas;
    string username;
    string userpassword;
    while (true) {
        int answer = 0;
        cout << "1. Войти" << endl;
        cout << "2. Зарегестрироваться" << endl;
        cin >> answer;
        if (answer == 1)
        {
            /* Вход в аккаунт*/
            while (true) {
                cout << "Введите логин и пароль" << endl;
                cin >> username;
                cin >> userpassword;

                /*Алгоритм взятия из файла данных*/
                string line;
                int flag = 0;
                int counter = 0;
                ifstream in("users.txt");
                if (in.is_open())
                {
                    while (getline(in, line))
                    {
                        int size_of_name = line.find(" ");
                        if (line.substr(0, size_of_name) == username)
                        {
                            counter += 1;
                            break;
                        }
                    }
                    if (counter > 0)
                    {
                        int size = line.length() - line.find(" ");
                        string _password = line.substr(line.find(" ") + 1, size);
                        if (userpassword == _password)
                        {
                            break;
                        }
                        else if (userpassword != _password)
                        {
                            cout << "Неверный пароль!" << endl;
                            continue;
                        }
                    }
                    if (counter == 0)
                    {
                        cout << "Такого пользователя не существует" << endl;
                        continue;
                    }
                }

            }

        }
        else if (answer == 2)
        {

            while (true) {
                /*Почти тоже самое, что и вход, но запись в файл*/
                cout << "Введите логин и пароль" << endl;
                cin >> username;
                cin >> userpassword;
                string line;
                int counter = 0;
                ifstream in("users.txt");
                if (in.is_open())
                {
                    while (getline(in, line))
                    {
                        int size_of_name = line.find(" ");
                        if (line.substr(0, size_of_name) == username)
                        {
                            counter += 1;
                        }
                    }
                    if (counter > 0)
                    {
                        cout << "Пользователь с таким ником уже существует" << endl;
                        continue;
                    }
                    else if (counter == 0)
                    {
                        break;
                    }
                }
            }
            ofstream out;
            out.open("users.txt", ios::app);
            if (out.is_open())
            {
                out << username + " " + userpassword + "\n";
            }
            out.close();

        }
        else
        {
            break;
        }




        User* userr = new User(username, userpassword);
        User& user = *userr;
        while (true) {
            printf("Выберите действие");

            printf("\n");

            /*интерфейс*/
            cout << "1. Написать сообщение" << endl;
            cout << "2. Информация об аккаунте" << endl;
            cout << "3. Выйти из аккаунта" << endl;
            cout << "4. Показать входящие сообщения сообщения" << endl;
            cout << "5. Показать общий чат" << endl;
            cout << "6. Написать в общий чат" << endl;

            int answer;

            cin >> answer;
            cout << endl;
            // действия с аккаунтом
            if (answer == 1)
            {
                string name, text;
                cout << "Кому отправить?" << endl;
                cin >> name;
                cout << endl;
                cout << "Введите сообщение" << endl;
                cin.seekg(cin.eof());
                _flushall();
                getline(cin, text);
                user.SendMesage(name, text);
            }
            else if (answer == 2)
            {
                user.Info();
                printf("\n");
            }
            else if (answer == 3)
            {
                delete userr;
                break;
            }
            else if (answer == 4)
            {
                user.ShowMesages();
            }
            else if (answer == 5)
            {
                user.SeeGeneral();
            }
            else if (answer == 6)
            {
                string text;
                cin.seekg(cin.eof());
                _flushall();
                getline(cin, text);
                user.SendGeneral(text);
            }
            else
            {
                cout << "Такого выбора нет" << endl;
                break;
            }
        }
    }
}