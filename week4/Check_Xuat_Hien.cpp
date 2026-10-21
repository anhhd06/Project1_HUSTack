#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unordered_set <int> s;
    int n,a;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a;
        if(s.count(a)){
            cout << 1 <<endl;

        }
        else {
            cout << 0 << endl;
            s.insert(a);
        }
    }
}