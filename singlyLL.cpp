#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
     
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

void insertAtHead(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void insertAtTail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtPos(Node *&head, int val, int pos)
{
    if (pos == 0)
    {
        insertAtHead(head, val);
        return;
    }
    Node *newNode = new Node(val);
    Node *temp = head;
    for (int i = 0; i < pos - 1 && temp != nullptr; i++)
    {
        temp = temp->next;
    }
    if (temp == nullptr)
    {
        cout << "Position out of bounds" << endl;
        delete newNode;
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtPos(Node *&head, int pos)
{
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }
    if (pos == 0)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node *temp = head;
    for (int i = 0; i < pos - 1 && temp->next != nullptr; i++)
    {
        temp = temp->next;
    }
    if (temp->next == nullptr)
    {
        cout << "Position out of bounds" << endl;
        return;
    }
    Node *nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
}

void display(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void deleteList(Node *&head)
{
    Node *temp;
    while (head != nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    Node *head = nullptr;
    int choice, value, position;

    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Insert at Head\n";
        cout << "2. Insert at Tail\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete at Position\n";
        cout << "5. Display List\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert at head: ";
            cin >> value;
            insertAtHead(head, value);
            break;
        case 2:
            cout << "Enter value to insert at tail: ";
            cin >> value;
            insertAtTail(head, value);
            break;
        case 3:
            cout << "Enter value to insert: ";
            cin >> value;
            cout << "Enter position to insert: ";
            cin >> position;
            insertAtPos(head, value, position);
            break;
        case 4:
            cout << "Enter position to delete: ";
            cin >> position;
            deleteAtPos(head, position);
            break;
        case 5:
            display(head);
            break;
        case 6:
            deleteList(head);
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
