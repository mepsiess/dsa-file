/* 4. Implement Stack as an ADT and use it to evaluate a prefix/postfix expression */


#include <iostream>
#include <cstring>
using namespace std;

class Stack {
private:
    int top;
    int arr[100];

public:
    Stack() {
        top = -1;
    }

    bool isFull() {
        return top == 99;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow!\n";
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!\n";
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (!isEmpty())
            return arr[top];
        return -1;
    }
};

// Function to perform operation
int operate(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0;
    }
}

// POSTFIX EVALUATION
int evaluatePostfix(string exp) {
    Stack s;

    for (int i = 0; i < exp.length(); i++) {

        if (isdigit(exp[i])) {
            s.push(exp[i] - '0');
        }
        else {
            int b = s.pop();
            int a = s.pop();
            int result = operate(a, b, exp[i]);
            s.push(result);
        }
    }
    return s.pop();
}

// PREFIX EVALUATION
int evaluatePrefix(string exp) {
    Stack s;

    for (int i = exp.length() - 1; i >= 0; i--) {

        if (isdigit(exp[i])) {
            s.push(exp[i] - '0');
        }
        else {
            int a = s.pop();
            int b = s.pop();
            int result = operate(a, b, exp[i]);
            s.push(result);
        }
    }
    return s.pop();
}

int main() {
    int choice;
    string exp;

    while (true) {
        cout << "\n--- STACK ADT MENU ---\n";
        cout << "1. Evaluate Postfix Expression\n";
        cout << "2. Evaluate Prefix Expression\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter postfix expression: ";
                cin >> exp;
                cout << "Result = " << evaluatePostfix(exp) << endl;
                break;

            case 2:
                cout << "Enter prefix expression: ";
                cin >> exp;
                cout << "Result = " << evaluatePrefix(exp) << endl;
                break;

            case 3:
            cout << "Exiting . . .";
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }
}
