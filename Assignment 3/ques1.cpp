#include <bits/stdc++.h>
using namespace std;

#define MAX 100
class Stack {
    int arr[MAX];
    int top;
public:
    Stack() { top = -1; }
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX - 1; }

    void push(int val) {
        if (isFull()) cout << "Stack Overflow\n";
        else arr[++top] = val;
    }

    void pop() {
        if (isEmpty()) cout << "Stack Underflow\n";
        else cout << "Popped: " << arr[top--] << "\n";
    }

    void peek() {
        if (isEmpty()) cout << "Stack Empty\n";
        else cout << "Top element: " << arr[top] << "\n";
    }

    void display() {
        if (isEmpty()) cout << "Stack Empty\n";
        else {
            cout << "Stack: ";
            for (int i = top; i >= 0; i--) cout << arr[i] << " ";
            cout << "\n";
        }
    }
};

int main() {
    Stack s;
    int choice, val;
    while (true) {
        cout << "\n1.Push  2.Pop  3.Display  4.Peek  5.Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter value: "; cin >> val; s.push(val); break;
            case 2: s.pop(); break;
            case 3: s.display(); break;
            case 4: s.peek(); break;
            case 5: return 0;
            default: cout << "Invalid!\n";
        }
    }
}
