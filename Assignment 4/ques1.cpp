#include <bits/stdc++.h>
using namespace std;

#define MAX 100
class Queue {
    int arr[MAX];
    int front, rear;
public:
    Queue() { front = rear = -1; }

    bool isEmpty() { return front == -1 || front > rear; }
    bool isFull()  { return rear == MAX - 1; }

    void enqueue(int x) {
        if (isFull()) { cout << "Queue Overflow\n"; return; }
        if (front == -1) front = 0;
        arr[++rear] = x;
    }

    void dequeue() {
        if (isEmpty()) { cout << "Queue Underflow\n"; return; }
        cout << "Deleted: " << arr[front++] << "\n";
    }

    void peek() {
        if (isEmpty()) cout << "Queue Empty\n";
        else cout << "Front element: " << arr[front] << "\n";
    }

    void display() {
        if (isEmpty()) cout << "Queue Empty\n";
        else {
            cout << "Queue: ";
            for (int i = front; i <= rear; i++) cout << arr[i] << " ";
            cout << "\n";
        }
    }
};

int main() {
    Queue q; int ch, val;
    while (true) {
        cout << "\n1.Enqueue 2.Dequeue 3.Display 4.Peek 5.Exit\nChoice: ";
        cin >> ch;
        switch (ch) {
            case 1: cout << "Enter value: "; cin >> val; q.enqueue(val); break;
            case 2: q.dequeue(); break;
            case 3: q.display(); break;
            case 4: q.peek(); break;
            case 5: return 0;
            default: cout << "Invalid!\n";
        }
    }
}
