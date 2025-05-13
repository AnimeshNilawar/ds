#include <iostream>
#include <cstring>
using namespace std;

class Stack
{
    char *arr;
    int top;
    int size;

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

    void push(char c)
    {
        if (top == size - 1)
            return;
        arr[++top] = c;
    }

    char pop()
    {
        if (top == -1)
            return '\0';
        return arr[top--];
    }

    char peek()
    {
        if (top == -1)
            return '\0';
        return arr[top];
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

int precedence(char c)
{
    if (c == '^')
        return 3;
    if (c == '/' || c == '*')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return -1;
}

void infixToPostfix(char *s)
{
    int n = strlen(s);
    Stack st(n);
    char *result = new char[n + 1];
    int k = 0;

    for (int i = 0; i < n; i++)
    {
        char c = s[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result[k++] = c;

        else if (c == '(')
            st.push(c);

        else if (c == ')')
        {
            while (st.peek() != '(')
                result[k++] = st.pop();
            st.pop();
        }
        else
        {
            while (!st.isEmpty() && precedence(c) <= precedence(st.peek()))
                result[k++] = st.pop();
            st.push(c);
        }
    }

    while (!st.isEmpty())
        result[k++] = st.pop();

    result[k] = '\0';
    cout << "Postfix Expression: " << result << endl;
    delete[] result;
}

int main()
{
    int choice;
    char exp[100];

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Convert Infix to Postfix\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter infix expression: ";
            cin >> exp;
            infixToPostfix(exp);
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
    Infix to Postfix Conversion = TC - Best: O(n), Average: O(n), Worst: O(n)
                                  SC - O(n) (due to stack and result array)

    INPUT - a+b*(c^d-e)^(f+g*h)-i
*/
