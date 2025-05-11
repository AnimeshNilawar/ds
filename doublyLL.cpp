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
        cout << "Position is greater than the number of "
                "nodes."
             << endl;
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
