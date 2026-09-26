#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N],pre[N];
int n,i1,j_1,i2,j2,m;

void input(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    pre[0] = 0;
    for(int i=1;i<=n;i++){
        pre[i] = pre[i-1] + a[i];
    }
    cin >> m;
}
void solve(){
    for(int i=1;i<=m;i++){
        cin >> i1 >> j_1 >> i2 >> j2 ;
        if( pre[j_1] - pre[i1-1] < pre[j2] - pre[i2-1]) cout<< 1 <<endl;
        else cout << 0 <<endl;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    solve();

}