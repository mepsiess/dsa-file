/* 3. Write a program to implement circular linked list as an ADT which supports the following operations:
i. Insert an element x in the list
ii. Remove an element from the list
iii. Search for an element x in the list and return its pointer */


#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class CircularLinkedList {
private:
    Node* tail;

public:
    CircularLinkedList() {
        tail = NULL;
    }

    // Insert element x in the list
    void insert(int x) {
        Node* newNode = new Node(x);

        if (tail == NULL) {  
            tail = newNode;
            tail->next = tail;   // points to itself
            return;
        }

        newNode->next = tail->next; 
        tail->next = newNode;       
        tail = newNode;             
    }

    // Remove element x from list
    void remove(int x) {
        if (tail == NULL) {
            cout << "List is empty!\n";
            return;
        }

        Node* curr = tail->next;
        Node* prev = tail;

        do {
            if (curr->data == x) {
                if (curr == tail && curr == tail->next) {  
                    tail = NULL; // deleting the only element
                }
                else if (curr == tail) {
                    tail = prev; // update tail if we're deleting last
                }
                prev->next = curr->next;
                delete curr;
                cout << "Deleted " << x << " from the list.\n";
                return;
            }

            prev = curr;
            curr = curr->next;

        } while (curr != tail->next);

        cout << "Element not found!\n";
    }

    // Search for element x
    Node* search(int x) {
        if (tail == NULL) {
            return NULL;
        }

        Node* temp = tail->next;

        do {
            if (temp->data == x) {
                return temp; // pointer returned
            }
            temp = temp->next;

        } while (temp != tail->next);

        return NULL;
    }

    // Display list
    void display() {
        if (tail == NULL) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = tail->next;
        cout << "List: ";

        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != tail->next);

        cout << "(back to head)\n";
    }
};

int main() {
    CircularLinkedList cll;
    int choice, x;

    while (true) {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert element\n";
        cout << "2. Remove element\n";
        cout << "3. Search element\n";
        cout << "4. Display list\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> x;
            cll.insert(x);
            break;

        case 2:
            cout << "Enter value to delete: ";
            cin >> x;
            cll.remove(x);
            break;

        case 3:
            cout << "Enter value to search: ";
            cin >> x;
            {
                Node* result = cll.search(x);
                if (result != NULL)
                    cout << "Element found at address: " << result << "\n";
                else
                    cout << "Element not found!\n";
            }
            break;

        case 4:
            cll.display();
            break;

        case 5:
            cout << "Exiting . . .";
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }
}
