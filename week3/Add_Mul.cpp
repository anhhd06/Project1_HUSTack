#include<bits/stdc++.h>
using namespace std;
stack <char> st;
string a;
void solve(){
    for(int i=0;i<a.size();i++){
        if(a[i] == '(') st.push(a[i]);
        else if (isdigit(a[i])){
            
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a;
}