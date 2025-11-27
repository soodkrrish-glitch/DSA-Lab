#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll merge_count(vector<int>& a, vector<int>& temp, int l, int r) {
    if (l >= r) return 0;
    int mid = (l + r) / 2;
    ll cnt = merge_count(a, temp, l, mid) + merge_count(a, temp, mid+1, r);
    int i = l, j = mid+1, k = l;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) temp[k++] = a[i++];
        else {
            temp[k++] = a[j++];
            cnt += (mid - i + 1); 
        }
    }
    while (i <= mid) temp[k++] = a[i++];
    while (j <= r) temp[k++] = a[j++];
    for (int t = l; t <= r; ++t) a[t] = temp[t];
    return cnt;
}

ll countInversions(vector<int> a) {
    int n = a.size();
    vector<int> temp(n);
    return merge_count(a, temp, 0, n-1);
}

int main() {
    vector<int> a = {2, 4, 1, 3, 5};
    cout << "Inversions: " << countInversions(a) << '\n'; 
}
