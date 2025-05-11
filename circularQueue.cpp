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
