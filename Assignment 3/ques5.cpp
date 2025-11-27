#include <bits/stdc++.h>
using namespace std;

int evalPostfix(string exp) {
    stack<int> st;
    for (char c : exp) {
        if (isdigit(c)) st.push(c - '0');
        else {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            switch (c) {
                case '+': st.push(a + b); break;
                case '-': st.push(a - b); break;
                case '*': st.push(a * b); break;
                case '/': st.push(a / b); break;
            }
        }
    }
    return st.top();
}

int main() {
    string exp; cout << "Enter postfix: "; cin >> exp;
    cout << "Result: " << evalPostfix(exp);
}
