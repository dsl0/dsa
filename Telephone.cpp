#include <iostream>
using namespace std;

// Store details: Node -> Key, Name, Telephone 
class node {
private:
    string name;
    string telephone;
    int key;
public:
    node() {
        key = 0;
        name = "";
        telephone = "";
    }
    friend class hashing;   // To access the private members of class node
};

// Hashing function that generates different key values
// Sum of ASCII values of each character in the string
int ascii_generator(string s) {
    int sum = 0;
    for (int i = 0; s[i] != '\0'; i++)
        sum = sum + s[i];
    return sum % 100;
}

// Hash Table Class
class hashing {
private:
    node data[100]; // Size of directory -> 100
    int size = 100;

public:
    // Function to create record
    void create_record(string n, string tele) {
        int k = ascii_generator(n);   // Using ASCII value of string as key
        int index = k % size;   

        for (int j = 0; j < size; j++) {
            if (data[index].key == 0) {
                data[index].key = k;
                data[index].name = n;
                data[index].telephone = tele;
                cout << "Record Added Successfully!\n";
                return;
            } 
            index = (index + 1) % size; // Linear probing
        }
        cout << "Hash Table is Full! Cannot insert record.\n";
    }

    // Function to search for record based on name input
    void search_record(string name) {
        int k = ascii_generator(name);
        int index = k % size;

        for (int i = 0; i < size; i++) {
            if (data[index].key == k && data[index].name == name) {
                cout << "\nRecord found\n";
                cout << "Name: " << data[index].name << endl;
                cout << "Telephone: " << data[index].telephone << endl;
                return;
            }
            if (data[index].key == 0) break; // Stop search if empty slot is found
            index = (index + 1) % size;
        }
        cout << "Record not found\n";
    }

    // Function to delete an existing record
    void delete_record(string name) {
        int k = ascii_generator(name);
        int index = k % size;

        for (int i = 0; i < size; i++) {
            if (data[index].key == k && data[index].name == name) {
                data[index].key = 0;
                data[index].name = "";
                data[index].telephone = "";
                cout << "\nRecord Deleted Successfully!\n";
                return;
            }
            if (data[index].key == 0) break; // Stop search if empty slot is found
            index = (index + 1) % size;
        }
        cout << "\nRecord not found\n";
    }

    // Function to update an existing record
    void update_record(string name) {
        int k = ascii_generator(name);
        int index = k % size;

        for (int i = 0; i < size; i++) {
            if (data[index].key == k && data[index].name == name) {
                cout << "Enter the new telephone number: ";
                cin >> data[index].telephone;
                cout << "\nRecord Updated Successfully!\n";
                return;
            }
            if (data[index].key == 0) break; // Stop search if empty slot is found
            index = (index + 1) % size;
        }
        cout << "\nRecord not found\n";
    }

    // Function to display the directory
    void display_record() {
        cout << "\n\t  Name  \t\t Telephone\n";
        cout << "---------------------------------------";
        for (int a = 0; a < size; a++) {
            if (data[a].key != 0) {
                cout << "\n\t" << data[a].name << " \t\t " << data[a].telephone;
            }
        }
        cout << endl;
    }
};

// Main Function
int main() {
    hashing s;
    string name, telephone;
    int choice;
    bool loop = true;

    // Menu-driven code
    while (loop) {
        cout << "\n-------------------------\n"
             << " Telephone Book Database \n"
             << "-------------------------\n"
             << "1. Create Record\n"
             << "2. Display Records\n"
             << "3. Search Record\n"
             << "4. Update Record\n"
             << "5. Delete Record\n"
             << "6. Exit\n"
             << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nEnter name: ";
                cin >> name;
                cout << "Enter Telephone number: ";
                cin >> telephone;
                s.create_record(name, telephone);
                break;
            
            case 2:
                s.display_record();
                break;

            case 3:
                cout << "\nEnter the name: ";
                cin >> name;
                s.search_record(name);
                break;

            case 4:
                cout << "\nEnter the name: ";
                cin >> name;
                s.update_record(name);
                break;

            case 5:
                cout << "\nEnter name to delete: ";
                cin >> name;
                s.delete_record(name);
                break;

            case 6:
                loop = false;
                break;

            default:
                cout << "\nInvalid choice! Please enter a valid option.\n";
                break;
        }
    }   
    return 0;
}
