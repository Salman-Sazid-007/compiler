// Write a program to build a lexical analyzer implementing the following regular
// expressions. It takes a text as input from a file (e.g. input.txt) and display output in
// console mode: 
// E -> E A E | (E) | ID 
// A -> +|-|*|/ 
// ID -> any valid identifier | any valid integer

#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <stack>
using namespace std;

// Regular expression for identifiers and integers
regex validID("[a-zA-Z_][a-zA-Z0-9_]*");
regex validInt("[0-9]+");
regex validOp("[+\\-*/]");

// Function prototypes
bool parseE(stack<string>& tokens);
bool parseA(stack<string>& tokens);
bool parseID(stack<string>& tokens);

// Function to parse E -> E A E | (E) | ID
bool parseE(stack<string>& tokens) {
    if (tokens.empty()) return false;

    string current = tokens.top();
    tokens.pop();

    // Check for "(E)"
    if (current == "(") {
        if (parseE(tokens)) {
            if (!tokens.empty() && tokens.top() == ")") {
                tokens.pop();
                return true;
            }
        }
        return false;
    }

    // Check for ID
    tokens.push(current); // Put back the token
    if (parseID(tokens)) {
        if (!tokens.empty() && parseA(tokens)) {
            return parseE(tokens);
        }
        return true;
    }

    return false;
}

// Function to parse A -> + | - | * | /
bool parseA(stack<string>& tokens) {
    if (tokens.empty()) return false;

    string current = tokens.top();
    tokens.pop();

    if (regex_match(current, validOp)) {
        return true;
    }

    tokens.push(current); // Put back the token
    return false;
}

// Function to parse ID -> any valid identifier | any valid integer
bool parseID(stack<string>& tokens) {
    if (tokens.empty()) return false;

    string current = tokens.top();
    tokens.pop();

    if (regex_match(current, validID) || regex_match(current, validInt)) {
        return true;
    }

    tokens.push(current); // Put back the token
    return false;
}

int main() {
    ifstream inputFile("input_test212.txt");
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open input.txt" << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        // Tokenize the input line
        stack<string> tokens;
        string token;
        for (int i = line.size() - 1; i >= 0; --i) {
            if (isspace(line[i])) continue;
            if (line[i] == '(' || line[i] == ')') {
                tokens.push(string(1, line[i]));
            } else if (regex_match(string(1, line[i]), validOp)) {
                tokens.push(string(1, line[i]));
            } else {
                token = "";
                while (i >= 0 && !isspace(line[i]) && line[i] != '(' && line[i] != ')' && !regex_match(string(1, line[i]), validOp)) {
                    token = line[i] + token;
                    --i;
                }
                ++i; // Step back to adjust for the loop decrement
                tokens.push(token);
            }
        }

        // Parse the tokens
        if (parseE(tokens) && tokens.empty()) {
            cout << "The expression \"" << line << "\" is valid according to the grammar." << endl;
        } else {
            cout << "The expression \"" << line << "\" is invalid." << endl;
        }
    }

    inputFile.close();
    return 0;
}
