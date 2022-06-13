#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

bool isOper(char c) {
    if (c == '+' || c == '-' || c == '/' || c == '*' || c == '^') {
        return true;
    }
    return false;
}
bool isNum(char c) {
    if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5'
    || c == '6' || c == '7' || c ==  '8' || c == '9') {
        return true;    
    }
    return false;
}
bool isDelim(char c) {
    if (c == ' ') {
        return true;
    }
    return false;
}
double evalExpr(double lOperand, double rOperand, char arithOper) {
    double result;
    switch (arithOper) {
        case '+' : 
            result = lOperand + rOperand;
            break;
        case '-' : 
            result = lOperand - rOperand;
            break;
        case '/' : 
            result = lOperand / rOperand;
            break;
        case '*' : 
            result = lOperand * rOperand;
            break;
        case '^' : 
            result = pow(lOperand, rOperand);
            break;
    }
    return result;
}

string reverseString(string word) {
    stack<char> letters;
    string rword = "";
    for (char l : word) {
        letters.push(l);
    }
    while (!letters.empty()) {
        rword.push_back(letters.top());
        letters.pop();
    }
    return rword;
}

int main()
{
    //Assignment #1, postfix expression evaluation` '
    stack<double> precedence;
    string expression; // = "4 19 2 30 + 2 / - ^";
    string element = "";
    int leftOperand, rightOperand;

    cout << "Please enter a space-delimited expression in postfix notation, e.g." << endl
         << "4 19 2 30 + 2 / - ^" << endl;
    getline(std::cin,expression);

    for (int i = 0; i < expression.size(); i++) {
        cout << "char #" << i+1 << " of expression: " << expression[i] << endl;
        if (isNum(expression[i])) {
            element += expression[i];
            cout << "element now equals: " << element << endl;
        } else if (isDelim(expression[i])) {
            if (!(element == "")) {
                cout << "pushing " << element << " onto the stack..." << endl;
                precedence.push(stod(element));
                element = "";
            }
        } else if (isOper(expression[i])) {
            cout << "evaluating expression and pushing result onto the stack..." << endl;
            rightOperand = precedence.top();
            precedence.pop();
            leftOperand = precedence.top();
            precedence.pop();
            precedence.push(evalExpr(leftOperand, rightOperand, expression[i]));
            cout << "left operand: " << leftOperand << ", right operand: " << rightOperand
                 << ", operator: " << expression[i] << ", result: " 
                 << evalExpr(leftOperand, rightOperand, expression[i]) << endl;
        } else {
            cout << "incorrectly formated expression" << endl;
        }
    }
    cout << "----Final Result----" << endl << precedence.top() << endl << endl;




    //Assignment #2, revese word
    stack<char> letters;
    string word;
    cout << "Please enter a word: ";
    cin >> word;
    cout << "Reversed word: " << reverseString(word) << endl;



    return 0;
}