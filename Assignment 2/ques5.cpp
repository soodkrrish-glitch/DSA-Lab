#include <bits/stdc++.h>
using namespace std;

// Diagonal matrix
struct Diagonal {
    int n;
    vector<int> A;
    Diagonal(int n): n(n), A(n+1,0) {} 
    void set(int i,int j,int val){ if(i==j) A[i]=val; }
    int get(int i,int j){ return (i==j? A[i] : 0); }
    void display(){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++) cout << get(i,j) << ' ';
            cout << '\n';
        }
    }
};

// Lower triangular 
struct Lower {
    int n;
    vector<int> A;
    Lower(int n): n(n), A(n*(n+1)/2 + 1, 0) {}
    int idx(int i,int j){ 
        return (i*(i-1))/2 + j;
    }
    void set(int i,int j,int val){ if(i>=j) A[idx(i,j)] = val; }
    int get(int i,int j){ if(i>=j) return A[idx(i,j)]; return 0; }
    void display(){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++) cout << get(i,j) << ' ';
            cout << '\n';
        }
    }
};

// Upper triangular 
struct Upper {
    int n;
    vector<int> A;
    Upper(int n): n(n), A(n*(n+1)/2 + 1, 0) {}
    int idx(int i,int j){ 
        return (j*(j-1))/2 + i;
    }
    void set(int i,int j,int val){ if(i<=j) A[idx(i,j)] = val; }
    int get(int i,int j){ if(i<=j) return A[idx(i,j)]; return 0; }
    void display(){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++) cout << get(i,j) << ' ';
            cout << '\n';
        }
    }
};

// Symmetric matrix
struct Symmetric {
    int n;
    vector<int> A;
    Symmetric(int n): n(n), A(n*(n+1)/2 + 1, 0) {}
    int idx(int i,int j){ if(i>=j) return (i*(i-1))/2 + j; else return (j*(j-1))/2 + i; }
    void set(int i,int j,int val){ A[idx(i,j)] = val; }
    int get(int i,int j){ return A[idx(i,j)]; }
    void display(){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++) cout << get(i,j) << ' ';
            cout << '\n';
        }
    }
};

// Tri-diagonal
struct Tridiagonal {
    int n;
    vector<int> A; 
    Tridiagonal(int n): n(n), A(3*n - 2, 0) {}
    void set(int i, int j, int val){
        if (i==j) A[n-1 + i-1] = val;            
        else if (i == j+1) A[j-1] = val;         
        else if (i+1 == j) A[(2*n-1) + i-1] = val;     }
    int get(int i,int j){
        if (i==j) return A[n-1 + i-1];
        if (i == j+1) return A[j-1];
        if (i+1 == j) return A[(2*n-1) + i-1];
        return 0;
    }
    void display(){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++) cout << get(i,j) << ' ';
            cout << '\n';
        }
    }
};

int main() {
    cout << "Demo: Diagonal matrix 4x4\n";
    Diagonal D(4);
    D.set(1,1,5); D.set(2,2,8); D.set(3,3,9); D.set(4,4,1);
    D.display();
    cout << "Demo: Lower triangular 4x4\n";
    Lower L(4);
    L.set(1,1,1); L.set(2,1,2); L.set(2,2,3); L.set(4,1,7);
    L.display();
    cout << "Demo: Symmetric 3x3\n";
    Symmetric S(3);
    S.set(1,2,10); S.set(2,3,20); S.set(1,1,5);
    S.display();
}
