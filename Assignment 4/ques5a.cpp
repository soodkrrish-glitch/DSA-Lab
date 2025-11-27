#include <bits/stdc++.h>
using namespace std;

class StackUsing2Q {
    queue<int> q1, q2;
public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) { q2.push(q1.front()); q1.pop(); }
        swap(q1,q2);
    }
    void pop() { if(!q1.empty()) q1.pop(); }
    int top() { return q1.empty()? -1 : q1.front(); }
    bool empty() { return q1.empty(); }
};

int main() {
    StackUsing2Q st;
    st.push(10); st.push(20); st.push(30);
    cout << st.top() << "\n"; st.pop();
    cout << st.top();
}
