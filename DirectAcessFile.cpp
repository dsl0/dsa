#include <iostream>
#include <fstream>

using namespace std;

int main() {
    cout << "\n\n ## Program to implement Random / Direct Access Files ##";

    // Writing to file
    ofstream fout;
    fout.open("One.txt", ios::out);
    
    cout << "\n Writing into the file ...";
    cout << "\n Location : " << fout.tellp();
    
    cout << "\n Line 01 : Do you know";
    fout << "Do you know" << endl;
    cout << "\n Location : " << fout.tellp();
    
    cout << "\n Line 02 : Go to Hell";
    fout << "Go to Hell" << endl;
    cout << "\n Location : " << fout.tellp();
    
    cout << "\n Line 03 : You are an idiot ";
    fout << "You are an idiot" << endl;
    cout << "\n Location : " << fout.tellp();

    fout.close();

    // Reading from file
    ifstream fin;
    fin.open("One.txt", ios::in);

    cout << "\n\n Reading from the file \n";
    cout << "\n Location : " << fin.tellg();
    
    cout << "\n Shift Control to ";
    fin.seekg(23, ios::beg);
    cout << "\n Location " << fin.tellg();
    
    cout << "\n Reading \n ";
    char c;
    while (fin.get(c)) {  // Using fin.get(c) instead of checking EOF separately
        cout << c;
    }

    cout << "\n Conclusion: We have directly accessed line 03 of this file.";

    fin.close();
    
    return 0;
}
