#include <iostream>
#include <vector>
using namespace std;

void hashing()
{
    vector<vector<int>> vec(13, vector<int>(2, 0));

    cout << "Enter how many numbers to store: ";
    int n;
    cin >> n;

    cout << "Enter the numbers:" << endl;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        if (vec[a % 13][0] == 0)
        {
            vec[a % 13][0] = a;
            a = 0;
        }
        else if (vec[a % 13][1] == 0)
        {
            vec[a % 13][1] = a;
            a = 0;
        }
        else
        {
            int row = a % 13 + 1;
            while (row != a % 13)
            {
                if (vec[row][0] == 0)
                {
                    vec[row][0] = a;
                    a = 0;
                    break;
                }
                else if (vec[row][1] == 0)
                {
                    vec[row][1] = a;
                    a = 0;
                    break;
                }
                row = (row + 1) % 13;
            }
        }
        if (a != 0)
        {
            cout << "Matrix Full: Cannot add more elements from here." << endl;
        }
    }

    cout << "Hash Table:" << endl;
    for (int i = 0; i < 13; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Perform Hashing\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            hashing();
            break;
        case 2:
            cout << "Exiting program.\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

/*
    Hashing Operations:

    Insert Operation = TC - Best: O(1), Average: O(1), Worst: O(n) (in case of collisions and probing)
                       SC - O(m) (where m is the size of the hash table)

    Search Operation = TC - Best: O(1), Average: O(1), Worst: O(n) (in case of collisions and probing)
                       SC - O(1)

    Space Complexity of Hash Table = O(m) (where m is the size of the hash table)
*/

/*
    Example 1:
    Input:
    Enter your choice: 1
    Enter how many numbers to store: 5
    Enter the numbers:
    13
    34
    53
    55
    23

    Output:
    Hash Table:
    13 0
    0 0
    0 0
    0 0
    0 0
    0 0
    0 0
    0 0
    0 0
    0 0
    0 0
    0 0
    34 53

    Example 2:
    Input:
    Enter your choice: 1
    Enter how many numbers to store: 3
    Enter the numbers:
    12
    25
    39

    Output:
    Hash Table:
    0 0
    0 0
    12 0
    0 0
    0 0
    0 0
    0 0
    0 0
    0 0
    0 0
    0 0
    0 0
    25 39
*/