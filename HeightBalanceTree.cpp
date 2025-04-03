#include <iostream>
#include <string>

using namespace std;

// Node structure for BST
class Node {
public:
    string key, value;
    Node *left, *right;

    Node() {
        key = "";
        value = "";
        left = NULL;
        right = NULL;
    }

    Node(string key, string value) {
        this->key = key;
        this->value = value;
        left = NULL;
        right = NULL;
    }
};

// BST Class
class BST {
public:
    Node *root;

    BST() {
        root = NULL;
    }

    bool insert(string, string);
    string search(string);
    bool update(string, string);
    bool delete_key(string);
    void display(Node *cur);
};

// Insert a node into BST
bool BST::insert(string key, string value) {
    if (root == NULL) {
        root = new Node(key, value);
        return true;
    }

    Node *temp = root, *prev = NULL;
    while (temp != NULL) {
        prev = temp;
        if (temp->key == key)
            return false;
        else if (temp->key < key)
            temp = temp->right;
        else
            temp = temp->left;
    }

    if (prev->key < key)
        prev->right = new Node(key, value);
    else
        prev->left = new Node(key, value);

    return true;
}

// Search for a node in BST
string BST::search(string key) {
    Node *temp = root;
    while (temp != NULL) {
        if (temp->key == key)
            return temp->value;
        else if (temp->key < key)
            temp = temp->right;
        else
            temp = temp->left;
    }
    return "";
}

// Update a node's value in BST
bool BST::update(string key, string value) {
    Node *temp = root;
    while (temp != NULL) {
        if (temp->key == key) {
            temp->value = value;
            return true;
        } else if (temp->key < key)
            temp = temp->right;
        else
            temp = temp->left;
    }
    return false;
}

// Delete a node from BST
bool BST::delete_key(string key) {
    Node **cur = &root;
    while (*cur != nullptr) {
        if ((*cur)->key == key) {
            Node *temp = *cur;
            if (temp->left == nullptr)
                *cur = temp->right;
            else if (temp->right == nullptr)
                *cur = temp->left;
            else {
                Node *successor = temp->right;
                while (successor->left != nullptr)
                    successor = successor->left;
                temp->key = successor->key;
                temp->value = successor->value;
                cur = &temp->right;
                key = successor->key;
                continue;
            }
            delete temp;
            return true;
        } else if ((*cur)->key < key)
            cur = &((*cur)->right);
        else
            cur = &((*cur)->left);
    }
    return false;
}

// Display BST in sorted (ascending) order
void BST::display(Node *cur) {
    if (cur == NULL)
        return;

    display(cur->left);
    cout << cur->key << " : " << cur->value << endl;
    display(cur->right);
}

// Main function
int main() {
    BST tree;
    int ch;
    string k, v, ans;

    do {
        cout << "\n--- MAIN MENU ---" << endl;
        cout << "1 - Insert" << endl;
        cout << "2 - Search" << endl;
        cout << "3 - Update" << endl;
        cout << "4 - Delete" << endl;
        cout << "5 - Display Ascending" << endl;
        cout << "0 - Exit" << endl;
        cout << "Choose an option (0-5): ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Key (word) to insert: ";
                cin >> k;
                cout << "Value (meaning): ";
                cin >> v;
                if (tree.insert(k, v))
                    cout << "Element insertion successful." << endl;
                else
                    cout << "Element already exists." << endl;
                break;

            case 2:
                cout << "Key (word) to search: ";
                cin >> k;
                ans = tree.search(k);
                if (ans == "")
                    cout << "Element does not exist." << endl;
                else
                    cout << "Value (meaning) is: " << ans << endl;
                break;

            case 3:
                cout << "Key (word) to update: ";
                cin >> k;
                cout << "New value (meaning): ";
                cin >> v;
                if (tree.update(k, v))
                    cout << "Element updated." << endl;
                else
                    cout << "Element does not exist." << endl;
                break;

            case 4:
                cout << "Key (word) to delete: ";
                cin >> k;
                if (tree.delete_key(k))
                    cout << "Element deletion successful." << endl;
                else
                    cout << "Element does not exist." << endl;
                break;

            case 5:
                cout << "Data in ascending order: " << endl;
                tree.display(tree.root);
                break;

            case 0:
                cout << "\n// END OF CODE\n";
                break;

            default:
                cout << "Please choose a valid option (0-5)." << endl;
                break;
        }
    } while (ch != 0);

    return 0;
}
