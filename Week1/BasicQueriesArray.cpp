#include<bits/stdc++.h>
using namespace std;
const int N =1e5 + 5;
int a[N], n, Max = -1001, Min = 1001, i, j, sum=0, max_seg = -1001 ;
string req;
void input(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if( a[i] > Max) Max = a[i];
        if( a[i] < Min ) Min = a[i];
        sum+=a[i];
    }
}
void solve(){
    cin >> req;
    if( req == "*"){
        while(1){
            cin >> req ;
            if( req == "find-max" ) cout << Max <<endl;
            else if ( req == "find-min") cout << Min << endl;
            else if ( req =="sum") cout << sum <<endl;
            else if ( req == "find-max-segment" ) {
                cin >> i >> j;
                for ( int k=i;k<=j;k++){
                    if( a[k] > max_seg ) max_seg = a[k];
                }
                cout << max_seg <<endl;
                max_seg = -1001;
            }
            else break;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    solve();
    return 0;

}