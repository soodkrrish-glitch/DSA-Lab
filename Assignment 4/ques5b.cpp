#include <bits/stdc++.h>
using namespace std;

class StackUsing1Q {
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        int n = q.size();
        for (int i = 0; i < n-1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    void pop() { if(!q.empty()) q.pop(); }
    int top() { return q.empty()? -1 : q.front(); }
    bool empty() { return q.empty(); }
};

int main() {
    StackUsing1Q s;
    s.push(5); s.push(10); s.push(15);
    cout << s.top() << "\n";
    s.pop();
    cout << s.top();
}
