#include <bits/stdc++.h>
using namespace std;
int findMissingBinary(vector<int> &a, int n) {
    int l = 0, r = a.size()-1;
    while (l <= r) {
        int mid = (l + r)/2;
        if (a[mid] == mid+1) l = mid+1;
        else r = mid-1;
    }
    return l+1;
}
int main() {
    vector<int> a = {1,2,3,4,6,7};
    cout << "Missing: " << findMissingBinary(a,7);
}
