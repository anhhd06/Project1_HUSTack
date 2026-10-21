#include<bits/stdc++.h>
using namespace std;
int T,n,m;
bool kqua;
// luu canh va check 
vector< vector<bool> > E;
vector<bool> visited;
vector<int> x;
//Quay lui
void Try(int k){
    if(kqua) return;
    if(k== n+1 && E[x[n]][1]){
        kqua = true;
        return;
    }
    else{
        for(int i=2;i<=n;i++){
            if(visited[i] == false && E[x[k-1]][i]){
                visited[i] = true;
                x[k] = i;
                Try(k+1);
                visited[i] = false;
            }
        }
    }
}
// Giai tung do thi
void solution(){
    cin >> n >> m;
    kqua = false;
    E.assign(n+1,vector<bool> (n+1,false) );
    visited.assign(n+1,false);
    x.assign(n+1,0);
    int u,v;
    for(int i=1;i<=m;i++){
        cin >> u >> v;
        E[u][v] = true;
        E[v][u] = true;
    }
    visited[1] = true;
    x[1] = 1;
    Try(2);
    if(kqua) cout<< 1<<endl;
    else cout << 0 << endl;
}

void solve(){
    for(int i=1;i<=T;i++){
        solution();
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    solve();
}