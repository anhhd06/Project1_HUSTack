#include<bits/stdc++.h>
using namespace std;
stack<int> st;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string type;
    int k;
    cin >> type;
    while (type != "#")
    {
        if(type == "PUSH"){
            cin >> k;
            st.push(k);
        }
        else{
            if(st.empty()) cout << "NULL" << endl; 
            else{
                cout << st.top() << endl ;
                st.pop();
            }
        }
        cin >> type;

    }
    
}