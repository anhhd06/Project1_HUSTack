#include<bits/stdc++.h>
using namespace std;
struct Node{
    int id;
    vector<Node*> children;
    Node(int _id){
        id = _id;
    }
};
unordered_set <int> s;
unordered_map < int , Node*> m;
Node * Root = NULL;
// chen u vao cuoi cung cua danh sach con cua v
void insert(int u,int v){
    if(s.count(u) == 0 && s.count(v)==1){
        Node * newnode = new Node(u);
        m[v]->children.push_back(newnode);
        m[u] = newnode;
        s.insert(u);

    }
}
void PreOrder(Node * root){
    if(root!=NULL){
        cout << root -> id << " ";
        for(const auto & x: root ->children){
            PreOrder(x);
        }
    }
}
void PostOrder(Node * root){
    if(root!=NULL){
        for(const auto & x:root->children){
            PostOrder(x);
        }
        cout << root->id << " ";
    }
}
void InOrder(Node * root){
    if(root!=NULL){
        if(root->children.size()>0){
            InOrder(root->children[0]);
            cout << root -> id <<" ";
            if(root->children.size()>1){
                for(int i=1;i<root->children.size();i++){
                    InOrder(root->children[i]);
                }
            }
        }
        else cout << root -> id << " ";
    }
}
void solve(){
    string type;
    int k,u,v;
    cin >> type;
    while (type != "*"){
        if(type == "MakeRoot"){
            cin >> k;
            Root = new Node(k);
            m[k] = Root;
            s.insert(k);
        }
        else if(type == "Insert"){
            cin >> u >> v;
            insert(u,v);
        }
        else if(type == "InOrder"){
            InOrder(Root);
            cout << endl;

        }
        else if(type == "PreOrder"){
            PreOrder(Root);
            cout << endl;
        }
        else if(type == "PostOrder"){
            PostOrder(Root);
            cout << endl;
        }
        cin >> type;
    }
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();

}