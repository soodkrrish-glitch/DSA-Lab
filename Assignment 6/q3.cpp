#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int x) : data(x), prev(nullptr), next(nullptr) {}
};

struct CNode {
    int data;
    CNode* next;
    CNode(int x) : data(x), next(nullptr) {}
};

DNode* createDLL(int n) {
    DNode* head = nullptr;
    DNode* tail = nullptr;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        DNode* node = new DNode(x);
        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }
    return head;
}

CNode* createCLL(int n) {
    CNode* head = nullptr;
    CNode* tail = nullptr;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        CNode* node = new CNode(x);
        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
    if (tail) tail->next = head;
    return head;
}

int sizeDLL(DNode* head) {
    int c = 0;
    while (head) {
        c++;
        head = head->next;
    }
    return c;
}

int sizeCLL(CNode* head) {
    if (!head) return 0;
    int c = 0;
    CNode* temp = head;
    do {
        c++;
        temp = temp->next;
    } while (temp != head);
    return c;
}

int main() {
    int n1, n2;
    cin >> n1;
    DNode* dhead = createDLL(n1);
    cin >> n2;
    CNode* chead = createCLL(n2);
    cout << "Size of DLL: " << sizeDLL(dhead) << endl;
    cout << "Size of CLL: " << sizeCLL(chead) << endl;
    return 0;
}
