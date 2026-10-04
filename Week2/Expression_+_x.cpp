#include<bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
string a;
stack<long long> st;
// check xem da gap phep nhan chua
bool check1 = false;
// check xem co gap phep tinh truoc do khong
bool check2 = false;

void solve(){
    cin >> a;
    int n = a.size();
    if(!isdigit(a[n-1])){
        cout << "NOT_CORRECT";
        return;
    }
    for(int i=0;i<n;i++){

        if(isdigit(a[i])){
            check2 = false;
            int j = i;
            while  ( j+1 < n && isdigit(a[j+1]) )
            {
                j++;
            }
            int num = stoi(a.substr(i,j-i+1));
            i = j;
            if(check1){
                if(st.empty()){
                    cout << "NOT_CORRECT";
                    return;
                }
                else{
                    st.top() *= num;
                    check1 = false;
                }
            }
            else st.push(num);
        }
        else if(a[i] == '*'){
            if(check2){
                cout << "NOT_CORRECT";
                return;
            }
            else{
                check1 = true;
                check2 = true ;
            }
        }
        else{
            if(check2){
                cout << "NOT_CORRECT";
            }
            else{
                check2 = true;
            }
        }

    }
    long long sum = 0;
    while (!st.empty())
    {
        sum += st.top() % M;
        st.pop();
    }
    cout<< sum % M;
    

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}