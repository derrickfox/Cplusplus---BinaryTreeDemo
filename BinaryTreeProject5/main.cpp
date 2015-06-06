#include "Tree.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
    ofstream outFile;
    outFile.open("Output.txt");
    
    ifstream inFile;
    inFile.open("Input.txt");
    
    Tree myTree;
    int answer = 1;
    
    string title;
    string author;
    int ID = 0;
    int year = 0;
    
    while (!inFile.eof())
    {
        inFile >> title >> author >> ID >> year;
        //cout << title << " " << author << " " << ID << "  " << year << endl;
        myTree.addLeaf(title, author, ID, year);
        //outFile << title << " " << author << " " << ID << "  " << year << endl;
    }
    
    cout << "Welcome to the library system!" << endl;
    cout << "Press 1 to Search or Press 0 to Exit" << endl;
    cin >> answer;
    while (answer != 0) {
        cout << "\nWhat is the year of the book you would like to search for?" << endl;
        cin >> year;
        myTree.search(myTree.root, year);
        cout << "Press 1 to Search or Press 0 to Exit" << endl;
        cin >> answer;
    }
    return 0;
}