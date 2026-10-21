#include<bits/stdc++.h>
using namespace std;
int n,m;
vector <bool> visited;
vector < vector<bool> > E;
stack<int> st;
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
    st.push(1);
    visited[1] = true;
}
void solve(){
    while (!st.empty())
    {
        int top = st.top();
        st.pop();
        cout << top << " ";
        for(int i=1;i<=n;i++){
            if(visited[i] == false && E[top][i]){
                st.push(i);
                visited[i] = true;
                solve();
            }
        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    solve();

}