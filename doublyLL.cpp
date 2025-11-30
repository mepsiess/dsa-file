#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    
    Node(int x) {
        data = x;
        prev = next = NULL;
    }
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = NULL;
    }

    // Insert at beginning
    void insertAtBeginning(int x) {
        Node* newNode = new Node(x);
        if (head == NULL) {
            head = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    // Insert at end
    void insertAtEnd(int x) {
        Node* newNode = new Node(x);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    // Remove from beginning
    void removeFromBeginning() {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;

        delete temp;
        cout << "Deleted from beginning.\n";
    }

    // Remove from end
    void removeFromEnd() {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = head;

        if (temp->next == NULL) { // only one node
            head = NULL;
            delete temp;
            cout << "Deleted the only element.\n";
            return;
        }

        while (temp->next != NULL)
            temp = temp->next;

        temp->prev->next = NULL;
        delete temp;
        cout << "Deleted from end.\n";
    }

    // Display list
    void display() {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        cout << "List: ";
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    DoublyLinkedList dll;
    int choice, x;

    while (true) {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Remove from beginning\n";
        cout << "4. Remove from end\n";
        cout << "5. Display list\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> x;
            dll.insertAtBeginning(x);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> x;
            dll.insertAtEnd(x);
            break;
        case 3:
            dll.removeFromBeginning();
            break;
        case 4:
            dll.removeFromEnd();
            break;
        case 5:
            dll.display();
            break;
        case 6:
            cout << "Exiting . . .";
            return 0;
        default:
            cout << "Invalid choice!\n";
        }
    }
}
