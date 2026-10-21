#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        string a;
        cin >> a;
        int h = 0;
        for( char c : a){
            h = ( h*256 + c) % m;
        }
        cout << h << endl;
    }
}