#include<bits/stdc++.h>
using namespace std;
const int N= 11;
bool check[N][N];
int a[N][N],n,r,c;
int Max,maxpre;
int dx[8] = {1,-1,1,-1,2,-2,2,-2};
int dy[8] = {2,2,-2,-2,1,1,-1,-1};
void input(){
    cin >> n >> r >> c;
    check[r][c] = true;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
        }
    }
    Max = a[r][c];
    maxpre = a[r][c];
}

void Try(int i,int j,int k){
    if(k==n*n) return;
    int x,y;
    for(int u=0;u<8;u++){
        x = i + dx[u];
        y = j + dy[u];
        if( x >=1 && y >=1 && x<=n && y <= n && check[x][y] == false){
            check[x][y] = true;
            maxpre += a[x][y];
            Max = max(Max,maxpre);
            Try(x,y,k+1);
            maxpre -= a[x][y];
            check[x][y] = false;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    Try(r,c,1);
    cout << Max;

}