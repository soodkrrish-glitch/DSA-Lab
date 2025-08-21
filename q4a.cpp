#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Enter number of elements: ";
    cin >> num;
    int a[100];
    cout << "Enter the elements: ";
    for (int i = 0; i < num; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < num / 2; i++) {
        int temp = a[i];
        a[i] = a[num - i - 1];
        a[num - i - 1] = temp;
    }
    cout << "Reversed array: ";
    for (int i = 0; i < num; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
