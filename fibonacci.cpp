#include <iostream>
using namespace std;

int fibonacciRecursive(int n) {
    if (n <= 1)
        return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

void fibonacciIterative(int n) {
    int a = 0, b = 1;
    cout << "Fibonacci Series (Iterative): ";
    for (int i = 0; i < n; i++) {
        cout << a << " ";
        int next = a + b;
        a = b;
        b = next;
    }
    cout << endl;
}

void printFibonacciRecursive(int n) {
    cout << "Fibonacci Series (Recursive): ";
    for (int i = 0; i < n; i++) {
        cout << fibonacciRecursive(i) << " ";
    }
    cout << endl;
}

int main() {
    int choice, n;

    do {
        cout << "1. Print using Recursion\n";
        cout << "2. Print without Recursion\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter number of terms: ";
            cin >> n;
            printFibonacciRecursive(n);
            break;

        case 2:
            cout << "Enter number of terms: ";
            cin >> n;
            fibonacciIterative(n);
            break;

        case 3:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 3);

    return 0;
}

/*
    Fibonacci Recursive = TC - Best: O(2^n), Average: O(2^n), Worst: O(2^n)
                          SC - O(n) (due to recursion stack)

    Fibonacci Iterative = TC - Best: O(n), Average: O(n), Worst: O(n)
                          SC - O(1)

    Print Fibonacci Recursive = TC - Best: O(n * 2^n), Average: O(n * 2^n), Worst: O(n * 2^n)
                                SC - O(n) (due to recursion stack)

    Print Fibonacci Iterative = TC - Best: O(n), Average: O(n), Worst: O(n)
                                SC - O(1)
*/