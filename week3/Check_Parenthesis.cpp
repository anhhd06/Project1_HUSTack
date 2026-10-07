#include<bits/stdc++.h>
using namespace std;
stack<char> st;
string a;
bool checkopen(char x){
    if(x=='(' || x=='[' || x=='{')  return true;
    else return false;
}
void solve(){
    for(int i=0;i<a.size();i++){
        if(checkopen(a[i])) st.push(a[i]);
        else{
            if(st.empty()) {
                cout << 0;
                return;
            }
            else if(a[i] ==')'){
                if( st.top() == '('){
                    st.pop();
                }
                else{
                    cout << 0;
                    return;
                }
            }
            else if( a[i] == ']'){
                if( st.top() == '['){
                    st.pop();
                }
                else {
                    cout << 0;
                    return;
                }
            }
            else if( a[i]=='}'){
                if( st.top() == '{'){
                    st.pop();
                }
                else {
                    cout << 0;
                    return;
                }
            }
            else cout << 0;
        }
    }
   
    if(st.empty()) cout << 1;
    else cout << 0;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a;
    solve();
}