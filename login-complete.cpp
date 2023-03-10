#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct User {
    string username;
    string password;
};

vector<User> users;

void subscribe() {
    string username, password;
    cout << "Enter a username: ";
    cin >> username;

    for (User user : users) {
        if (user.username == username) {
            cout << "This username is already taken." << endl;
            return;
        }
    }

    cout << "Enter a password: ";
    cin >> password;

    users.push_back({username, password});
    cout << "You have successfully subscribed!" << endl;
}

void login() {
    string username, password;
    cout << "Enter your username: ";
    cin >> username;

    cout << "Enter your password: ";
    cin >> password;

    for (User user : users) {
        if (user.username == username && user.password == password) {
            cout << "Login successful!" << endl;
            return;
        }
    }

    cout << "Invalid username or password." << endl;
}

int main() {
    int choice;

    do {
        cout << "1. Subscribe\n2. Login\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                subscribe();
                break;
            case 2:
                login();
                break;
            case 3:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
                break;
        }
    } while (choice != 3);

    return 0;
}
