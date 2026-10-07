#include<bits/stdc++.h>
using namespace std;
unordered_set<int> s;
int n;
struct Node{
    int val;
    Node * next;
    Node(int k){
        val = k;
        next = NULL;
    }
};
Node * Head = NULL;

void input(){
    cin >> n;
    int k;
    Node * curr ;
    for(int i=1;i<=n;i++){
        cin >> k;
        s.insert(k);
        if(Head == NULL){
            Head = new Node(k);
            curr = Head;
        }
        else{
            Node * newnode = new Node(k);
            curr -> next = newnode;
            curr = newnode;
        }

    }
}

//Them vao cuoi ds
void addlast(int k){
    if(s.count(k) == 1) return;
    else{
        if(Head == NULL){
            Head = new Node(k);
        }
        else{
            Node * curr = Head;
            while(curr->next!=NULL){
                curr = curr->next;
            }
            curr -> next = new Node(k);
        }
        s.insert(k);
    }
}
//Them vao dau ds
void addfirst(int k){
    if(s.count(k) == 1) return;
    else{
        if(Head == NULL){
            Head = new Node(k);
        }
        else{
            Node * curr = new Node(k);
            curr -> next = Head;
            Head = curr;
        }
        s.insert(k);
    }
}
//Them u vao sau v
void addafter(int u,int v){
    if(s.count(v) == 1 && s.count(u) == 0){
        Node * curr = Head;
        while (curr -> val != v)
        {
            curr = curr->next;
        }
        Node * newNode = new Node(u);
        newNode ->next  = curr -> next;
        curr -> next = newNode;
        s.insert(u);
    }
}

//Them u vao truoc v
void addbefore(int u,int v){
    if(s.count(v) == 1 && s.count(u) ==0){
        Node* curr = Head;
        if(curr->val == v){
            Node * newnode = new Node(u);
            newnode->next = curr;
            Head = newnode;
        }
        else{
            while(curr->next->val != v){
                curr = curr ->next;
            }
            Node * newnode = new Node(u);
            newnode -> next = curr -> next;
            curr -> next = newnode ;
        }
        s.insert(u);
    }
}
//Loai bo phan tu co key la k
void Remove(int k){
    if(s.count(k)==1){
        if(Head -> val == k){
            Head = Head -> next ;
            s.erase(k);
            return;
        }
        else{
            Node * curr = Head;
            while(curr->next->val != k){
                curr = curr ->next;
            }
            curr ->next = curr ->next->next;
        }
        s.erase(k);
    }
}

void reverse(){
    Node * node1 = NULL;
    Node * node2 = Head ;
    if(Head->next==NULL) return;
    Head = Head -> next;
    while(Head -> next != NULL){
        node2 ->next = node1;
        node1 = node2 ;
        node2 = Head;
        Head = Head->next;
    }
    node2 -> next = node1;
    Head -> next = node2;
}
// in danh sach
void print(){
    Node * curr = Head;
    while(curr!= NULL){
        cout << curr -> val << " ";
        curr = curr ->next;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    string type;
    int k,u,v;
    cin >> type;
    while (type != "#")
    {
        if(type == "addlast"){
            cin >> k;
            addlast(k);
        }
        else if(type == "addfirst"){
            cin >> k;
            addfirst(k);
        }
        else if(type == "addafter"){
            cin >> u >> v;
            addafter(u,v);
        }
        else if( type == "addbefore"){
            cin >> u >> v;
            addbefore(u,v);
        }
        else if( type == "remove"){
            cin >> k;
            Remove(k);
        }
        else if(type == "reverse"){
            reverse();
        }
        cin >> type;
    }
    print();
    
}