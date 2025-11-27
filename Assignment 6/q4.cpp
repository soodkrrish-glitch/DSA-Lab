#include <iostream>
using namespace std;

struct DNode {
    char data;
    DNode* prev;
    DNode* next;
    DNode(char x) : data(x), prev(nullptr), next(nullptr) {}
};

DNode* createDLL(int n) {
    DNode* head = nullptr;
    DNode* tail = nullptr;
    for (int i = 0; i < n; i++) {
        char ch;
        cin >> ch;
        DNode* node = new DNode(ch);
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

bool isPalindrome(DNode* head) {
    if (!head) return true;
    DNode* tail = head;
    while (tail->next) tail = tail->next;
    while (head != tail && head->prev != tail) {
        if (head->data != tail->data) return false;
        head = head->next;
        tail = tail->prev;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    DNode* head = createDLL(n);
    if (isPalindrome(head)) cout << "True";
    else cout << "False";
    return 0;
}
