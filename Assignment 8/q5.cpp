#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>& a, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && a[l] > a[largest]) largest = l;
    if (r < n && a[r] > a[largest]) largest = r;
    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void heapSortAsc(vector<int>& a) {
    int n = a.size();
    for (int i = n / 2 - 1; i >= 0; i--) heapify(a, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

void heapSortDesc(vector<int>& a) {
    heapSortAsc(a);
    int n = a.size();
    for (int i = 0; i < n / 2; i++) swap(a[i], a[n - 1 - i]);
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> b = a;
    heapSortAsc(a);
    heapSortDesc(b);
    cout << "Ascending: ";
    for (int x : a) cout << x << " ";
    cout << "\nDescending: ";
    for (int x : b) cout << x << " ";
    cout << endl;
    return 0;
}
