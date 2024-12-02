// Write a program to build a lexical analyzer implementing the following regular
// expressions. It takes a text as input from a file (e.g., input.txt) and display output in
// console mode:
// Integer variable = (i-nI-N)(a-zA-Z0-9)* 
// ShortInt Number = (1-9)|(1-9)(0-9)|(1-9)(0-9)(0-9)|(1-9)(0-9)(0-9)(0-9) 
// Double Number = 0.(0-9)(0-9)(0-9)+|(1-9)(0-9)*.(0-9)(0-9)(0-9)+
// Character variable =ch_(a-zA-Z0-9)(a-zA-Z0-9)* 
// Invalid Input or Undefined = Otherwise 

#include <iostream>
#include <fstream>
#include <regex>
#include <string>
using namespace std;

void analyzeToken(const string &token) {
    // Define regular expressions for each type
    regex integerVar("[i-nI-N][a-zA-Z0-9]*");
    regex shortIntNum("([1-9]|[1-9][0-9]|[1-9][0-9][0-9]|[1-9][0-9][0-9][0-9])");
    regex doubleNum("(0\\.[0-9]{3,})|([1-9][0-9]*\\.[0-9]{3,})");
    regex charVar("ch_[a-zA-Z0-9][a-zA-Z0-9]*");

    // Match the token against the patterns
    if (regex_match(token, integerVar)) {
        cout << token << " is an Integer Variable" << endl;
    } else if (regex_match(token, shortIntNum)) {
        cout << token << " is a ShortInt Number" << endl;
    } else if (regex_match(token, doubleNum)) {
        cout << token << " is a Double Number" << endl;
    } else if (regex_match(token, charVar)) {
        cout << token << " is a Character Variable" << endl;
    } else {
        cout << token << " is Invalid Input or Undefined" << endl;
    }
}

int main() {
    ifstream inputFile("input_test201.txt");
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
