#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

Node* insertBST(Node* root, int k) {
    if (!root) return new Node(k);
    if (k < root->key) root->left = insertBST(root->left, k);
    else if (k > root->key) root->right = insertBST(root->right, k);
    return root;
}

Node* searchRec(Node* root, int k) {
    if (!root || root->key == k) return root;
    if (k < root->key) return searchRec(root->left, k);
    else return searchRec(root->right, k);
}

Node* searchIter(Node* root, int k) {
    while (root) {
        if (k == root->key) return root;
        else if (k < root->key) root = root->left;
        else root = root->right;
    }
    return nullptr;
}

Node* minNode(Node* root) {
    if (!root) return nullptr;
    while (root->left) root = root->left;
    return root;
}

Node* maxNode(Node* root) {
    if (!root) return nullptr;
    while (root->right) root = root->right;
    return root;
}

Node* inorderSuccessor(Node* root, int k) {
    Node* curr = root;
    Node* succ = nullptr;
    while (curr) {
        if (k < curr->key) {
            succ = curr;
            curr = curr->left;
        } else if (k > curr->key) {
            curr = curr->right;
        } else {
            if (curr->right) succ = minNode(curr->right);
            break;
        }
    }
    return succ;
}

Node* inorderPredecessor(Node* root, int k) {
    Node* curr = root;
    Node* pred = nullptr;
    while (curr) {
        if (k > curr->key) {
            pred = curr;
            curr = curr->right;
        } else if (k < curr->key) {
            curr = curr->left;
        } else {
            if (curr->left) pred = maxNode(curr->left);
            break;
        }
    }
    return pred;
}

int main() {
    int n;
    cin >> n;
    Node* root = nullptr;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insertBST(root, x);
    }
    int k;
    cin >> k;
    Node* s1 = searchRec(root, k);
    Node* s2 = searchIter(root, k);
    cout << "Recursive search: " << (s1 ? "Found" : "Not Found") << endl;
    cout << "Iterative search: " << (s2 ? "Found" : "Not Found") << endl;
    Node* mn = minNode(root);
    Node* mx = maxNode(root);
    cout << "Min: " << (mn ? mn->key : -1) << endl;
    cout << "Max: " << (mx ? mx->key : -1) << endl;
    Node* succ = inorderSuccessor(root, k);
    Node* pred = inorderPredecessor(root, k);
    cout << "Inorder successor of " << k << ": " << (succ ? succ->key : -1) << endl;
    cout << "Inorder predecessor of " << k << ": " << (pred ? pred->key : -1) << endl;
    return 0;
}
