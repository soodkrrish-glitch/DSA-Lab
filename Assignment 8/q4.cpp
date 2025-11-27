#include <iostream>
#include <queue>
#include <climits>
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

bool isBSTUtil(Node* root, long long mn, long long mx) {
    if (!root) return true;
    if (root->data <= mn || root->data >= mx) return false;
    return isBSTUtil(root->left, mn, root->data) && isBSTUtil(root->right, root->data, mx);
}

bool isBST(Node* root) {
    return isBSTUtil(root, LLONG_MIN, LLONG_MAX);
}

int main() {
    Node* root = buildTreeLevelOrder();
    if (isBST(root)) cout << "BST";
    else cout << "Not BST";
    cout << endl;
    return 0;
}
