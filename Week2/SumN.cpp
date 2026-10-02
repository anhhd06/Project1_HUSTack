#include<bits/stdc++.h>
using namespace std;
const int N = 21;
int a[N],n,sum = 0;
void input(){
    cin >> n;
    a[0] = 1;
}
void Try(int k){
    if(sum == n){
        for(int i=1;i<k;i++){
            cout<< a[i] <<" ";
        }
        cout<<endl;
        return;
    }
    for(int x = a[k-1];x<=n;x++){
        a[k] = x;
        sum+=x;
        if(sum > n){
            sum -=x;
            break;
        }
        Try(k+1);
        a[k] = 0;
        sum-=x;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    Try(1);
}