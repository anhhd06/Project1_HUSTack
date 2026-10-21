#include<bits/stdc++.h>
using namespace std;
unordered_set <string> s;
void input(){
    string k;
    while (1)
    {
        cin >> k;
        if(  k == "*") break;
        else{
            s.insert(k);
        }
    }
    
}
void solve(){
    string cmd,k;
    cin >> cmd;
    while (cmd != "***")
    {
        if(cmd == "find"){
            cin >> k;
            if(s.count(k)){
                cout << 1<< endl;
            }
            else cout << 0 << endl;
        }
        else if(cmd == "insert"){
            cin >> k;
            if(s.count(k)){
                cout << 0 <<endl;
            }
            else{
                s.insert(k);
                cout<< 1 << endl;
            }
        }
        cin >> cmd;
    }
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    solve();
    
}