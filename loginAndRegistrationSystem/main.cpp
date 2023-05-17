#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

// Map to store user information (username, password)
map<string, string> users;

// Function to register a new user
void registerUser() {
    string username, password;
	cout << endl;
	cout << "=================================" << endl;
	cout << endl;
    cout << "Enter username: ";
    cin >> username;

    // Check if the username already exists
    if (users.find(username) != users.end()) {
		cout << endl;
		cout << "=================================" << endl;
		cout << endl;
        cout << "Username already exists!" << endl;
		cout << endl;
		cout << "=================================" << endl;
		cout << endl;
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    // Add the new user to the map
    users[username] = password;

    // Append the new user to the file
    ofstream outfile("users.txt", ios::app);
    outfile << username << " " << password << endl;
    outfile.close();
	
	cout << endl;
    cout << "=================================" << endl;
	cout << endl;
	cout << "Registration successful!" << endl;
	cout << endl;
}

// Function to log in an existing user
void loginUser() {
    string username, password;
	cout << endl;
	cout << "====================" <<endl;
	cout << endl;
    cout << "Enter username: ";
    cin >> username;

    // Check if the username exists
    if (users.find(username) == users.end()) {
		cout << endl;
		cout << "=================================" << endl;
		cout << endl;
        cout << "User not found!" << endl;
		cout << endl;
		cout << "=================================" << endl;
		cout << endl;
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    // Check if the entered password matches the stored password
    if (users[username] == password) {
		cout << endl;
		cout << "=================================" << endl;
		cout << endl;
        cout << "Login successful!" << endl;
		cout << endl;
		cout << "=================================" << endl;
		cout << endl;
    } else {
		cout << endl;
        cout << "=================================" << endl;
		cout << endl;
		cout << "Incorrect password!" << endl;
		cout << endl;
		cout << "=================================" << endl;
		cout << endl;
    }
}

// Function to delete an existing user
void deleteUser() {
    string username;
	cout << endl;
	cout << "=================================" << endl;
	cout << endl;
    cout << "Enter username: ";
    cin >> username;

    // Check if the username exists
    if (users.find(username) == users.end()) {
		cout << endl;
		cout << "=================================" << endl;
		cout << endl;
        cout << "User not found!" << endl;
		cout << endl;
		cout << "=================================" << endl;
		cout << endl;
        return;
    }

    // Remove the user from the map
    users.erase(username);

    // Overwrite the file with the updated user information
    ofstream outfile("users.txt");
    for (const auto& [key, value] : users) {
        outfile << key << " " << value << endl;
    }
    outfile.close();
	
	cout << endl;
	cout << "=================================" << endl;
	cout << endl;
    cout << "User deleted!" << endl;
	cout << endl;
	cout << "=================================" << endl;
	cout << endl;
}

// Function to read the user information from the file
void readUsersFromFile() {
    ifstream infile("users.txt");
    string username, password;
    while (infile >> username >> password) {
        users[username] = password;
    }
    infile.close();
}

// Function to display all the registered users
void displayUsers() {
	cout << endl;
	cout << "=================================" << endl;
	cout << endl;
    cout << "Registered Users:" << endl;
	cout << endl;
    for (const auto& [key, value] : users) {
        cout << "Username: " << key << ", Password: " << value << endl;
    }
	cout << endl;
	cout << "=================================" << endl;
	cout << endl;
}

int main() {
    int choice;

    // Read the user information from the file
    readUsersFromFile();
	cout << "Welcome to the simple Login-Registration System by Ninetysix" << endl;
	cout << endl;
    while (true) {
        cout << "Select an option:" << endl;
		cout << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Delete User" << endl;
        cout << "4. Display Users" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                deleteUser();
                break;
            case 4:
                displayUsers();
                break;
            case 5:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}
