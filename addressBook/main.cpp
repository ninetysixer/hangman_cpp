#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cctype>
#include <cstring>

#ifdef _WIN32
    #define CLEAR_SCREEN "cls"
#else
    #define CLEAR_SCREEN "clear"
#endif

struct Contact {
    std::string phoneNumber;
    std::string emailAddress;
};

class AddressBook {
private:
    std::map<std::string, Contact> contacts;

public:
    void addContact(const std::string& name, const std::string& phoneNumber, const std::string& emailAddress) {
        Contact contact;
        contact.phoneNumber = phoneNumber;
        contact.emailAddress = emailAddress;
        contacts[name] = contact;
		std::cout << "\n========================== ============================" << std::endl;
        std::cout << "Contact added successfully." << std::endl;
		std::cout << "========================== ============================" << std::endl;
    }

    void searchContact(const std::string& name) {
        if (contacts.find(name) != contacts.end()) {
            Contact contact = contacts[name];
			std::cout << "\n========================== ============================" << std::endl;
            std::cout << "Name: " << name << std::endl;
            std::cout << "Phone Number: " << contact.phoneNumber << std::endl;
            std::cout << "Email Address: " << contact.emailAddress << std::endl;
			std::cout << "========================== ============================" << std::endl;
        } else {
			std::cout << "\n========================== ============================" << std::endl;
            std::cout << "Contact not found." << std::endl;
			std::cout << "========================== ============================" << std::endl;
        }
    }

    void updateContact(const std::string& name, const std::string& phoneNumber, const std::string& emailAddress) {
        if (contacts.find(name) != contacts.end()) {
            Contact& contact = contacts[name];
            contact.phoneNumber = phoneNumber;
            contact.emailAddress = emailAddress;
			std::cout << "\n========================== ============================" << std::endl;
            std::cout << "Contact updated successfully." << std::endl;
			std::cout << "========================== ============================" << std::endl;
        } else {
			std::cout << "\n========================== ============================" << std::endl;
            std::cout << "Contact not found." << std::endl;
			std::cout << "========================== ============================" << std::endl;
        }
    }

    void deleteContact(const std::string& name) {
        if (contacts.find(name) != contacts.end()) {
            contacts.erase(name);
			std::cout << "\n========================== ============================" << std::endl;
            std::cout << "Contact deleted successfully." << std::endl;
			std::cout << "========================== ============================" << std::endl;
        } else {
			std::cout << "\n========================== ============================" << std::endl;
            std::cout << "Contact not found." << std::endl;
			std::cout << "========================== ============================" << std::endl;
        }
    }
	
	void saveContactsToFile(const std::string& filename) {
        std::ofstream file(filename);

        if (file.is_open()) {
            for (const auto& contact : contacts) {
                file << contact.first << "," << contact.second.phoneNumber << "," << contact.second.emailAddress << std::endl;
            }
            std::cout << "\nContacts saved to file successfully.\n" << std::endl;
            file.close();
        } else {
            std::cout << "Unable to open file for saving contacts." << std::endl;
        }
    }

    void loadContactsFromFile(const std::string& filename) {
		std::ifstream file(filename);

		if (file.is_open()) {
			std::string line;
			while (std::getline(file, line)) {
				std::string name, phoneNumber, emailAddress;
				std::size_t pos = line.find(',');
				if (pos != std::string::npos) {
					name = line.substr(0, pos);
					std::size_t pos2 = line.find(',', pos + 1);
					if (pos2 != std::string::npos) {
						phoneNumber = line.substr(pos + 1, pos2 - pos - 1);
						emailAddress = line.substr(pos2 + 1);
						contacts[name] = { phoneNumber, emailAddress };
					}
				}
			}
			std::cout << "Contacts loaded from file successfully.\n" << std::endl;
			file.close();
		} else {
			std::cout << "File doesn't exist. Creating a new file." << std::endl;
			std::ofstream newFile(filename);
			if (newFile.is_open()) {
				std::cout << "New file created successfully." << std::endl;
				newFile.close();
			} else {
				std::cout << "Unable to create the new file." << std::endl;
			}
		}
	}

};

int main() {
    AddressBook addressBook;
	std::string filename = "contacts.txt";
	addressBook.loadContactsFromFile(filename);
    int choice;
    std::string name, phoneNumber, emailAddress, final_answer;

    do {
		std::cout << "Address Book by semihdursungul\n" << std::endl;
        std::cout << "Main Menu" << std::endl;
        std::cout << "\n1. Add Contact" << std::endl;
        std::cout << "2. Search Contact" << std::endl;
        std::cout << "3. Update Contact" << std::endl;
        std::cout << "4. Delete Contact" << std::endl;
        std::cout << "5. Quit" << std::endl;
        std::cout << "\nEnter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
				std::cout << "\n========================== ============================" << std::endl;
                std::cout << "\nEnter name: ";
                std::cin.ignore();  // Ignore the newline character in the input buffer
                std::getline(std::cin, name);
                std::cout << "Enter phone number: ";
                std::getline(std::cin, phoneNumber);
                std::cout << "Enter email address: ";
                std::getline(std::cin, emailAddress);
                addressBook.addContact(name, phoneNumber, emailAddress);
				std::cout << "\nDo you want to go back to the main menu? Type 'y' or 'n': ";
				std::getline(std::cin,final_answer);
				if (final_answer == "y") {
					system(CLEAR_SCREEN);
					break;
				}
				else {
					choice = 5;
					std::cout << "\n========================== ============================" << std::endl;
					addressBook.saveContactsToFile(filename);
					std::cout << "Exiting program." << std::endl;
					break;
				}
                

            case 2:
				std::cout << "\n========================== ============================" << std::endl;
                std::cout << "\nEnter name to search: ";
                std::cin.ignore();  // Ignore the newline character in the input buffer
                std::getline(std::cin, name);
                addressBook.searchContact(name);
                std::cout << "\nDo you want to go back to the main menu? Type 'y' or 'n': ";
				std::getline(std::cin,final_answer);
				if (final_answer == "y") {
					system(CLEAR_SCREEN);
					break;
				}
				else {
					choice = 5;
					std::cout << "\n========================== ============================" << std::endl;
					addressBook.saveContactsToFile(filename);
					std::cout << "Exiting program." << std::endl;
					break;
				}

            case 3:
				std::cout << "\n========================== ============================" << std::endl;
                std::cout << "\nEnter name to update: ";
                std::cin.ignore();  // Ignore the newline character in the input buffer
                std::getline(std::cin, name);
                std::cout << "Enter new phone number: ";
                std::getline(std::cin, phoneNumber);
                std::cout << "Enter new email address: ";
                std::getline(std::cin, emailAddress);
                addressBook.updateContact(name, phoneNumber, emailAddress);
                std::cout << "\nDo you want to go back to the main menu? Type 'y' or 'n': ";
				std::getline(std::cin,final_answer);
				if (final_answer == "y") {
					system(CLEAR_SCREEN);
					break;
				}
				else {
					choice = 5;
					std::cout << "\n========================== ============================" << std::endl;
					addressBook.saveContactsToFile(filename);
					std::cout << "Exiting program." << std::endl;
					break;
				}

            case 4:
				std::cout << "\n========================== ============================" << std::endl;
                std::cout << "\nEnter name to delete: ";
                std::cin.ignore();  // Ignore the newline character in the input buffer
                std::getline(std::cin, name);
                addressBook.deleteContact(name);
                std::cout << "\nDo you want to go back to the main menu? Type 'y' or 'n': ";
				std::getline(std::cin,final_answer);
				if (final_answer == "y") {
					system(CLEAR_SCREEN);
					break;
				}
				else {
					choice = 5;
					std::cout << "\n========================== ============================" << std::endl;
					addressBook.saveContactsToFile(filename);
					std::cout << "Exiting program." << std::endl;
					break;
				}

            case 5:
				std::cout << "\n========================== ============================" << std::endl;
				// Save contacts to file
				addressBook.saveContactsToFile(filename);
                std::cout << "Exiting program." << std::endl;
                break;

            default:
				std::cout << "\n========================== ============================" << std::endl;
                std::cout << "\nInvalid choice. Please try again." << std::endl;
				std::cout << "\n========================== ============================" << std::endl;
        }

        std::cout << std::endl;

    } while (choice != 5);


    return 0;
}
