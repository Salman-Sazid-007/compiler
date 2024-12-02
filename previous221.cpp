// Write a program to build a lexical analyzer implementing the following regular
// expressions. It takes a text as input from a file (e.g., input.txt) and display output in
// console mode:
// Integer variable = (i-n|I-N)(a-z|A-Z|_|0-9)* 
// ShortInt Number = (1-9)|(1-9)(0-9)|(1-9)(0-9)(0-9)|(1-9)(0-9)(0-9)(0-9)
// LongInt Number = (1-9)(0-9)(0-9)(0-9)(0-9)+
// Constant Integer = (1)*|(2)*...|(9)*
// Keyword = 1|12|123...|123456789

// Invalid Input or Undefined = Otherwise 

#include <iostream>
#include <fstream>
#include <regex>
#include <string>

using namespace std;

// Function to determine if a token is an Integer Variable
bool isIntegerVariable(const string& token) {
    regex intVarRegex("[i-nI-N][a-zA-Z0-9_]*");
    return regex_match(token, intVarRegex);
}

// Function to determine if a token is a ShortInt Number
bool isShortIntNumber(const string& token) {
    regex shortIntRegex("([1-9]|[1-9][0-9]|[1-9][0-9]{2}|[1-9][0-9]{3})");
    return regex_match(token, shortIntRegex);
}

// Function to determine if a token is a LongInt Number
bool isLongIntNumber(const string& token) {
    regex longIntRegex("[1-9][0-9]{4,}");
    return regex_match(token, longIntRegex);
}

// Function to determine if a token is a Constant Integer
bool isConstantInteger(const string& token) {
    regex constantIntRegex("^[1-9]+$"); // Matches numbers with repeated digits from 1 to 9 (e.g., 111, 222).
    return regex_match(token, constantIntRegex);
}

// Function to determine if a token is a Keyword
bool isKeyword(const string& token) {
    regex keywordRegex("^(1|12|123|1234|12345|123456|1234567|12345678|123456789)$");
    return regex_match(token, keywordRegex);
}

// Function to analyze a token and classify it
void analyzeToken(const string& token) {
    if (isIntegerVariable(token)) {
        cout << token << " is an Integer Variable" << endl;
    } else if (isShortIntNumber(token)) {
        cout << token << " is a ShortInt Number" << endl;
    } else if (isLongIntNumber(token)) {
        cout << token << " is a LongInt Number" << endl;
    } else if (isConstantInteger(token)) {
        cout << token << " is a Constant Integer" << endl;
    } else if (isKeyword(token)) {
        cout << token << " is a Keyword" << endl;
    } else {
        cout << token << " is Invalid Input or Undefined" << endl;
    }
}

int main() {
    ifstream inputFile("input_test221.txt");
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
