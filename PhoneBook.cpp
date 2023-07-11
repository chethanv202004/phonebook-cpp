#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
private:
    string name;
    string country_code;
    string mobile_no;
    string gender;
    string email;

public:
    // Parameterized constructor
    Person(const string& name, const string& country_code,
           const string& mobile_no, const string& gender,
           const string& email)
        : name(name),
          country_code(country_code),
          mobile_no(mobile_no),
          gender(gender),
          email(email) {}

    // Friend function to access private members
    friend ostream& operator<<(ostream& os, const Person& person);

    // Getter functions
    string getName() const { return name; }
    string getCountryCode() const { return country_code; }
    string getMobileNo() const { return mobile_no; }
    string getGender() const { return gender; }
    string getEmail() const { return email; }

    // Setter functions
    void setName(const string& name) { this->name = name; }
    void setCountryCode(const string& country_code) { this->country_code = country_code; }
    void setMobileNo(const string& mobile_no) { this->mobile_no = mobile_no; }
    void setGender(const string& gender) { this->gender = gender; }
    void setEmail(const string& email) { this->email = email; }
};

ostream& operator<<(ostream& os, const Person& person) {
    os << "Name: " << person.name << endl;
    os << "Country Code: " << person.country_code << endl;
    os << "Mobile No: " << person.mobile_no << endl;
    os << "Gender: " << person.gender << endl;
    os << "Email: " << person.email << endl;
    return os;
}

class PhoneBook {
private:
    vector<Person> contacts;

public:
    void addPerson() {
        string name, country_code, mobile_no, gender, email;

        cout<<"-------------------------------------"<<endl;
        cout << "Enter details for the new contact:" << endl;
        cout << "Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Country Code: ";
        cin >> country_code;
        cout << "Mobile No: ";
        cin >> mobile_no;

        // Check if the mobile number has 10 digits
        while (mobile_no.length() != 10) {
            cout<<"-------------------------------------"<<endl;
            cout << "Mobile No should have exactly 10 digits. Please enter again: ";
            cin >> mobile_no;
        }

        cout << "Gender: ";
        cin >> gender;
        cout << "Email: ";
        cin >> email;

        contacts.emplace_back(name, country_code, mobile_no, gender, email);
        cout<<"-------------------------------------"<<endl;
        cout<<"-------------------------------------"<<endl;
        cout << "Contact added successfully!" << endl;
        cout<<"-------------------------------------"<<endl;
        cout<<"-------------------------------------"<<endl;
    }

    void listRecords() {
        if (contacts.empty()) {
            cout << "No contacts in the phone book." << endl;
        } else {
            cout << "Phone Book Records:" << endl << endl;
            for (const auto& person : contacts) {
                cout << "----------------------------------------" << endl;
                cout << person << endl;
                cout << "----------------------------------------" << endl;
            }
        }
    }

    void searchPerson() {
        int searchChoice;
        cout<<"-------------------------------"<<endl;
        cout << "Search by:" << endl;
        cout << "1. Phone Number" << endl;
        cout << "2. Name" << endl;
        cout << "Enter your choice (1-2): ";
        cin >> searchChoice;

        if (searchChoice == 1) {
            string mobile_no;
            cout << "Enter the mobile number to search: ";
            cin >> mobile_no;

            bool found = false;
            for (const auto& person : contacts) {
                if (person.getMobileNo() == mobile_no) {
                    cout<<"----------------------"<<endl;
                    cout << "Person found:" << endl;
                    cout << person << endl;
                    found = true;
                    break;
                    cout<<"----------------------"<<endl;
                }
            }
            if (!found) {
                cout<<"----------------------"<<endl;
                cout << "Person not found in the phone book." << endl;
            }
        } else if (searchChoice == 2) {
            string name;
            cout << "Enter the name to search: ";
            cin.ignore();
            getline(cin, name);

            bool found = false;
            for (const auto& person : contacts) {
                if (person.getName() == name) {
                    cout << "Person found:" << endl;
                    cout << person << endl;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout<<"-------------------------------------"<<endl;
                cout << "Person not found in the phone book." << endl;
                cout<<"-------------------------------------"<<endl;
            }
        } else {
            cout<<"-------------------------------------"<<endl;
            cout << "Invalid choice. Please try again." << endl;
            cout<<"-------------------------------------"<<endl;
        }
    }

    void editPerson() {
        int editChoice;
        cout<<"-------------------------------------"<<endl;
        cout << "Edit by:" << endl;
        cout << "1. Phone Number" << endl;
        cout << "2. Name" << endl;
        cout<<"-------------------------------------"<<endl;
        cout << "Enter your choice (1-2): ";
        cin >> editChoice;

        if (editChoice == 1) {
            string mobile_no;
            cout << "Enter the mobile number of the contact to edit: ";
            cin >> mobile_no;

            bool found = false;
            for (auto& person : contacts) {
                if (person.getMobileNo() == mobile_no) {
                    cout << "Enter the new mobile number: ";
                    cin >> mobile_no;
                    
                    // Check if the mobile number has 10 digits
                    while (mobile_no.length() != 10) {
                        cout<<"-------------------------------------"<<endl;
                        cout << "Mobile No should have exactly 10 digits. Please enter again: ";
                        cin >> mobile_no;
                    }
                    
                    person.setMobileNo(mobile_no);
                    cout<<"-------------------------------------"<<endl;
                    cout << "Contact updated successfully!" << endl;
                    cout<<"-------------------------------------"<<endl;
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout<<"-------------------------------------"<<endl;
                cout << "Person not found in the phone book." << endl;
                cout<<"-------------------------------------"<<endl;
            }
        } else if (editChoice == 2) {
            string name;
            cout << "Enter the name of the contact to edit: ";
            cin.ignore();
            getline(cin, name);

            bool found = false;
            for (auto& person : contacts) {
                if (person.getName() == name) {
                    string mobile_no;
                    cout << "Enter the new mobile number: ";
                    cin >> mobile_no;
                    
                    // Check if the mobile number has 10 digits
                    while (mobile_no.length() != 10) {
                        cout<<"-------------------------------------"<<endl;
                        cout << "Mobile No should have exactly 10 digits. Please enter again: ";
                        cin >> mobile_no;
                    }
                    
                    person.setMobileNo(mobile_no);
                    cout<<"-------------------------------------"<<endl;
                    cout << "Contact updated successfully!" << endl;
                    cout<<"-------------------------------------"<<endl;
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout<<"-------------------------------------"<<endl;
                cout << "Person not found in the phone book." << endl;
                cout<<"-------------------------------------"<<endl;
            }
        } else {
            cout<<"-------------------------------------"<<endl;
            cout << "Invalid choice. Please try again." << endl;
            cout<<"-------------------------------------"<<endl;
        }
    }

    void removePerson() {
        string mobile_no;
        cout << "Enter the mobile number to remove: ";
        cin >> mobile_no;

        auto it = contacts.begin();
        while (it != contacts.end()) {
            if (it->getMobileNo() == mobile_no) {
                it = contacts.erase(it);
                cout<<"-------------------------------------"<<endl;
                cout << "Contact removed successfully!" << endl;
                cout<<"-------------------------------------"<<endl;
                return;
            } else {
                ++it;
            }
        }
        cout<<"-------------------------------------"<<endl;
        cout << "Person not found in the phone book." << endl;
        cout<<"-------------------------------------"<<endl;
    }

    void removeAll() {
        contacts.clear();
        cout<<"-------------------------------------"<<endl;
        cout << "All contacts removed from the phone book." << endl;
        cout<<"-------------------------------------"<<endl;
    }
};

int main() {
    PhoneBook phoneBook;
    int choice;

    do {
        cout<<"\t\t\t"<<"*********************************"<<endl;
        cout <<"\t\t\t\t"<< "PHONE BOOK " << endl;
        cout<<"\t\t\t"<<"---------------------------------"<<endl;
        cout <<"\t\t\t"<< "1. Add a contact" << endl;
        cout <<"\t\t\t"<< "2. Delete a contact" << endl;
        cout <<"\t\t\t"<< "3. Edit a contact" << endl;
        cout <<"\t\t\t"<< "4. Display all contacts" << endl;
        cout <<"\t\t\t"<< "5. Search a contact" << endl;
        cout <<"\t\t\t"<< "6. DELETE ALL" << endl;
        cout <<"\t\t\t"<< "7. Quit" << endl;
        cout<<"\t\t\t"<<"*********************************"<<endl;
        cout << "Enter your choice (1-7): ";
        cin >> choice;

        switch (choice) {
            case 1:
                phoneBook.addPerson();
                break;
            case 2:
                phoneBook.removePerson();
                break;
            case 3:
                phoneBook.editPerson();
                break;
            case 4:
                phoneBook.listRecords();
                break;
            case 5:
                phoneBook.searchPerson();
                break;
            case 6:
                phoneBook.removeAll();
                break;
            case 7:
            cout<<"-------------------------------------"<<endl;
                cout << "Exiting the phone book." << endl;
                cout<<"-------------------------------------"<<endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    } while (choice != 6);

    return 0;
}