/* 1. Write a program to implement singly linked list as an ADT that supports the following operations: 
i. Insert an element x at the beginning of the singly linked list
ii. Insert an element x at ith position in the singly linked list
iii. Remove an element from the beginning of the doubly linked list
iv. Remove an element from ith position in the singly linked list.
v. Search for an element x in the singly linked list and return its pointer*/



#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Insert at beginning
void insertAtBeginning(Node*& head, int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = head;
    head = newNode;
}

// Insert at i-th position (1-based index)
void insertAtPosition(Node*& head, int x, int pos) {
    Node* newNode = new Node;
    newNode->data = x;

    if (pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Position out of range!\n";
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Remove from beginning
void removeFromBeginning(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty!\n";
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

// Remove from i-th position
void removeFromPosition(Node*& head, int pos) {
    if (head == nullptr) {
        cout << "List is empty!\n";
        return;
    }

    if (pos == 1) {
        removeFromBeginning(head);
        return;
    }

    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr || temp->next == nullptr) {
        cout << "Position out of range!\n";
        return;
    }

    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
}

// Search element x and return pointer
Node* searchElement(Node* head, int x) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == x)
            return temp;
        temp = temp->next;
    }
    return nullptr;
}

// Display list
void display(Node* head) {
    Node* temp = head;
    cout << "List: ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = nullptr;
    int choice, x, pos;

    while (true) {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at ith position\n";
        cout << "3. Remove from beginning\n";
        cout << "4. Remove from ith position\n";
        cout << "5. Search for an element\n";
        cout << "6. Display list\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to insert: ";
                cin >> x;
                insertAtBeginning(head, x);
                break;

            case 2:
                cout << "Enter element: ";
                cin >> x;
                cout << "Enter position: ";
                cin >> pos;
                insertAtPosition(head, x, pos);
                break;

            case 3:
                removeFromBeginning(head);
                break;

            case 4:
                cout << "Enter position: ";
                cin >> pos;
                removeFromPosition(head, pos);
                break;

            case 5:
                cout << "Enter element to search: ";
                cin >> x;
                if (searchElement(head, x))
                    cout << "Element found at address: " << searchElement(head, x) << endl;
                else
                    cout << "Element not found!\n";
                break;

            case 6:
                display(head);
                break;

            case 7:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }
}
