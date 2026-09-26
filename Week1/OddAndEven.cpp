#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N];
int n,odd = 0,even = 0;
void input(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(a[i] % 2 == 0) even++;
        else odd++;
    }
    cout<< odd <<" "<<even ;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    
}