#include <iostream>
using namespace std;

#define MAX_SIZE 5

class Queue {
public:
    int front, rear;
    int arr[MAX_SIZE];

    Queue() { front = rear = 0; }

    bool isEmpty() {
        return front == rear;
    }

    bool isFull() {
        return (rear + 1) % MAX_SIZE == front;
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue Overflow!\n";
            return;
        }
        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = val;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!\n";
            return;
        }
        front = (front + 1) % MAX_SIZE;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is Empty!\n";
            return -1;
        }
        return arr[(front + 1) % MAX_SIZE];
    }

    void print() {
        if (isEmpty()) {
            cout << "Queue is Empty!\n";
            return;
        }
        for (int i = (front + 1) % MAX_SIZE; i != rear; i = (i + 1) % MAX_SIZE) {
            cout << arr[i] << " ";
        }
        cout << arr[rear] << endl;
    }
};

int main() {
    Queue q;
    int option = 0;

    while (true) {
        cout << "Enter option:\n"
             << "1) Enqueue\n"
             << "2) Dequeue\n"
             << "3) Peek\n"
             << "4) Print Queue\n"
             << "5) Exit\n";
        cin >> option;

        if (option == 1) {
            int value;
            cout << "Enter value to enqueue: ";
            cin >> value;
            q.enqueue(value);
        } else if (option == 2) {
            q.dequeue();
        } else if (option == 3) {
            int frontValue = q.peek();
            if (frontValue != -1) {
                cout << "Front value: " << frontValue << endl;
            }
        } else if (option == 4) {
            cout << "Queue contents: ";
            q.print();
        } else if (option == 5) {
            cout << "Exiting...\n";
            break;
        } else {
            cout << "Invalid option!\n";
        }
    }

    return 0;
}

/*
    Circular Queue Operations:

    Enqueue Operation = TC - Best: O(1), Average: O(1), Worst: O(1)
                        SC - O(1)

    Dequeue Operation = TC - Best: O(1), Average: O(1), Worst: O(1)
                        SC - O(1)

    Peek Operation = TC - Best: O(1), Average: O(1), Worst: O(1)
                     SC - O(1)

    Print Operation = TC - Best: O(n), Average: O(n), Worst: O(n)
                      SC - O(1)

    Space Complexity of Queue = O(MAX_SIZE)
*/

/*
    Example 1:
    Input:
    Enter option:
    1) Enqueue
    2) Dequeue
    3) Peek
    4) Print Queue
    5) Exit
    1
    Enter value to enqueue: 10
    1
    Enter value to enqueue: 20
    1
    Enter value to enqueue: 30
    4

    Output:
    Queue contents: 10 20 30

    Example 2:
    Input:
    Enter option:
    1) Enqueue
    2) Dequeue
    3) Peek
    4) Print Queue
    5) Exit
    2
    3

    Output:
    Front value: 20
*/