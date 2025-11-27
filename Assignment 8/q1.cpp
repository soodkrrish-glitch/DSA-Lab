#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

Node* buildTreeLevelOrder() {
    int n;
    cin >> n;
    if (n == 0) return nullptr;
    int x;
    cin >> x;
    if (x == -1) return nullptr;
    Node* root = new Node(x);
    queue<Node*> q;
    q.push(root);
    int count = 1;
    while (!q.empty() && count < n) {
        Node* curr = q.front();
        q.pop();
        int l, r;
        cin >> l;
        count++;
        if (l != -1) {
            curr->left = new Node(l);
            q.push(curr->left);
        }
        if (count >= n) break;
        cin >> r;
        count++;
        if (r != -1) {
            curr->right = new Node(r);
            q.push(curr->right);
        }
    }
    return root;
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = buildTreeLevelOrder();
    cout << "Preorder: ";
    preorder(root);
    cout << "\nInorder: ";
    inorder(root);
    cout << "\nPostorder: ";
    postorder(root);
    cout << endl;
    return 0;
}
