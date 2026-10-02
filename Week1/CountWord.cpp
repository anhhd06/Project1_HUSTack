#include<bits/stdc++.h>
using namespace std;
string s;
int solve(){
    int sum =0;
    while(getline(cin , s)){
        int n = int(s.size());
        for(int i=0; i < n; i++){
            if(isalpha(s[i]) ){
                sum+=1;
                while( (isalpha(s[i]) || s[i] == '-' ) && i<n ){
                    i+=1;
                }
            }
        } 
    }
    return sum;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int output = solve();
    cout << output ;

}