#include<bits/stdc++.h>
using namespace std;
const int M = 11, N = 31;
int LB[M],crd[N],load[M],SL[M],m,n;
//phan cong mon k cho giao vien i
int phancong[N];

int kqua = INT_MAX;
//luu cac mon ma giao vien i co the day.
bool canTeach [M][N];
// them mon hoc cho gvien i



vector<vector<int>> adj(N);
void input(){
    cin >> m >> n;
    int k,v;
    for(int i=1;i<=m;i++){
        load[i] = 0;
        SL[i] = 0;
        cin >> k;
        for(int j=1;j<=k;j++){
            cin >> v; 
            canTeach[i][v] = true;
        }
    }

    for(int i=1;i<=n;i++){
        cin >> crd[i];
    }

    for(int i=1;i<=m;i++){
        cin >> LB[i];
    }

    int i,j;
    cin >> k;
    for(int v=1;v<=k;v++){
        cin >> i >> j;
        adj[i].push_back(j);
        adj[j].push_back(i);
    }

}
bool check(int k,int i){
    if(!canTeach[i][k]) return false;
    for( int x : adj[k]){
        if(phancong[x]==i) return false;
    }
    return true;
}
void Try(int k){
    if(k==n+1){
        int Max = INT_MIN;
        for(int i=1;i<=m;i++){
            if(SL[i] >= LB[i]){
                if(Max < load[i]) Max = load[i];
            }
            else return ;
        }
        kqua = min(kqua,Max);
        return;
    }
    for(int i=1;i<=m;i++){
        if(check(k,i) ){
            SL[i]++;
            load[i] += crd[k];
            phancong[k] = i;
            if(load[i] < kqua) Try(k+1);
            SL[i]--;
            load[i] -= crd[k];
            phancong[k] = 0;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    Try(1);
    if(kqua == INT_MAX) cout << -1;
    else cout << kqua;

}