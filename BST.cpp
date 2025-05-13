#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->right = nullptr;
        this->left = nullptr;
    }
};

class BST
{
public:
    Node *root;

    BST()
    {
        root = nullptr;
    }

    Node *insert(Node *node, int val)
    {
        if (node == nullptr)
        {
            return new Node(val);
        }
        if (val < node->data)
        {
            node->left = insert(node->left, val);
        }
        else if (val > node->data)
        {
            node->right = insert(node->right, val);
        }
        return node;
    }

    Node *deleteNode(Node *node, int val)
    {
        if (node == nullptr)
        {
            return node;
        }
        if (val < node->data)
        {
            node->left = deleteNode(node->left, val);
        }
        else if (val > node->data)
        {
            node->right = deleteNode(node->right, val);
        }
        else
        {
            if (node->left == nullptr)
            {
                Node *temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr)
            {
                Node *temp = node->left;
                delete node;
                return temp;
            }
            Node *temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    Node *findMin(Node *node)
    {
        while (node->left != nullptr)
        {
            node = node->left;
        }
        return node;
    }

    void inorderRecursive(Node *node)
    {
        if (node == nullptr)
            return;
        inorderRecursive(node->left);
        cout << node->data << " ";
        inorderRecursive(node->right);
    }

    void preorderRecursive(Node *node)
    {
        if (node == nullptr)
            return;
        cout << node->data << " ";
        preorderRecursive(node->left);
        preorderRecursive(node->right);
    }

    void postorderRecursive(Node *node)
    {
        if (node == nullptr)
            return;
        postorderRecursive(node->left);
        postorderRecursive(node->right);
        cout << node->data << " ";
    }

    void inorderNonRecursive(Node *node)
    {
        stack<Node *> s;
        Node *current = node;
        while (current != nullptr || !s.empty())
        {
            while (current != nullptr)
            {
                s.push(current);
                current = current->left;
            }
            current = s.top();
            s.pop();
            cout << current->data << " ";
            current = current->right;
        }
    }

    void preorderNonRecursive(Node *node)
    {
        if (node == nullptr)
            return;
        stack<Node *> s;
        s.push(node);
        while (!s.empty())
        {
            Node *current = s.top();
            s.pop();
            cout << current->data << " ";
            if (current->right)
                s.push(current->right);
            if (current->left)
                s.push(current->left);
        }
    }

    void postorderNonRecursive(Node *node)
    {
        if (node == nullptr)
            return;
        stack<Node *> s1, s2;
        s1.push(node);
        while (!s1.empty())
        {
            Node *current = s1.top();
            s1.pop();
            s2.push(current);
            if (current->left)
                s1.push(current->left);
            if (current->right)
                s1.push(current->right);
        }
        while (!s2.empty())
        {
            cout << s2.top()->data << " ";
            s2.pop();
        }
    }

    Node *mirror(Node *node)
    {
        if (node == nullptr)
            return nullptr;
        Node *temp = node->left;
        node->left = mirror(node->right);
        node->right = mirror(temp);
        return node;
    }

    int countNodes(Node *node)
    {
        if (node == nullptr)
            return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }
};

int main()
{
    BST tree;
    int choice, value;

    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Recursive Inorder Traversal\n";
        cout << "4. Recursive Preorder Traversal\n";
        cout << "5. Recursive Postorder Traversal\n";
        cout << "6. Non-Recursive Inorder Traversal\n";
        cout << "7. Non-Recursive Preorder Traversal\n";
        cout << "8. Non-Recursive Postorder Traversal\n";
        cout << "9. Mirror Tree\n";
        cout << "10. Count Nodes\n";
        cout << "11. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            tree.root = tree.insert(tree.root, value);
            break;
        case 2:
            cout << "Enter value to delete: ";
            cin >> value;
            tree.root = tree.deleteNode(tree.root, value);
            break;
        case 3:
            cout << "Recursive Inorder Traversal: ";
            tree.inorderRecursive(tree.root);
            cout << endl;
            break;
        case 4:
            cout << "Recursive Preorder Traversal: ";
            tree.preorderRecursive(tree.root);
            cout << endl;
            break;
        case 5:
            cout << "Recursive Postorder Traversal: ";
            tree.postorderRecursive(tree.root);
            cout << endl;
            break;
        case 6:
            cout << "Non-Recursive Inorder Traversal: ";
            tree.inorderNonRecursive(tree.root);
            cout << endl;
            break;
        case 7:
            cout << "Non-Recursive Preorder Traversal: ";
            tree.preorderNonRecursive(tree.root);
            cout << endl;
            break;
        case 8:
            cout << "Non-Recursive Postorder Traversal: ";
            tree.postorderNonRecursive(tree.root);
            cout << endl;
            break;
        case 9:
            tree.root = tree.mirror(tree.root);
            cout << "Tree mirrored.\n";
            break;
        case 10:
            cout << "Number of nodes: " << tree.countNodes(tree.root) << endl;
            break;
        case 11:
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

/*
    Binary Search Tree (BST) Operations:

    Insert Operation = TC - Best: O(log n), Average: O(log n), Worst: O(n)
                       SC - O(log n) (due to recursion stack)

    Delete Operation = TC - Best: O(log n), Average: O(log n), Worst: O(n)
                       SC - O(log n) (due to recursion stack)

    Traversals (Recursive) = TC - Best: O(n), Average: O(n), Worst: O(n)
                             SC - O(h) (where h is the height of the tree)

    Traversals (Non-Recursive) = TC - Best: O(n), Average: O(n), Worst: O(n)
                                 SC - O(h) (due to stack usage)

    Mirror Tree = TC - Best: O(n), Average: O(n), Worst: O(n)
                  SC - O(h) (due to recursion stack)

    Count Nodes = TC - Best: O(n), Average: O(n), Worst: O(n)
                  SC - O(h) (due to recursion stack)
*/

/*
    Example 1:
    Input:
    Enter value to insert: 50
    Enter value to insert: 30
    Enter value to insert: 70
    Enter value to insert: 20
    Enter value to insert: 40
    Enter value to insert: 60
    Enter value to insert: 80
    Recursive Inorder Traversal: 20 30 40 50 60 70 80

    Example 2:
    Input:
    Enter value to delete: 50
    Recursive Inorder Traversal: 20 30 40 60 70 80

    Example 3:
    Input:
    Mirror Tree
    Recursive Inorder Traversal: 80 70 60 40 30 20
*/