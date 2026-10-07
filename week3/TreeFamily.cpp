#include<bits/stdc++.h>
using namespace std;
map <string , set<string> > tree;
void input(){
    string child,parent;
    cin >> child;
    while(child != "***"){
        cin >> parent;
        tree[parent].insert(child);
        cin >> child;
    }
}
int Sum(string a){
    int sum = 0;
    if(tree.count(a)==1){
        for(const auto & x :tree[a]){
            sum += 1 + Sum(x);
        }
    }
    return sum;
}

int gene(string a){
    int sum = 0;
    if(tree.count(a) == 1){
        for(const auto & x : tree[a]){
            sum = max(sum,gene(x));
        }
        sum += 1;
    }
    return sum;
}
void solve(){
    string cmd,param;
    cin >> cmd;
    while ( cmd != "***")
    {
        if( cmd == "descendants"){
            cin >> param;
            int sum = Sum(param);
            cout << sum << endl;
        }
        else if( cmd == "generation"){
            cin >> param;
            int Gene = gene(param);
            cout << Gene <<endl;
        }
        cin >> cmd;
    }
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    solve();
}