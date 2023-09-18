#include <iostream>
using namespace std;

const int MAX = 100;

struct Queue {
    int front, rear;
    int elements[MAX];
};

void initialize(Queue& q) {
    q.front = -1;
    q.rear = -1;
}

bool isEmpty(Queue& q) {
    return q.front == -1;
}

bool isFull(Queue& q) {
    return (q.rear + 1) % MAX == q.front;
}

void enqueue(Queue& q, int value) {
    if (isFull(q)) {
        cout << "Error: the queue is full." << endl;
        return;
    }
    if (isEmpty(q)) {
        q.front = 0;
        q.rear = 0;
    } else {
        q.rear = (q.rear + 1) % MAX;
    }
    q.elements[q.rear] = value;
}

int dequeue(Queue& q) {
    if (isEmpty(q)) {
        cout << "Error: the queue is empty." << endl;
        return -1;
    }
    int value = q.elements[q.front];
    if (q.front == q.rear) {
        q.front = -1;
        q.rear = -1;
    } else {
        q.front = (q.front + 1) % MAX;
    }
    return value;
}

int front(Queue& q) {
    if (isEmpty(q)) {
        cout << "Error: the queue is empty." << endl;
        return -1;
    }
    return q.elements[q.front];
}

void menu();

void clear() {
    system("cls");
    menu();
}

int main() {
    Queue q;
    initialize(q);
    menu();
    int option, value;
    do {
        cout << "Select an option: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "Enter the value to enqueue: ";
                cin >> value;
                enqueue(q, value);
                break;
            case 2:
                cout << "Dequeued element: " << dequeue(q) << endl;
                break;
            case 3:
                cout << "Is the queue full? " << (isFull(q) ? "Yes" : "No") << endl;
                break;
            case 4:
    if (isEmpty(q)) {
        cout << "Error: the queue is empty." << endl;
    } else {
        cout << "Queue elements: ";
        for (int i = q.front; i <= q.rear; i++) {
            cout << q.elements[i] << " ";
        }
        cout << endl;
    }
    break;
            case 5:
                clear();
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
                break;
        }
    } while (option != 0);
    return 0;
}

void menu() {
    cout << "Choose an option:" << endl;
    cout << "1. Enqueue" << endl;
    cout << "2. Dequeue" << endl;
    cout << "3. Check if the queue is full" << endl;
    cout << "4. Check the front element" << endl;
    cout << "5. Clear" << endl;
    cout << "0. Exit" << endl;
}
