//  Write a program to recognize C++ which converts a word of C++ program to its equivalent token. 
 
// i) Keyword ii) Identifier iii) Operator iv) Constant
 
// RESULT:
// Input: 646.45
// Output: Float
// Input: do
// Output: Keyword
// Input: 554
// Output: Integer
// Input: abe
// Output: Identifier
// Input: +
// Output: Arithmetic Operator 

#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <regex>

using namespace std;

// Function to determine if a word is a C++ keyword
bool isKeyword(const string &word) {
    const set<string> keywords = {
        "auto", "break", "case", "char", "const", "continue", "default", "do", 
        "double", "else", "enum", "extern", "float", "for", "goto", "if", 
        "inline", "int", "long", "register", "return", "short", "signed", 
        "sizeof", "static", "struct", "switch", "typedef", "union", 
        "unsigned", "void", "volatile", "while", "class", "public", "private", 
        "protected", "virtual", "friend", "namespace", "template", "try", 
        "catch", "throw", "bool", "new", "delete", "operator"
    };
    return keywords.find(word) != keywords.end();
}

// Function to determine if a token is a constant
bool isConstant(const string &token) {
    regex intRegex("^[0-9]+$");                     // Integer constant
    regex floatRegex("^[0-9]*\\.[0-9]+$");          // Float constant
    if (regex_match(token, intRegex)) {
        cout << token << " is an Integer" << endl;
        return true;
    }
    if (regex_match(token, floatRegex)) {
        cout << token << " is a Float" << endl;
        return true;
    }
    return false;
}

// Function to determine if a token is an operator
bool isOperator(const string &token) {
    const set<string> operators = {"+", "-", "*", "/", "%", "++", "--", "=", "+=", "-=", "*=", "/=", "%=", "==", "!=", ">", "<", ">=", "<=", "&&", "||", "!", "&", "|", "^", "~", "<<", ">>"};
    return operators.find(token) != operators.end();
}

// Function to determine if a token is a valid identifier
bool isIdentifier(const string &token) {
    regex identifierRegex("^[a-zA-Z_][a-zA-Z0-9_]*$"); // Identifiers start with a letter or '_'
    return regex_match(token, identifierRegex);
}

// Function to analyze a token and print its type
void analyzeToken(const string &token) {
    if (isKeyword(token)) {
        cout << token << " is a Keyword" << endl;
    } else if (isConstant(token)) {
        // Constant type is already printed in `isConstant`.
    } else if (isOperator(token)) {
        cout << token << " is an Arithmetic Operator" << endl;
    } else if (isIdentifier(token)) {
        cout << token << " is an Identifier" << endl;
    } else {
        cout << token << " is Undefined or Invalid" << endl;
    }
}

int main() {
    ifstream inputFile("input_test202.txt");
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
