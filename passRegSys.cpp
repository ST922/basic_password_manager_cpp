#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void registration(string username, string password);
void login(string username, string password);
void incorrect();

int main()
{
    string username;
    string password;

    int choice;

    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "What would you like to do? ";
    cin >> choice;

    if (choice == 1)
    {
        registration(username, password);
    }
    else if (choice == 2)
    {
        login(username, password);
    }
    else
    {
        incorrect();
    }
}

void registration(string username, string password)
{
    fstream file;
    file.open("passwordData.dat");

    cout << "Please enter a username: ";
    cin >> username;
    file << username;
    file << endl;

    cout << "Please enter a password: ";
    cin >> password;

    while (password == username)
    {
        cout << "Your password cannot be the same as your username." << endl;
        cout << "Please enter a different password: ";
        cin >> password;
    }

    file << password;
    file << endl;

    file.close();

    main();
}

void login(string username, string password)
{
    string line;
    bool found = false;

    fstream file;
    file.open("passwordData.dat");

    cout << endl;
    cout << "Welcome back!" << endl;

    cout << "Please enter your username: ";
    cin >> username;

    while (getline(file, line) && !found)
    {
        if (username == line)
            found = true;
    }
    if (!found)
    {
        cout << "You have entered an invalid username. Please restart." << endl;
        main();
    }

    found = false;

    file.close();
    file.open("passwordData.dat");

    cout << "Please enter your password: ";
    cin >> password;

    while (getline(file, line) && !found)
    {
        if (password == line)
            found = true;
    }
    if (!found)
    {
        cout << "You have entered an invalid password. Please restart." << endl;
        main();
    }

    file.close();
}

void incorrect()
{
    cout << "You have given an invalid entry. Please try again." << endl;

    main();
}