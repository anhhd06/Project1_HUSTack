#include<bits/stdc++.h>
using namespace std;
unordered_set<int> check;
const int N=1e8;
int a[N];
int n;
void input(){
    cin >> n;
}
void Try(int k){
    if(k==n+1){
        for(int i=1;i<=n;i++){
            cout << a[i] << " ";
        }
        cout<<endl;
    }
    for(int i=1;i<=n;i++){
        if(check.count(i) == 0){
            a[k] = i;
            check.insert(i);
            Try(k+1);
            check.erase(i);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    Try(1);
}