#include<bits/stdc++.h>
using namespace std;
string a,b,T;
void input(){
    getline(cin,a);
    getline(cin,b);
    getline(cin,T);

}
void solve(){
    while ( T.find(a) != string::npos){
        int index = T.find(a);
        T.replace(index,int(a.size()),b);
    }
    cout<< T ;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    solve();
    
}