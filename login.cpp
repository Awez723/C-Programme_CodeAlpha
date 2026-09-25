#include <iostream>
#include <fstream>
using namespace std;

void registrationuser(){
    string username;
    string password;

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    ofstream file("users.txt");
    file << username << endl;
    file << password << endl;
    file.close();

cout << "Registration successful!" << endl;
}

void loginUser()
{
    string username;
    string password;

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");

    string savedUsername;
    string savedPassword;
    file >> savedUsername;
    file >> savedPassword;
    file.close();

    if (username == savedUsername && password == savedPassword)
    {
    cout << "Login successful!" << endl;
    }
else{
    cout << "Invalid username or password!" << endl;
    }
}


int main()
{
    cout << "Login and Registration System" << endl;
    registrationuser();
    loginUser();

    return 0;
}