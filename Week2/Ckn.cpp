#include<bits/stdc++.h>
using namespace std;
const int N = 1000, M = 1e9 + 7;
int C[N][N],n,k;
void input(){
    cin >> k >> n;
}
void pre(){
    for(int i=0;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==0) C[i][j] = 1;
            else if(i == j) C[i][j] = 1;
            else if( i<j ) C[i][j] = ( C[i][j-1] + C[i-1][j-1] ) % M;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    pre();
    cout << C[k][n];

}