#include <bits/stdc++.h>
using namespace std;

struct T {
    int r,c;
    int val;
    bool operator<(const T& other) const {
        if (r != other.r) return r < other.r;
        return c < other.c;
    }
};

vector<T> transposeTriplet(const vector<T>& A) {
    vector<T> B;
    B.reserve(A.size());
    for (auto &t : A) B.push_back({t.c, t.r, t.val});
    sort(B.begin(), B.end());
    return B;
}

vector<T> addTriplets(const vector<T>& A, const vector<T>& B) {
    vector<T> C;
    int i=0, j=0;
    while (i < (int)A.size() && j < (int)B.size()) {
        if (A[i].r < B[j].r || (A[i].r==B[j].r && A[i].c < B[j].c)) C.push_back(A[i++]);
        else if (B[j].r < A[i].r || (A[i].r==B[j].r && B[j].c < A[i].c)) C.push_back(B[j++]);
        else { 
            int s = A[i].val + B[j].val;
            if (s != 0) C.push_back({A[i].r, A[i].c, s});
            i++; j++;
        }
    }
    while (i < (int)A.size()) C.push_back(A[i++]);
    while (j < (int)B.size()) C.push_back(B[j++]);
    return C;
}

vector<T> multiplyTriplets(const vector<T>& A, const vector<T>& B, int rowsA, int colsA, int colsB) {
    unordered_map<int, vector<pair<int,int>>> brow;
    for (auto &t : B) {
        brow[t.r].push_back({t.c, t.val});
    }
    map<pair<int,int>, long long> result;
    for (auto &a : A) {
        auto it = brow.find(a.c);
        if (it == brow.end()) continue;
        for (auto &p : it->second) {
            int col = p.first;
            int val = p.second;
            result[{a.r, col}] += 1LL * a.val * val;
        }
    }
    vector<T> C;
    for (auto &kv : result) {
        if (kv.second != 0) C.push_back({kv.first.first, kv.first.second, (int)kv.second});
    }
    return C;
}

void printTriplets(const vector<T>& A) {
    cout << "r c val\n";
    for (auto &t: A) cout << t.r << " " << t.c << " " << t.val << '\n';
}

int main() {
    vector<T> A = {{1,1,1}, {1,3,2}, {2,2,3}}; 
    vector<T> B = {{1,2,4}, {3,1,5}, {2,2,1}}; 
    cout << "A triplets:\n"; printTriplets(A);
    cout << "\nB triplets:\n"; printTriplets(B);

    cout << "\nTranspose of A:\n";
    auto At = transposeTriplet(A); printTriplets(At);

    cout << "\nAddition A + A:\n";
    auto sum = addTriplets(A, A); printTriplets(sum);

    cout << "\nMultiplication A * B:\n";
    auto prod = multiplyTriplets(A, B, 2, 3, 2);
    printTriplets(prod);
}
