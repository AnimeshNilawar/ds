#include <iostream>
#include <string>

using namespace std;

// Custom stack class
class Stack {
private:
    string* arr;
    int top;
    int capacity;

public:
    Stack(int size = 100) {
        arr = new string[size];
        capacity = size;
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(string val) {
        if (top >= capacity - 1) {
            cout << "Stack overflow!\n";
            return;
        }
        arr[++top] = val;
    }

    string pop() {
        if (isEmpty()) {
            cout << "Stack underflow!\n";
            return "";
        }
        return arr[top--];
    }

    string peek() {
        if (isEmpty()) {
            return "";
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    int size() {
        return top + 1;
    }
};

// Utility function to check if a character is an operator
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

// Postfix to Infix Conversion
string postfixToInfix(const string& postfix) {
    Stack s;

    for (char ch : postfix) {
        if (isspace(ch)) continue;

        if (isalnum(ch)) {
            s.push(string(1, ch));
        } else if (isOperator(ch)) {
            if (s.size() < 2) {
                return "Error: Invalid postfix expression!";
            }
            string op2 = s.pop();
            string op1 = s.pop();
            string expr = "(" + op1 + ch + op2 + ")";
            s.push(expr);
        } else {
            return "Error: Invalid character in expression!";
        }
    }

    if (s.size() != 1) {
        return "Error: Invalid postfix expression!";
    }

    return s.pop();
}

// Menu-driven main function
int main() {
    int choice;
    string postfix;

    do {
        cout << "\n==== Postfix to Infix Converter ====\n";
        cout << "1. Convert Postfix to Infix\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore leftover newline

        switch (choice) {
            case 1:
                cout << "Enter postfix expression (single-character operands): ";
                getline(cin, postfix);
                cout << "Infix expression: " << postfixToInfix(postfix) << endl;
                break;
            case 2:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 2);

    return 0;
}

/*
    Postfix to Infix Conversion = TC - Best: O(n), Average: O(n), Worst: O(n)
                                  SC - O(n) (due to stack usage)

    INPUT = abc+*d/
            ab+c*
*/
