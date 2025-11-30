/* 6. Write a program to implement Binary Search Tree as an ADT which supports the following operations:
i. Insert an element x
ii. Delete an element x
iii. Search for an element x in the BST 
iv. Display the elements of the BST in preorder, inorder, and postorder traversal */


#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = NULL;
    }

    // Insert
    Node* insert(Node* node, int x) {
        if (node == NULL)
            return new Node(x);

        if (x < node->data)
            node->left = insert(node->left, x);
        else if (x > node->data)
            node->right = insert(node->right, x);

        return node;
    }

    // Search
    Node* search(Node* node, int x) {
        if (node == NULL || node->data == x)
            return node;

        if (x < node->data)
            return search(node->left, x);

        return search(node->right, x);
    }

    // Find minimum value (used in deletion)
    Node* findMin(Node* node) {
        while (node && node->left != NULL)
            node = node->left;
        return node;
    }

    // Delete
    Node* deleteNode(Node* node, int x) {
        if (node == NULL) return node;

        if (x < node->data)
            node->left = deleteNode(node->left, x);

        else if (x > node->data)
            node->right = deleteNode(node->right, x);

        else {
            // Case 1: No child
            if (node->left == NULL && node->right == NULL) {
                delete node;
                return NULL;
            }
            // Case 2: One child
            else if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            // Case 3: Two children
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    // Traversals
    void inorder(Node* node) {
        if (node == NULL) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void preorder(Node* node) {
        if (node == NULL) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node* node) {
        if (node == NULL) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }
};

int main() {
    BST tree;
    int choice, x;

    while (true) {
        cout << "\n--- BST ADT MENU ---\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Inorder Traversal\n";
        cout << "5. Preorder Traversal\n";
        cout << "6. Postorder Traversal\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> x;
                tree.root = tree.insert(tree.root, x);
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> x;
                tree.root = tree.deleteNode(tree.root, x);
                break;

            case 3:
                cout << "Enter value to search: ";
                cin >> x;
                {
                    Node* result = tree.search(tree.root, x);
                    if (result)
                        cout << "Element found at address: " << result << endl;
                    else
                        cout << "Element not found!" << endl;
                }
                break;

            case 4:
                cout << "Inorder: ";
                tree.inorder(tree.root);
                cout << endl;
                break;

            case 5:
                cout << "Preorder: ";
                tree.preorder(tree.root);
                cout << endl;
                break;

            case 6:
                cout << "Postorder: ";
                tree.postorder(tree.root);
                cout << endl;
                break;

            case 7:
                cout << "Exiting . . .";
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }
}
