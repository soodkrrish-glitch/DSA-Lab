#include <iostream>
#include <algorithm>
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

Node* minNode(Node* root) {
    if (!root) return nullptr;
    while (root->left) root = root->left;
    return root;
}

Node* deleteBST(Node* root, int k) {
    if (!root) return nullptr;
    if (k < root->key) root->left = deleteBST(root->left, k);
    else if (k > root->key) root->right = deleteBST(root->right, k);
    else {
        if (!root->left && !root->right) {
            delete root;
            return nullptr;
        } else if (!root->left) {
            Node* t = root->right;
            delete root;
            return t;
        } else if (!root->right) {
            Node* t = root->left;
            delete root;
            return t;
        } else {
            Node* succ = minNode(root->right);
            root->key = succ->key;
            root->right = deleteBST(root->right, succ->key);
        }
    }
    return root;
}

int maxDepth(Node* root) {
    if (!root) return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    return 1 + max(l, r);
}

int minDepth(Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    if (!root->left) return 1 + minDepth(root->right);
    if (!root->right) return 1 + minDepth(root->left);
    int l = minDepth(root->left);
    int r = minDepth(root->right);
    return 1 + min(l, r);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
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
    int del;
    cin >> del;
    root = deleteBST(root, del);
    cout << "Inorder after deletion: ";
    inorder(root);
    cout << "\nMax depth: " << maxDepth(root) << endl;
    cout << "Min depth: " << minDepth(root) << endl;
    return 0;
}
