#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Define a user class to store user details
class User {
public:
    string name;
    string gender;
    int age;
    string occupation;
    string interests;
    User(string n, string g, int a, string o, string i) {
        name = n;
        gender = g;
        age = a;
        occupation = o;
        interests = i;
    }
};

// Define a database class to store all users
class Database {
public:
    vector<User*> users;
    void addUser(User* user) {
        users.push_back(user);
    }
    vector<User*> searchUsers(string gender, int age) {
        vector<User*> results;
        for (User* user : users) {
            if (user->gender == gender && user->age == age) {
                results.push_back(user);
            }
        }
        return results;
    }
};

// Define a user interface to interact with the user
class UserInterface {
public:
    Database* db;
    UserInterface(Database* d) {
        db = d;
    }
    void createUser() {
        string name, gender, occupation, interests;
        int age;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter gender: ";
        cin >> gender;
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter occupation: ";
        cin >> occupation;
        cout << "Enter interests: ";
        cin >> interests;
        User* user = new User(name, gender, age, occupation, interests);
        db->addUser(user);
        cout << "User created: " << user->name << endl;
    }
    void searchUsers() {
        string gender;
        int age;
        cout << "Enter gender to search for: ";
        cin >> gender;
        cout << "Enter age to search for: ";
        cin >> age;
        vector<User*> results = db->searchUsers(gender, age);
        cout << "Search results:" << endl;
        for (User* user : results) {
            cout << "- " << user->name << endl;
        }
    }
};

int main() {
    Database* db = new Database();
    UserInterface* ui = new UserInterface(db);
    cout << "Welcome to the dating app!" << endl;
    while (true) {
        cout << endl;
        cout << "1. Create user" << endl;
        cout << "2. Search users" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                ui->createUser();
                break;
            case 2:
                ui->searchUsers();
                break;
            case 3:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
    return 0;
}
  
