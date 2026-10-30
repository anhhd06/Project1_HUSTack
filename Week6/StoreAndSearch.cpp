#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int N,K;
struct g
{
    int n; // so nút
    int m; // so cạnh
    vector< vector <int> > edge;// cac canh ke
    vector< vector<bool> > mat;// danh dau cac canh noi voi nhau
    vector<ull> node_hash;
    ull graph_hash;

    g(int n,int m){
        this->n = n;
        this->m = m;
        edge.assign(n+1,vector<int>());
        mat.assign(n+1,vector<bool> (n+1,false));
        node_hash.assign(n+1,0);
    }
    // tinh hash cua tung node và cả đồ thị
    void tinh_hash(){
        graph_hash = 0;
        vector<ull> temp;
        for(int u=1;u<=n;u++){
            ull bac_cua_u = edge[u].size();
            ull bac_cua_bb = 0;
            for( int v : edge[u]){
                bac_cua_bb += edge[v].size()*edge[v].size();
            }
            node_hash[u] = 10000*bac_cua_u + bac_cua_bb;
            temp.push_back(node_hash[u]);
        }
        sort(temp.begin(),temp.end());
        for(ull x : temp) graph_hash = graph_hash* 10003 + x;
    }

};
vector<g> G;
vector<g> H;
void input(){
    cin >> N;
    int n,m,u,v;
    for(int i=0;i<N;i++){
        cin >> n >> m;
        G.push_back(g(n,m));
        for(int j=1;j<=m;j++){
            cin >> u >> v;
            G[i].edge[u].push_back(v);
            G[i].edge[v].push_back(u);
            G[i].mat[u][v] = true;
            G[i].mat[v][u] = true;
        }
        G[i].tinh_hash();
    }
    string a;
    cin >> a;
    cin >> K; 
    for(int i=0;i<K;i++){
        cin >> n >> m;
        H.push_back(g(n,m));
        for(int j=1;j<=m;j++){
            cin >> u >> v;
            H[i].edge[u].push_back(v);
            H[i].edge[v].push_back(u);
            H[i].mat[u][v] = true;
            H[i].mat[v][u] = true;
        }
        H[i].tinh_hash();
    }
}

int map_to[1005]; //lưu xem thằng u của dinh của thằng A nối với thằng nào của B
bool used[1005]; // lưu xem thằng v đã được dùng chưa
bool assembly(int u, const g & A, const g & B){
    if(u > A.n) return true;

    for(int v = 1 ;v <= B.n ; v++ ){
        if(used[v]) continue;
        if(A.node_hash[u] != B.node_hash[v]) continue;
        bool hople = true;
        // check xem mấy thằng ghép trước đó đã đúng với u và v chưa
        for(int i=1;i<u;i++){
            int v_da_ghep = map_to[i];
            if(A.mat[u][i] != B.mat[v][v_da_ghep]){
                hople = false;
                break;
            }
        }
        if(hople){
            map_to[u] = v;
            used[v] = true;
            if(assembly(u+1,A,B)) return true;

            used[v] = false;
        }
    }
    return false;
}
// Hàm kiểm tra xem 2 thằng có cùng cấu trúc k
bool same(const g & A, const g & B){
    if(A.n != B.n || A.m != B.m ) return false;
    if(A.graph_hash != B.graph_hash) return false;
    // làm sạch mảng map va used để ghép
    for(int i=1;i<=B.n;i++){
        map_to[i] = 0;
        used[i] = false;
    }
    return assembly(1,A,B);
}
void solve(){
    for(int i=0;i<K;i++){
        int check = false;
        for(int j=0;j<N;j++){
            if(same(H[i],G[j])){
                check = true;
                break;
            }
        }
        cout << check << endl;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    solve();
}