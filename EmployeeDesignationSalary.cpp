#include <iostream>
#include <fstream>

using namespace std;

// Manual Employee Structure
class Employee {
public:
    int id;
    char name[50];
    char designation[50];
    float salary;

    Employee() {
        id = 0;
        salary = 0;
        name[0] = '\0';
        designation[0] = '\0';
    }

    // Function to input employee details manually
    void input() {
        cout << "Enter Employee ID: ";
        cin >> id;
        cin.ignore(); // Clear buffer

        cout << "Enter Name: ";
        cin.getline(name, 50);

        cout << "Enter Designation: ";
        cin.getline(designation, 50);

        cout << "Enter Salary: ";
        cin >> salary;
    }

    // Function to display employee details
    void display() {
        cout << "ID: " << id << " | Name: " << name;
        cout << " | Designation: " << designation << " | Salary: " << salary << "\n";
    }
};

// User-defined File Handler class
class FileHandler {
public:
    // Function to add an employee
    void addEmployee() {
        Employee emp;
        emp.input();

        ofstream fout("employees.dat", ios::binary | ios::app);
        fout.write((char*)&emp, sizeof(emp));
        fout.close();

        cout << "✅ Employee added successfully!\n";
    }

    // Function to search for an employee
    void searchEmployee() {
        int searchID;
        Employee emp;
        ifstream fin("employees.dat", ios::binary);

        cout << "Enter Employee ID to Search: ";
        cin >> searchID;

        bool found = false;
        while (fin.read((char*)&emp, sizeof(emp))) {
            if (emp.id == searchID) {
                cout << "\n✅ Employee Found!\n";
                emp.display();
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "❌ Employee with ID " << searchID << " does not exist!\n";
        }

        fin.close();
    }

    // Function to delete an employee
    void deleteEmployee() {
        int deleteID;
        Employee emp;
        ifstream fin("employees.dat", ios::binary);
        ofstream fout("temp.dat", ios::binary);

        cout << "Enter Employee ID to Delete: ";
        cin >> deleteID;

        bool found = false;
        while (fin.read((char*)&emp, sizeof(emp))) {
            if (emp.id == deleteID) {
                found = true;
            } else {
                fout.write((char*)&emp, sizeof(emp));
            }
        }

        fin.close();
        fout.close();

        remove("employees.dat");
        rename("temp.dat", "employees.dat");

        if (found) {
            cout << "✅ Employee deleted successfully!\n";
        } else {
            cout << "❌ Employee with ID " << deleteID << " not found!\n";
        }
    }

    // Function to display all employees
    void displayAllEmployees() {
        Employee emp;
        ifstream fin("employees.dat", ios::binary);

        cout << "\n📌 List of Employees:\n";
        while (fin.read((char*)&emp, sizeof(emp))) {
            emp.display();
        }

        fin.close();
    }
};

// Main Menu Class (User-defined)
class Menu {
public:
    void showMenu() {
        FileHandler fileHandler;
        int choice;

        do {
            cout << "\n--- 🏢 Employee Management System ---\n";
            cout << "1. Add Employee\n2. Search Employee\n3. Delete Employee\n4. Display All Employees\n5. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: fileHandler.addEmployee(); break;
                case 2: fileHandler.searchEmployee(); break;
                case 3: fileHandler.deleteEmployee(); break;
                case 4: fileHandler.displayAllEmployees(); break;
                case 5: cout << "🚪 Exiting... Goodbye!\n"; break;
                default: cout << "❌ Invalid choice! Try again.\n";
            }
        } while (choice != 5);
    }
};

// Main function
int main() {
    Menu menu;
    menu.showMenu();
    return 0;
}
