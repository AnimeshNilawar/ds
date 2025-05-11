#include <iostream>
using namespace std;

class Stack
{
    int top;
    int size;
    int *arr;

public:
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        this->top = -1;
    }

    ~Stack()
    {
        delete[] arr;
    }

    void push(int n)
    {
        if (top == size - 1)
        {
            cout << "Stack is Full\n";
            return;
        }
        top++;
        arr[top] = n;
    }

    int pop()
    {
        if (top == -1)
        {
            cout << "Stack is Empty\n";
        }
        int temp = arr[top];
        top--;
        return temp;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    void printStack()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty\n";
            return;
        }

        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int size;
    cout << "Enter the size of the stack: ";
    cin >> size;

    Stack stack(size);

    int option = 0;
    while (true)
    {
        cout << "Enter option:\n"
             << "1) Push\n"
             << "2) Pop\n"
             << "3) Print Stack\n"
             << "4) Exit\n";
        cin >> option;

        if (option == 1)
        {
            int value;
            cout << "Enter value to push: ";
            cin >> value;
            stack.push(value);
        }
        else if (option == 2)
        {

            int poppedValue = stack.pop();
            cout << "Popped value: " << poppedValue << endl;
        }
        else if (option == 3)
        {
            cout << "Stack contents: ";
            stack.printStack();
        }
        else if (option == 4)
        {
            cout << "Exiting...\n";
            break;
        }
        else
        {
            cout << "Invalid option!\n";
        }
    }

    return 0;
}
