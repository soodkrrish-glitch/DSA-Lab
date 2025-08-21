#include <iostream>
#include <cstdlib>
using namespace std;

int arr[100], n = 0;

void create() {
    cout << "Enter size of array: ";
    cin >> n;
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
}

void display() {
    cout << "Array elements: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";
}

void insert() {
    int pos, val;
    cout << "Enter position to insert: ";
    cin >> pos;
    cout << "Enter value to insert: ";
    cin >> val;
    for (int i = n; i >= pos; i--) arr[i] = arr[i - 1];
    arr[pos - 1] = val;
    n++;
}

void del() {
    int pos;
    cout << "Enter position to delete: ";
    cin >> pos;
    for (int i = pos - 1; i < n - 1; i++) arr[i] = arr[i + 1];
    n--;
}

void search() {
    int value;
    cout << "Enter element to search: ";
    cin >> value;
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            cout << "Found at position " << i + 1 << "\n";
            return;
        }
    }
    cout << "Not found\n";
}

int main() {
    int ch;
        cout << "\n1 -> CREATE\n2 -> DISPLAY\n3 -> INSERT\n4 -> DELETE\n5 -> SEARCH\n6 -> EXIT\n";
        cout << "Enter choice: ";
        cin >> ch;
        switch(ch) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insert(); break;
            case 4: del(); break;
            case 5: search(); break;
            case 6: exit(0);
            default: cout << "Invalid choice\n";
        }
    }
