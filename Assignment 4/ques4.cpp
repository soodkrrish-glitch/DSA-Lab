#include <bits/stdc++.h>
using namespace std;
int main() {
    string s; cout << "Enter string: "; cin >> s;
    vector<int> freq(26,0);
    queue<char> q;
    for (char c : s) {
        freq[c-'a']++;
        q.push(c);
        while (!q.empty() && freq[q.front()-'a']>1)
            q.pop();
        if (q.empty()) cout << "-1 ";
        else cout << q.front() << " ";
    }
}
