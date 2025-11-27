#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &a, int key) {
    int l = 0, r = a.size() - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] == key) return mid;
        else if (a[mid] < key) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}
int main() {
    vector<int> a = {10, 20, 30, 40, 50};
    int key; cout << "Enter key: "; cin >> key;
    int pos = binarySearch(a, key);
    if (pos != -1) cout << "Found at index " << pos << endl;
    else cout << "Not found\n";
}
