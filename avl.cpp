#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int x) {
        data = x;
        left = right = NULL;
        height = 1;
    }
};

class AVL {
public:
    Node* root;

    AVL() {
        root = NULL;
    }

    // Get height of node
    int getHeight(Node* n) {
        if (n == NULL) return 0;
        return n->height;
    }

    // Get balance factor
    int getBalance(Node* n) {
        if (n == NULL) return 0;
        return getHeight(n->left) - getHeight(n->right);
    }

    // Right rotation (RR)
    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    // Left rotation (LL)
    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    // Insert into AVL
    Node* insert(Node* node, int key) {
        if (node == NULL)
            return new Node(key);

        // BST insert
        if (key < node->data)
            node->left = insert(node->left, key);
        else if (key > node->data)
            node->right = insert(node->right, key);
        else
            return node;  // No duplicates

        // Update height
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        // Get balance
        int balance = getBalance(node);

        // FOUR ROTATION CASES

        // Left Left (LL)
        if (balance > 1 && key < node->left->data)
            return rotateRight(node);

        // Right Right (RR)
        if (balance < -1 && key > node->right->data)
            return rotateLeft(node);

        // Left Right (LR)
        if (balance > 1 && key > node->left->data) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // Right Left (RL)
        if (balance < -1 && key < node->right->data) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    // Search in AVL
    Node* search(Node* node, int key) {
        if (node == NULL || node->data == key)
            return node;

        if (key < node->data)
            return search(node->left, key);
        else
            return search(node->right, key);
    }

    // inorder (to verify balancing)
    void inorder(Node* node) {
        if (node == NULL) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
};

int main() {
    AVL tree;
    int choice, x;

    while (true) {
        cout << "\n--- AVL TREE MENU ---\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Display Inorder\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> x;
                tree.root = tree.insert(tree.root, x);
                cout << "Inserted!\n";
                break;

            case 2:
                cout << "Enter value to search: ";
                cin >> x;
                {
                    Node* result = tree.search(tree.root, x);
                    if (result)
                        cout << "Element found at address: " << result << endl;
                    else
                        cout << "Element not found!\n";
                }
                break;

            case 3:
                cout << "Inorder traversal: ";
                tree.inorder(tree.root);
                cout << endl;
                break;

            case 4:
                cout << "Exiting. . .";
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }
}
