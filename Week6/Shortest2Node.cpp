#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n,m;
vector < vector<pii> > adj; // luu cac canh ke cua i
vector<int> dist;
vector<bool> visited;

void input(){
    cin >> n >> m;
    adj.assign(n+1,vector<pii> ());
    dist.assign(n+1,INT_MAX/2);
    visited.assign(n+1,false);
    int u,v,w;
    for (int i=1;i<=m;i++){
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }
}
void solve(){
    int s,t;
    cin >> s >> t;
    priority_queue < pii , vector<pii> ,greater <pii> > pq;
    pq.push({0,s});
    bool check = false;
    while (!pq.empty())
    {
        pii top = pq.top();
        pq.pop();
        if(top.second == t){
            cout << top.first;
            check = true;
            break;
        }
        if(visited[top.second]) continue;
        else{
            visited[top.second] = true;
            dist[top.second] = top.first;
            for(pii x : adj[top.second]){
                if(top.first + x.second < dist[x.first]) pq.push({top.first + x.second,x.first});
            }
        } 
    }
    if(!check) cout << -1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    solve();
}