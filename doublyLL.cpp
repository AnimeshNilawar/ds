#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

void insert(Node *&head, int data)
{
    Node *newNode = new Node(data);

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
    newNode->prev = temp;
}

void deleteAtBeginning(Node *&head)
{
    if (head == nullptr)
    {
        cout << "The list is already empty." << endl;
        return;
    }

    Node *temp = head;
    head = head->next;
    if (head != nullptr)
    {
        head->prev = nullptr;
    }
    delete temp;
}

void deleteAtPosition(Node *&head, int position)
{
    if (head == nullptr)
    {
        cout << "The list is already empty." << endl;
        return;
    }

    if (position == 1)
    {
        deleteAtBeginning(head);
        return;
    }

    Node *temp = head;
    for (int i = 1; temp != nullptr && i < position; i++)
    {
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cout << "Position is greater than the number of nodes." << endl;
        return;
    }

    if (temp->next != nullptr)
    {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != nullptr)
    {
        temp->prev->next = temp->next;
    }
    delete temp;
}

void printList(Node *head)
{
    Node *temp = head;
    cout << "Forward List: ";
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void findEvenNodes(Node *head)
{
    Node *temp = head;
    cout << "Nodes with even numbers: ";
    while (temp != nullptr)
    {
        if (temp->data % 2 == 0)
        {
            cout << temp->data << " ";
        }
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = nullptr;
    int option = 0;

    while (true)
    {
        cout << "Enter option:\n"
             << "1) Insert Node\n"
             << "2) Delete Node at Position\n"
             << "3) Print List\n"
             << "4) Find Even Nodes\n"
             << "5) Exit\n";
        cin >> option;

        if (option == 1)
        {
            int value;
            cout << "Enter value to insert: ";
            cin >> value;
            insert(head, value);
        }
        else if (option == 2)
        {
            int position;
            cout << "Enter position to delete: ";
            cin >> position;
            deleteAtPosition(head, position);
        }
        else if (option == 3)
        {
            printList(head);
        }
        else if (option == 4)
        {
            findEvenNodes(head);
        }
        else if (option == 5)
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

/*
    Doubly Linked List Operations:

    Insert Operation = TC - Best: O(1) (inserting at the beginning),
                             Average: O(n), Worst: O(n) (inserting at the end)
                      SC - O(1)

    Delete Operation = TC - Best: O(1) (deleting the first node),
                             Average: O(n), Worst: O(n) (deleting at a specific position)
                      SC - O(1)

    Print Operation = TC - Best: O(n), Average: O(n), Worst: O(n)
                      SC - O(1)

    Find Even Nodes = TC - Best: O(n), Average: O(n), Worst: O(n)
                      SC - O(1)
*/

/*
    Example 1:
    Input:
    Enter option:
    1) Insert Node
    2) Delete Node at Position
    3) Print List
    4) Find Even Nodes
    5) Exit
    1
    Enter value to insert: 10
    1
    Enter value to insert: 20
    1
    Enter value to insert: 15
    3

    Output:
    Forward List: 10 20 15

    Example 2:
    Input:
    Enter option:
    4

    Output:
    Nodes with even numbers: 10 20

    Example 3:
    Input:
    Enter option:
    2
    Enter position to delete: 2
    3

    Output:
    Forward List: 10 15
*/
