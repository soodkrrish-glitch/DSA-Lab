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

void insertDLLFirst(DNode*& head, int x) {
    DNode* node = new DNode(x);
    if (!head) {
        head = node;
        return;
    }
    node->next = head;
    head->prev = node;
    head = node;
}

void insertDLLLast(DNode*& head, int x) {
    DNode* node = new DNode(x);
    if (!head) {
        head = node;
        return;
    }
    DNode* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = node;
    node->prev = temp;
}

bool insertDLLAfter(DNode*& head, int key, int x) {
    if (!head) return false;
    DNode* temp = head;
    while (temp && temp->data != key) temp = temp->next;
    if (!temp) return false;
    DNode* node = new DNode(x);
    node->next = temp->next;
    node->prev = temp;
    if (temp->next) temp->next->prev = node;
    temp->next = node;
    return true;
}

bool insertDLLBefore(DNode*& head, int key, int x) {
    if (!head) return false;
    if (head->data == key) {
        insertDLLFirst(head, x);
        return true;
    }
    DNode* temp = head->next;
    while (temp && temp->data != key) temp = temp->next;
    if (!temp) return false;
    DNode* node = new DNode(x);
    node->next = temp;
    node->prev = temp->prev;
    temp->prev->next = node;
    temp->prev = node;
    return true;
}

bool deleteDLLValue(DNode*& head, int key) {
    if (!head) return false;
    DNode* temp = head;
    while (temp && temp->data != key) temp = temp->next;
    if (!temp) return false;
    if (temp == head) head = head->next;
    if (temp->prev) temp->prev->next = temp->next;
    if (temp->next) temp->next->prev = temp->prev;
    delete temp;
    return true;
}

bool searchDLL(DNode* head, int key) {
    DNode* temp = head;
    while (temp) {
        if (temp->data == key) return true;
        temp = temp->next;
    }
    return false;
}

void displayDLL(DNode* head) {
    DNode* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertCLLFirst(CNode*& head, int x) {
    CNode* node = new CNode(x);
    if (!head) {
        head = node;
        head->next = head;
        return;
    }
    CNode* last = head;
    while (last->next != head) last = last->next;
    node->next = head;
    last->next = node;
    head = node;
}

void insertCLLLast(CNode*& head, int x) {
    CNode* node = new CNode(x);
    if (!head) {
        head = node;
        head->next = head;
        return;
    }
    CNode* last = head;
    while (last->next != head) last = last->next;
    last->next = node;
    node->next = head;
}

bool insertCLLAfter(CNode*& head, int key, int x) {
    if (!head) return false;
    CNode* temp = head;
    do {
        if (temp->data == key) {
            CNode* node = new CNode(x);
            node->next = temp->next;
            temp->next = node;
            return true;
        }
        temp = temp->next;
    } while (temp != head);
    return false;
}

bool insertCLLBefore(CNode*& head, int key, int x) {
    if (!head) return false;
    if (head->data == key) {
        insertCLLFirst(head, x);
        return true;
    }
    CNode* prev = head;
    CNode* curr = head->next;
    while (curr != head && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == head) return false;
    CNode* node = new CNode(x);
    node->next = curr;
    prev->next = node;
    return true;
}

bool deleteCLLValue(CNode*& head, int key) {
    if (!head) return false;
    if (head->data == key && head->next == head) {
        delete head;
        head = nullptr;
        return true;
    }
    CNode* curr = head;
    CNode* prev = nullptr;
    do {
        if (curr->data == key) {
            if (curr == head) {
                CNode* last = head;
                while (last->next != head) last = last->next;
                head = head->next;
                last->next = head;
            } else {
                prev->next = curr->next;
            }
            delete curr;
            return true;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != head);
    return false;
}

bool searchCLL(CNode* head, int key) {
    if (!head) return false;
    CNode* temp = head;
    do {
        if (temp->data == key) return true;
        temp = temp->next;
    } while (temp != head);
    return false;
}

void displayCLL(CNode* head) {
    if (!head) {
        cout << endl;
        return;
    }
    CNode* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    DNode* dhead = nullptr;
    CNode* chead = nullptr;
    while (true) {
        cout << "1. Insert in DLL\n2. Delete from DLL\n3. Search in DLL\n4. Display DLL\n";
        cout << "5. Insert in CLL\n6. Delete from CLL\n7. Search in CLL\n8. Display CLL\n9. Exit\n";
        int choice;
        cin >> choice;
        if (choice == 9) break;
        int x, key, op;
        switch (choice) {
        case 1:
            cout << "1.First 2.Last 3.After 4.Before\n";
            cin >> op;
            if (op == 1 || op == 2) cin >> x;
            else cin >> key >> x;
            if (op == 1) insertDLLFirst(dhead, x);
            else if (op == 2) insertDLLLast(dhead, x);
            else if (op == 3) insertDLLAfter(dhead, key, x);
            else if (op == 4) insertDLLBefore(dhead, key, x);
            break;
        case 2:
            cin >> key;
            deleteDLLValue(dhead, key);
            break;
        case 3:
            cin >> key;
            cout << (searchDLL(dhead, key) ? "Found\n" : "Not Found\n");
            break;
        case 4:
            displayDLL(dhead);
            break;
        case 5:
            cout << "1.First 2.Last 3.After 4.Before\n";
            cin >> op;
            if (op == 1 || op == 2) cin >> x;
            else cin >> key >> x;
            if (op == 1) insertCLLFirst(chead, x);
            else if (op == 2) insertCLLLast(chead, x);
            else if (op == 3) insertCLLAfter(chead, key, x);
            else if (op == 4) insertCLLBefore(chead, key, x);
            break;
        case 6:
            cin >> key;
            deleteCLLValue(chead, key);
            break;
        case 7:
            cin >> key;
            cout << (searchCLL(chead, key) ? "Found\n" : "Not Found\n");
            break;
        case 8:
            displayCLL(chead);
            break;
        default:
            break;
        }
    }
    return 0;
}
