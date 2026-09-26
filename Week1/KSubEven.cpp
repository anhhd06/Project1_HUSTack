#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int k,a[N],n,dem = 0,sum = 0;
void input(){
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(i <= k) sum += a[i];
    }
}
void solve(){
    if(sum % 2==0) dem ++;
    for(int i=k+1; i<=n ;i++){
        sum = sum + a[i] - a[i-k];
        if(sum % 2 == 0 ) dem ++;
    }
    cout << dem ;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    solve();
}