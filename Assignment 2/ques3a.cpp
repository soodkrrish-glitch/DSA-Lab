#include <bits/stdc++.h>
using namespace std;
int findMissingLinear(vector<int> &a, int n) {
    for (int i = 0; i < a.size(); i++)
        if (a[i] != i + 1) return i + 1;
    return n;
}
int main() {
    vector<int> a = {1,2,3,4,6,7};
    cout << "Missing: " << findMissingLinear(a, 7);
}
