#include<bits/stdc++.h>
using namespace std;
const int N = 20;
int a[N],n;

void Stepk(int k){
    if(k==n+1){
        for(int i=1;i<=n;i++){
            cout << a[i];
        }
        cout << endl;
    }
    else{
        for(int i=0;i<=1;i++){
            a[k] = i;
            Stepk(k+1);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    Stepk(1);
}