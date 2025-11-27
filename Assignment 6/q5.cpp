#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

Node* createList(int n, bool makeCircular) {
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        Node* node = new Node(x);
        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
    if (makeCircular && tail) tail->next = head;
    return head;
}

bool isCircular(Node* head) {
    if (!head) return false;
    Node* temp = head->next;
    while (temp && temp != head) temp = temp->next;
    return temp == head;
}

int main() {
    int n;
    cin >> n;
    int flag;
    cin >> flag;
    Node* head = createList(n, flag == 1);
    if (isCircular(head)) cout << "True";
    else cout << "False";
    return 0;
}
