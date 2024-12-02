// Write a program to build a lexical analyzer implementing the following regular
// expressions. It takes a text as input from a file (e.g., input.txt) and display output in
// console mode:
// Character variable =ch_(a-zA-Z0-9)(a-zA-Z0-9)* 
// Integer variable = (i-nI-N)_(a-zA-Z0-9)(a-zA-Z0-9)* 
// Binary Number = 0(0]1)(0[1)* 
// Integer Number = (1-9)(1-9)*


// Invalid Input or Undefined = Otherwise 

#include <iostream>
#include <fstream>
#include <regex>
#include <string>
using namespace std;

void analyzeToken(const string &token) {
    // Define regular expressions for each type
    regex characterVar("ch_[a-zA-Z0-9][a-zA-Z0-9]*");
    regex integerVar("[i-nI-N]_[a-zA-Z0-9][a-zA-Z0-9]*");
    regex binaryNum("0[01][01]*");
    regex integerNum("[1-9][0-9]*");

    // Match the token against the patterns
    if (regex_match(token, characterVar)) {
        cout << token << " is a Character Variable" << endl;
    } else if (regex_match(token, integerVar)) {
        cout << token << " is an Integer Variable" << endl;
    } else if (regex_match(token, binaryNum)) {
        cout << token << " is a Binary Number" << endl;
    } else if (regex_match(token, integerNum)) {
        cout << token << " is an Integer Number" << endl;
    } else {
        cout << token << " is Invalid Input or Undefined" << endl;
    }
}

int main() {
    ifstream inputFile("input_test211.txt");
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open input.txt" << endl;
        return 1;
    }

    string token;
    while (inputFile >> token) {
        analyzeToken(token);
    }

    inputFile.close();
    return 0;
}
