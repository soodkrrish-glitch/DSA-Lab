#include <iostream>
#include <vector>
using namespace std;

void heapifyDown(vector<int>& h, int i) {
    int n = h.size();
    while (true) {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < n && h[l] > h[largest]) largest = l;
        if (r < n && h[r] > h[largest]) largest = r;
        if (largest == i) break;
        swap(h[i], h[largest]);
        i = largest;
    }
}

void heapifyUp(vector<int>& h, int i) {
    while (i > 0) {
        int p = (i - 1) / 2;
        if (h[p] < h[i]) {
            swap(h[p], h[i]);
            i = p;
        } else break;
    }
}

void pushPQ(vector<int>& h, int x) {
    h.push_back(x);
    heapifyUp(h, (int)h.size() - 1);
}

bool emptyPQ(const vector<int>& h) {
    return h.empty();
}

int topPQ(const vector<int>& h) {
    if (h.empty()) return -1;
    return h[0];
}

int popPQ(vector<int>& h) {
    if (h.empty()) return -1;
    int top = h[0];
    h[0] = h.back();
    h.pop_back();
    if (!h.empty()) heapifyDown(h, 0);
    return top;
}

void displayPQ(const vector<int>& h) {
    for (int x : h) cout << x << " ";
    cout << endl;
}

int main() {
    vector<int> heap;
    int choice;
    while (true) {
        cout << "1.Insert 2.Top 3.Pop 4.Display 5.Exit\n";
        cin >> choice;
        if (choice == 5) break;
        if (choice == 1) {
            int x;
            cin >> x;
            pushPQ(heap, x);
        } else if (choice == 2) {
            cout << topPQ(heap) << endl;
        } else if (choice == 3) {
            cout << popPQ(heap) << endl;
        } else if (choice == 4) {
            displayPQ(heap);
        }
    }
    return 0;
}
