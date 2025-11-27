#include <bits/stdc++.h>
using namespace std;

int countDistinct(const vector<int>& a) {
    unordered_set<int> s(a.begin(), a.end());
    return (int)s.size();
}

int main() {
    vector<int> a = {1,2,2,3,4,1,5};
    cout << "Distinct count: " << countDistinct(a) << '\n';
}
