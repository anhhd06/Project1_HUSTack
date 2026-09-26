#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    int n = int(s.size());
    if( n!= 10 || s[4]!='-' || s[7]!='-')
        cout << "INCORRECT";
    else {
        int Y = stoi(s.substr(0,4));
        int M = stoi (s.substr(5,2));
        int D = stoi(s.substr(8,2));
        if( M <1 || M >12 || D <1 || D > 31) cout << "INCORRECT";
        else cout << Y <<" "<< M <<" "<< D ;

    }
}