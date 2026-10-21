#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string p,t;
    getline(cin,p);
    getline(cin,t);
    int sum = 0;
    while(t.find(p)!=string::npos){
        sum++;
        t = t.substr(t.find(p)+p.size());
    }
    cout << sum;
}