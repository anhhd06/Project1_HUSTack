#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node * left;
    Node * right;
    Node(int k){
        val = k;
        left = NULL;
        right = NULL;
    }
};
void insert(Node * & root,int k){
    if(root == NULL){
        root = new Node(k);
        return ;
    }
    else{
        if( k < root->val){
            insert(root -> left,k);
        }
        else if(k> root->val){
            insert(root->right,k);
        }
        else return;

    }
}
void pre_oder(Node * root){
    if(root!=NULL){
        cout << root->val <<" ";
        pre_oder(root->left);
        pre_oder(root->right);
    }
    else return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string type;
    cin >> type;
    int k;
    Node * root = NULL;
    while(type!="#"){
        cin >> k;
        insert(root,k);
        cin >> type;
    }
    pre_oder(root);

}