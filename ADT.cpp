#include <iostream>
using namespace std;

class ADTSet {
public:
    // Method to add an element to the set
    void Add_element(int val, int Set[], int &size) {
        // Check if the element already exists to avoid duplicates
        for (int i = 0; i < size; i++) {
            if (Set[i] == val) {
                cout << val << " already exists in the set!" << endl;
                return;
            }
        }
        // Add the new element to the set
        Set[size] = val;
        size++;
        cout << val << " is added to the set." << endl;
    }

    // Method to remove an element from the set
    void Delete_element(int val, int Set[], int &size) {
        int i, pos = -1;
        // Search for the element in the set
        for (i = 0; i < size; i++) {
            if (Set[i] == val) {
                pos = i;
                break;
            }
        }
        if (pos == -1) {
            cout << val << " not found in the set!" << endl;
            return;
        }
        // Remove the element by shifting all elements after it one position to the left
        for (i = pos; i < size - 1; i++) {
            Set[i] = Set[i + 1];
        }
        size--;
        cout << val << " is deleted from the set." << endl;
    }

    // Method to check if an element is contained in the set
    void Is_contain(int val, int Set[], int size) {
        for (int i = 0; i < size; i++) {
            if (Set[i] == val) {
                cout << val << " is contained in the set." << endl;
                return;
            }
        }
        cout << val << " is not contained in the set." << endl;
    }

    // Method to get the size of the set
    void Size_of_set(int size) {
        cout << "The size of the set is: " << size << endl;
    }

    // Method to perform the union of two sets
    void Union(int SetA[], int sizeA, int SetB[], int sizeB) {
        int result[100], resSize = 0;

        // Add all elements of SetA to result
        for (int i = 0; i < sizeA; i++) {
            result[resSize++] = SetA[i];
        }

        // Add only the elements of SetB that are not in SetA
        for (int i = 0; i < sizeB; i++) {
            bool isDuplicate = false;
            for (int j = 0; j < sizeA; j++) {
                if (SetB[i] == SetA[j]) {
                    isDuplicate = true;
                    break;
                }
            }
            if (!isDuplicate) {
                result[resSize++] = SetB[i];
            }
        }

        cout << "Union of the sets is: ";
        for (int i = 0; i < resSize; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }

    // Method to perform the intersection of two sets
    void Intersection(int SetA[], int sizeA, int SetB[], int sizeB) {
        int result[100], resSize = 0;

        for (int i = 0; i < sizeA; i++) {
            for (int j = 0; j < sizeB; j++) {
                if (SetA[i] == SetB[j]) {
                    result[resSize++] = SetA[i];
                    break;
                }
            }
        }

        cout << "Intersection of the sets is: ";
        for (int i = 0; i < resSize; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }

    // Method to perform the difference of two sets
    void Difference(int SetA[], int sizeA, int SetB[], int sizeB) {
        int result[100], resSize = 0;

        // Add elements of SetA that are not in SetB
        for (int i = 0; i < sizeA; i++) {
            bool isInB = false;
            for (int j = 0; j < sizeB; j++) {
                if (SetA[i] == SetB[j]) {
                    isInB = true;
                    break;
                }
            }
            if (!isInB) {
                result[resSize++] = SetA[i];
            }
        }

        cout << "Difference of the sets is: ";
        for (int i = 0; i < resSize; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }

    // Method to check if SetA is a subset of SetB
    void Is_subset(int SetA[], int sizeA, int SetB[], int sizeB) {
        for (int i = 0; i < sizeA; i++) {
            bool isFound = false;
            for (int j = 0; j < sizeB; j++) {
                if (SetA[i] == SetB[j]) {
                    isFound = true;
                    break;
                }
            }
            if (!isFound) {
                cout << "Set A is not a subset of Set B" << endl;
                return;
            }
        }
        cout << "Set A is a subset of Set B" << endl;
    }

private:
    void print_set(int Set[], int size) {
        for (int i = 0; i < size; i++) {
            cout << Set[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int a[100] = {11, 25, 39, 14, 5}; // Set A
    int b[100] = {39, 14, 5, 62, 78}; // Set B
    int sizeA = 5, sizeB = 5; // Current size of Set A and Set B

    ADTSet obj;
    int choice, element, set_choice;

    while (true) {
        cout << "\nSelect operation to perform:" << endl;
        cout << "1. Add\n2. Remove\n3. Contain\n4. Size\n5. Intersection\n6. Union\n7. Difference\n8. Subset\n9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the set to add the element:\n1) Set A\n2) Set B\nEnter your choice: ";
                cin >> set_choice;
                cout << "Enter the element to add: ";
                cin >> element;
                if (set_choice == 1) {
                    obj.Add_element(element, a, sizeA);
                } else if (set_choice == 2) {
                    obj.Add_element(element, b, sizeB);
                }
                break;

            case 2:
                cout << "Enter the set to delete the element:\n1) Set A\n2) Set B\nEnter your choice: ";
                cin >> set_choice;
                cout << "Enter the element to delete: ";
                cin >> element;
                if (set_choice == 1) {
                    obj.Delete_element(element, a, sizeA);
                } else if (set_choice == 2) {
                    obj.Delete_element(element, b, sizeB);
                }
                break;

            case 3:
                cout << "Enter the set to check the element:\n1) Set A\n2) Set B\nEnter your choice: ";
                cin >> set_choice;
                cout << "Enter the element to check: ";
                cin >> element;
                if (set_choice == 1) {
                    obj.Is_contain(element, a, sizeA);
                } else if (set_choice == 2) {
                    obj.Is_contain(element, b, sizeB);
                }
                break;

            case 4:
                cout << "Enter the set to check size:\n1) Set A\n2) Set B\nEnter your choice: ";
                cin >> set_choice;
                if (set_choice == 1) {
                    obj.Size_of_set(sizeA);
                } else if (set_choice == 2) {
                    obj.Size_of_set(sizeB);
                }
                break;

            case 5:
                obj.Intersection(a, sizeA, b, sizeB);
                break;

            case 6:
                obj.Union(a, sizeA, b, sizeB);
                break;

            case 7:
                obj.Difference(a, sizeA, b, sizeB);
                break;

            case 8:
                obj.Is_subset(a, sizeA, b, sizeB);
                break;

            case 9:
                return 0;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    return 0;
}
