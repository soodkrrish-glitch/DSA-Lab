#include <bits/stdc++.h>
using namespace std;

#define MAX 5
class CircularQueue {
    int arr[MAX], front, rear;
public:
    CircularQueue() { front = rear = -1; }

    bool isEmpty() { return front == -1; }
    bool isFull()  { return (rear + 1) % MAX == front; }

    void enqueue(int x) {
        if (isFull()) { cout << "Queue Full\n"; return; }
        if (front == -1) front = 0;
        rear = (rear + 1) % MAX;
        arr[rear] = x;
    }

    void dequeue() {
        if (isEmpty()) { cout << "Queue Empty\n"; return; }
        cout << "Deleted: " << arr[front] << "\n";
        if (front == rear) front = rear = -1;
        else front = (front + 1) % MAX;
    }

    void display() {
        if (isEmpty()) { cout << "Queue Empty\n"; return; }
        cout << "Queue: ";
        int i = front;
        do {
            cout << arr[i] << " ";
            i = (i + 1) % MAX;
        } while (i != (rear + 1) % MAX);
        cout << "\n";
    }
};

int main() {
    CircularQueue q; int ch, val;
    while (true) {
        cout << "\n1.Enqueue 2.Dequeue 3.Display 4.Exit\nChoice: ";
        cin >> ch;
        switch (ch) {
            case 1: cout << "Enter value: "; cin >> val; q.enqueue(val); break;
            case 2: q.dequeue(); break;
            case 3: q.display(); break;
            case 4: return 0;
            default: cout << "Invalid!\n";
        }
    }
}
