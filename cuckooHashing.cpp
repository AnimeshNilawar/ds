#include <iostream>
#include <climits>
using namespace std;

const int TABLE_SIZE = 11;        // Size of hash tables
const int MAX_DISPLACEMENTS = 20; // Max attempts before rehashing

class CuckooHash
{
    int table1[TABLE_SIZE];
    int table2[TABLE_SIZE];

    int hash1(int key)
    {
        return key % TABLE_SIZE;
    }

    int hash2(int key)
    {
        return (key / TABLE_SIZE) % TABLE_SIZE;
    }

public:
    CuckooHash()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            table1[i] = table2[i] = INT_MIN;
        }
    }

    void insert(int key)
    {
        int pos1 = hash1(key);
        if (table1[pos1] == key || table2[hash2(key)] == key)
        {
            cout << "Key " << key << " already exists.\n";
            return;
        }

        for (int attempt = 0; attempt < MAX_DISPLACEMENTS; ++attempt)
        {
            if (table1[pos1] == INT_MIN)
            {
                table1[pos1] = key;
                return;
            }

            // Kick out
            swap(key, table1[pos1]);
            int pos2 = hash2(key);

            if (table2[pos2] == INT_MIN)
            {
                table2[pos2] = key;
                return;
            }

            // Kick out
            swap(key, table2[pos2]);

            pos1 = hash1(key); // Repeat loop
        }

        cout << "Cycle detected! Rehash required for key " << key << "\n";
    }

    bool search(int key)
    {
        return (table1[hash1(key)] == key || table2[hash2(key)] == key);
    }

    void display()
    {
        cout << "\nTable 1:\n";
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            if (table1[i] == INT_MIN)
                cout << "[ ] ";
            else
                cout << "[" << table1[i] << "] ";
        }

        cout << "\nTable 2:\n";
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            if (table2[i] == INT_MIN)
                cout << "[ ] ";
            else
                cout << "[" << table2[i] << "] ";
        }
        cout << "\n";
    }
};

// Menu-driven main
int main()
{
    CuckooHash hash;
    int choice, key;

    do
    {
        cout << "\n--- Cuckoo Hashing Menu ---\n";
        cout << "1. Insert\n2. Search\n3. Display\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter key to insert: ";
            cin >> key;
            hash.insert(key);
            break;
        case 2:
            cout << "Enter key to search: ";
            cin >> key;
            if (hash.search(key))
                cout << "Key found!\n";
            else
                cout << "Key not found.\n";
            break;
        case 3:
            hash.display();
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}

/*
    Cuckoo Hashing Operations:

    Insert Operation = TC - Best: O(1), Average: O(1), Worst: O(MAX_DISPLACEMENTS)
                       SC - O(TABLE_SIZE) (for two hash tables)

    Search Operation = TC - Best: O(1), Average: O(1), Worst: O(1)
                       SC - O(1)

    Display Operation = TC - O(TABLE_SIZE)
                        SC - O(1)

    Space Complexity of Hash Table = O(TABLE_SIZE) (for two hash tables)
*/

/*
    Example 1:
    Input:
    Enter choice: 1
    Enter key to insert: 10
    Enter choice: 1
    Enter key to insert: 22
    Enter choice: 1
    Enter key to insert: 31
    Enter choice: 3

    Output:
    Table 1:
    [10] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [31]
    Table 2:
    [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [22]

    Example 2:
    Input:
    Enter choice: 2
    Enter key to search: 22

    Output:
    Key found!

    Example 3:
    Input:
    Enter choice: 2
    Enter key to search: 50

    Output:
    Key not found.

    Example 4:
    Input:
    Enter Choice: 1
    Insert: 10
    Insert: 22
    Insert: 31
    Insert: 4
    Insert: 15
    Insert: 28
    Insert: 35
    Insert: 45

    Output:
    Table 1:
    [22] [45] [35] [ ] [15] [ ] [28] [ ] [ ] [31] [10]
    Table 2:
    [4] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]


*/
