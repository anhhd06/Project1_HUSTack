#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,M;
    cin >> n >> M;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a,a+n);
    int i = 0, j = n-1,sum = 0;
    while (i < j)
    {
        if(a[i] + a[j] == M){
            sum ++;
            i++;
            j--;
        }
        else if(a[i] + a[j] > M){
            j--;
        }
        else i++;
    }
    cout << sum;
}