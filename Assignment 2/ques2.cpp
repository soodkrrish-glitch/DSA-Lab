#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> a = {64, 34, 25, 12, 22, 11, 90};
    for (int i = 0; i < a.size()-1; i++)
        for (int j = 0; j < a.size()-i-1; j++)
            if (a[j] > a[j+1]) swap(a[j], a[j+1]);
    cout << "Sorted: ";
    for (int x : a) cout << x << " ";
}
