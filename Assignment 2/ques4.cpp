#include <bits/stdc++.h>
using namespace std;

// (a)
string concatStrings(string a, string b){ return a+b; }
// (b)
string reverseString(string s){ reverse(s.begin(),s.end()); return s; }
// (c)
string deleteVowels(string s){
    string r;
    for(char c:s){
        char t=tolower(c);
        if(t!='a'&&t!='e'&&t!='i'&&t!='o'&&t!='u') r+=c;
    }
    return r;
}
// (d)
void sortStrings(vector<string>& arr){ sort(arr.begin(),arr.end()); }
// (e)
string toLowerCase(string s){ for(char &c:s)c=tolower(c); return s; }

int main(){
    cout<<concatStrings("Hello","World")<<"\n";
    cout<<reverseString("DataStructure")<<"\n";
    cout<<deleteVowels("HelloWorld")<<"\n";
    vector<string>a={"banana","apple","mango"};
    sortStrings(a); for(auto&s:a)cout<<s<<" "; cout<<"\n";
    cout<<toLowerCase("ABcdEF");
}
