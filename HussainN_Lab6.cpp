// niaz hussain
// lab 6 – binary trees
// cst 202 – data structures

//HussainN_Lab6.cpp
#include <iostream>
#include <fstream>
#include <string>
#include "Tree.h"
using namespace std;

//check if letter
bool isLetter(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

//uppercase -> lowercase
char toLowercase(char c) {
    if (c >= 'A' && c <= 'Z') return static_cast<char>(c - 'A' + 'a');
    return c;
}

//strip trailing punctuation, validate chars, lowercase letters
bool cleanWord(string& s) {
    if (s.empty()) return false;
    const string punct = ",.!?;:\"";
    while (!s.empty() && punct.find(s.back()) != string::npos) {
        s.pop_back();
    }
    if (s.empty()) return false;
    for (auto& ch : s) {
        if (ch == '-' || ch == '\'') continue;
        if (!isLetter(ch)) return false;
        ch = toLowercase(ch);
    }
    return true;
}


int main() {
    Tree tree;
    int files = 0;
    string choice;

    //prompt user for file names and process them
    while (true) {
        cout << "\n1) enter file name to process\n";
        cout << "2) done, write analysis.txt\n";
        cout << "choice: ";
        getline(cin, choice);  //get user choice

        //check for empty input
        if (choice == "1") {
            cout << "file name: ";
            string fname;
            getline(cin, fname);  //get file name
            ifstream in(fname.c_str());
            if (!in.is_open()) {
                cout << "can't open " << fname << "\n";
                continue;
            }
            ++files;
            string token;
            //process file
            while (in >> token) {
                if (cleanWord(token)) {
                    tree.insert(token);  //insert or update word
                }
            }
            in.close();  //close file
            cout << "file processed\n";
        }
        else if (choice == "2") {
            if (files == 0) {
                cout << "no files processed, nothing to do\n";
            }
            else {
                tree.writeInOrder("analysis.txt");
                cout << "results saved to analysis.txt\n";
            }
            break;
        }
        else {
            cout << "invalid choice, try 1 or 2\n";
        }
    }
    return 0;
}
