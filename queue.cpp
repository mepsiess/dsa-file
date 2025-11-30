/* 5. Implement Queue as an ADT */


#include <iostream>
using namespace std;

class Queue {
private:
    int arr[100];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    bool isFull() {
        return rear == 99;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow!\n";
            return;
        }
        if (front == -1)
            front = 0;
        arr[++rear] = x;
        cout << x << " inserted into queue.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!\n";
            return;
        }
        cout << "Deleted: " << arr[front] << endl;
        front++;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Front element: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Queue: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, x;

    while (true) {
        cout << "\n--- QUEUE ADT MENU ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek Front\n";
        cout << "4. Display Queue\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> x;
            q.enqueue(x);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.peek();
            break;

        case 4:
            q.display();
            break;

        case 5:
            cout << "Exiting. . .";
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }
}
