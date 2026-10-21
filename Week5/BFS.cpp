#include<bits/stdc++.h>
using namespace std;
int n,m;
queue <int> q;
vector <bool> visited;
vector < vector<bool> > E;
vector<int> x;
void input(){
    cin >> n >> m;
    visited.assign(n+1,false);
    E.assign(n+1,vector<bool>(n+1,false));
    int u,v;
    for(int i=1;i<=m;i++){
        cin >> u >> v;
        E[u][v] = true;
        E[v][u] = true;
    }
}
void solve();
void solution(){
    for(int i=1;i<=n;i++){
        if(visited[i] == false){
            q.push(i);
            visited[i] = true;
            solve();
        }
    }
    for(int i=0;i<x.size();i++){
        cout << x[i] << " ";
    }
    
}
void solve(){
    while (!q.empty())
    {
        int fr = q.front();
        q.pop();
        x.push_back(fr);
        for(int i=2;i<=n;i++){
            if(E[fr][i] && visited[i] == false){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    solution();
}