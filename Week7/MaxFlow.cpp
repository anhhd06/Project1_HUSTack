#include<bits/stdc++.h>
using namespace std;
int n,m,s,t;
vector < vector<int> > capacity;
vector < vector<int> > adj;
vector<int> parent;
void input(){
    cin >> n >> m;
    capacity.assign(n+1, vector<int>(n+1,0));
    adj.resize(n+1);
    //
    cin >> s >> t;
    int u,v,c;
    for(int i=1;i<=m;i++){
        cin >> u >> v >> c;
        adj[u].push_back(v);
        adj[v].push_back(u);
        capacity[u][v] = c;
    }
}
int bfs(){
    parent.assign(n+1,-1);
    parent[s] = -2;
    queue<pair<int,int>> q;
    q.push({s,INT_MAX});
    while (!q.empty())
    {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();
        for(int next : adj[cur]){
            if(parent[next] == -1 && capacity[cur][next] > 0){
                parent[next] = cur;
                int new_flow = min(capacity[cur][next],flow);
                if(next == t) return new_flow;
                q.push({next,new_flow});
            }
        }
    }
    return 0;
    
}
int solve(){
    int max_flow = 0;
    int new_flow;
    while ( (new_flow = bfs()) > 0)
    {
        max_flow += new_flow;
        int cur = t;
        while (cur != s)
        {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return max_flow;
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    cout << solve();
}