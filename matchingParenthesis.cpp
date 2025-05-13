#include <iostream>
#include <string>
using namespace std;

class Stack
{
    int top;
    int size;
    char *arr;

public:
    Stack(int size)
    {
        this->size = size;
        arr = new char[size];
        top = -1;
    }

    ~Stack()
    {
        delete[] arr;
    }

    void push(char ch)
    {
        if (top == size - 1)
        {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = ch;
    }

    char pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow\n";
            return '\0';
        }
        return arr[top--];
    }

    char peek()
    {
        if (top == -1)
        {
            return '\0';
        }
        return arr[top];
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

bool isMatchingParenthesis(const string &expression)
{
    Stack s(expression.length());
    for (char ch : expression)
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (s.isEmpty())
            {
                return false;
            }
            char top = s.pop();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '['))
            {
                return false;
            }
        }
    }
    return s.isEmpty();
}

int main()
{
    int choice;
    string expression;

    do
    {
        cout << "1. Check Matching Parenthesis\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter an expression: ";
            cin >> expression;
            if (isMatchingParenthesis(expression))
            {
                cout << "The parenthesis are balanced.\n";
            }
            else
            {
                cout << "The parenthesis are not balanced.\n";
            }
            break;
        case 2:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 2);

    return 0;
}

/*
    Push Operation = TC - Best: O(1), Average: O(1), Worst: O(1)
                     SC - O(1)

    Pop Operation = TC - Best: O(1), Average: O(1), Worst: O(1)
                    SC - O(1)

    isEmpty Operation = TC - Best: O(1), Average: O(1), Worst: O(1)
                        SC - O(1)

    Matching Parenthesis = TC - Best: O(n), Average: O(n), Worst: O(n)
                           SC - O(n) (due to stack usage)
*/