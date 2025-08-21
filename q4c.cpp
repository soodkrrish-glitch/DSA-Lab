#include <iostream>
using namespace std;

int main() {
    int r, c;
    cout << "Enter number of rows: ";
    cin >> r;
    cout << "Enter number of columns: ";
    cin >> c;

    int a[20][20], b[20][20];

    cout << "Enter elements of matrix a: ";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> a[i][j];
            b[j][i] = a[i][j];
        }
    }

    cout << "Original matrix:" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Transpose matrix:" << endl;
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            cout << b[j][i] << " ";
        }
        cout << endl;
    }

    return 0;
}
