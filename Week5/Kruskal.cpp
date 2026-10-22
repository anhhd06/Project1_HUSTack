#include<bits/stdc++.h>
using namespace std;
struct edge
{
    int u;
    int v;
    int w;
};
vector<edge> E;
struct DSU
{
    vector<int> parent; // luu cha cua thang i
    vector<int> size; //luu kich thuoc cua tap co tk i
    //khoi tao n tập
    DSU(){

    }
    DSU(int n){
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
        size.assign(n+1,1);
    }
    int find(int u){
        if(u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }
    bool unite(int u,int v){
        u = find(u);
        v = find(v);
        if(u==v) return false;
        if(size[u] >= size[v]){
            parent[v] = u;
            size[u] += size[v];
        }
        else{
            parent[u] = v;
            size[v] += size[u];
        }
        return true;
    }
    bool same(int u,int v){
        return find(u) == find(v);
    }
};
int n,m,sum = 0;
DSU dsu;
void input(){
    cin >> n >> m;
    int u,v,w;
    for(int i=1;i<=m;i++){
        cin >> u >> v >> w;
        E.push_back({u,v,w});
    }
    sort(E.begin(),E.end(),[](const edge & a,const edge &b ){
        return a.w < b.w;
    });
    dsu = DSU(n);
}
void solve(){
    for(int i=0;i<m;i++){
        int u = E[i].u, v = E[i].v, w = E[i].w;
        if(dsu.unite(u,v)){
            sum += w;
        }
    }
    cout << sum;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    solve();
}