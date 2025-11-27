#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIdx]) minIdx = j;
        }
        if (minIdx != i) swap(a[i], a[minIdx]);
    }
}

void insertionSort(vector<int>& a) {
    int n = a.size();
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void bubbleSort(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void merge(vector<int>& a, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = a[l + i];
    for (int j = 0; j < n2; j++) R[j] = a[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) a[k++] = L[i++];
        else a[k++] = R[j++];
    }
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
}

void mergeSortRec(vector<int>& a, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSortRec(a, l, m);
    mergeSortRec(a, m + 1, r);
    merge(a, l, m, r);
}

void mergeSort(vector<int>& a) {
    if (!a.empty()) mergeSortRec(a, 0, (int)a.size() - 1);
}

int partitionQS(vector<int>& a, int low, int high) {
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}

void quickSortRec(vector<int>& a, int low, int high) {
    if (low < high) {
        int pi = partitionQS(a, low, high);
        quickSortRec(a, low, pi - 1);
        quickSortRec(a, pi + 1, high);
    }
}

void quickSort(vector<int>& a) {
    if (!a.empty()) quickSortRec(a, 0, (int)a.size() - 1);
}

void improvedSelectionSort(vector<int>& a) {
    int n = a.size();
    int left = 0, right = n - 1;
    while (left < right) {
        int minIdx = left;
        int maxIdx = right;
        if (a[minIdx] > a[maxIdx]) swap(a[minIdx], a[maxIdx]);
        for (int i = left + 1; i < right; i++) {
            if (a[i] < a[minIdx]) minIdx = i;
            else if (a[i] > a[maxIdx]) maxIdx = i;
        }
        if (minIdx != left) swap(a[left], a[minIdx]);
        if (maxIdx == left) maxIdx = minIdx;
        if (maxIdx != right) swap(a[right], a[maxIdx]);
        left++;
        right--;
    }
}

void printArray(const vector<int>& a) {
    for (int x : a) cout << x << " ";
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> s = a;
    vector<int> ins = a;
    vector<int> bub = a;
    vector<int> mer = a;
    vector<int> qui = a;
    vector<int> imp = a;

    selectionSort(s);
    insertionSort(ins);
    bubbleSort(bub);
    mergeSort(mer);
    quickSort(qui);
    improvedSelectionSort(imp);

    cout << "Selection Sort: ";
    printArray(s);
    cout << "Insertion Sort: ";
    printArray(ins);
    cout << "Bubble Sort: ";
    printArray(bub);
    cout << "Merge Sort: ";
    printArray(mer);
    cout << "Quick Sort: ";
    printArray(qui);
    cout << "Improved Selection Sort: ";
    printArray(imp);

    return 0;
}
