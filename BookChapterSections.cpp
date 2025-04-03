#include <iostream>
#include <string.h>

using namespace std;

struct node {
    char name[15];
    node *next;
    node *down;
    int flag;
};

class GLL {
    char ch[20];
    node *head;
    node *t1;
    node *t2;

public:
    GLL() {
        head = NULL;
    }

    node *create();
    void insertb();
    void insertch();
    void insertsec();
    void displayb();
};

node* GLL::create() {
    node *temp = new node;
    temp->next = NULL;
    temp->down = NULL;
    temp->flag = 0;
    cout << "\nEnter the name: ";
    cin >> temp->name;
    return temp;
}

void GLL::insertb() {
    if (head == NULL) {
        t1 = create();
        head = t1;
    } else {
        cout << "\nBook already exists" << endl;
    }
}

void GLL::insertch() {
    int n;
    if (head == NULL) {
        cout << "\nCannot insert chapter (No book available!)" << endl;
    } else {
        cout << "\nHow many chapters do you want to insert?" << endl;
        cin >> n;
        for (int i = 0; i < n; i++) {
            t1 = create();
            if (head->flag == 0) {
                head->down = t1;
                head->flag = 1;
            } else {
                node *temp = head->down;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = t1;
            }
        }
    }
}

void GLL::insertsec() {
    int n;
    if (head == NULL) {
        cout << "\nCannot insert section (No book available!)" << endl;
        return;
    }
    cout << "\nEnter the name of the chapter to insert section: ";
    cin >> ch;

    node *temp = head;
    if (temp->flag == 0) {
        cout << "\nNo chapters in the book" << endl;
        return;
    }

    temp = temp->down;
    while (temp != NULL) {
        if (strcmp(ch, temp->name) == 0) {
            cout << "\nEnter the number of sections you want to enter: ";
            cin >> n;
            for (int i = 0; i < n; i++) {
                t1 = create();
                if (temp->flag == 0) {
                    temp->down = t1;
                    temp->flag = 1;
                } else {
                    node *t2 = temp->down;
                    while (t2->next != NULL) {
                        t2 = t2->next;
                    }
                    t2->next = t1;
                }
            }
            return;
        }
        temp = temp->next;
    }
    cout << "\nChapter not found!" << endl;
}

void GLL::displayb() {
    if (head == NULL) {
        cout << "\nNo book found!" << endl;
        return;
    }

    cout << "\nBook Name: " << head->name << endl;

    if (head->flag == 0) {
        cout << "No chapters available!" << endl;
        return;
    }

    node *chapter = head->down;
    while (chapter != NULL) {
        cout << "  Chapter: " << chapter->name << endl;

        if (chapter->flag == 0) {
            cout << "    No sections in this chapter" << endl;
        } else {
            node *section = chapter->down;
            while (section != NULL) {
                cout << "    Section: " << section->name << endl;
                section = section->next;
            }
        }
        chapter = chapter->next;
    }
}

int main() {
    GLL g1;
    int choice;
    do {
        cout << "\nMENU";
        cout << "\n1. Insert Book";
        cout << "\n2. Insert Chapter";
        cout << "\n3. Insert Section";
        cout << "\n4. Display Book";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                g1.insertb();
                break;
            case 2:
                g1.insertch();
                break;
            case 3:
                g1.insertsec();
                break;
            case 4:
                g1.displayb();
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
