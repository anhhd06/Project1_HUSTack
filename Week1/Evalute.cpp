#include<bits/stdc++.h>
using namespace std; 
string s;
int solve(){
    int sum = 0;
    cin >> s;
    int n = int(s.size());
    for( int i=0; i<n ;i++){
        if(isdigit(s[i])){
            int dem = 0;
            while(isdigit(s[i]) && i < n){
                i++;
                dem++;
            }
            sum += stoi(s.substr(i-dem,dem));
        }
        else if(s[i]!='+') return -1;
    }
    if(isdigit(s[n-1])!=1) return -1;
    return sum;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int output = solve();
    if(output == -1) cout<<"NOT_CORRECT";
    else cout << output ;

}