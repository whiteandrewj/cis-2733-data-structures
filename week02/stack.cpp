#include <iostream>
#include <stack>

using namespace std;

bool isOp(char c) {
    if (c == '+' || c == '-' || c == '/' || c == '*' || c == '^') {
        return true;
    }
    return false;
}
bool isNum(char c) {
    if (c == 0 || c == 1 || c == 2 || c == 3 || c == 4 || c == 5
    || c == 6 || c == 7 || c ==  8 || c == 9) {
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

int main()
{
    stack<int> precedence;
    string expression = "5 1 2 3 + * -";
    string expression2 = "5 2 3 + 1 * -";
    int leftOperand, rightOperand, result;

    string element = "";

    for (int i = 0; i < expression.size(); i++) {
        if (isNum(expression[i])) {
            element += i;
        } else if (isDelim(expression[i])) {
            precedence.push(stoi(element));
            element = "";
        } else if (isOp(expression[i])) {
            rightOperand = precedence.top();
            precedence.pop();
            leftOperand = precedence.top();
            precedence.pop();
            result = (leftOperand expression[i] rightOperand);
            precedence.push(result);
        } else {
            cout << "incorrectly formated expression";
        }
    }
    return 0;
}