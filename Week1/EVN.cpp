#include<bits/stdc++.h>
using namespace std;
int n;
int mucbac6(){
    int tien = 0;
    if( n > 400) tien = (n-400)*3015+ 291900 + 261200 + 207400 + 1786* 50 + 1728* 50;
    else if( n > 300) tien = (n-300)* 2919 + 261200 + 207400 + 1786* 50 + 1728* 50;
    else if( n > 200 ) tien = (n-200) * 2612 + 207400 + 1786* 50 + 1728* 50;
    else if ( n > 100) tien = (n-100) * 2074 + 1786* 50 + 1728* 50;
    else if (n > 50) tien = (n-50)*1786 + 1728* 50;
    else tien = n*1728;
    return tien;
}
int mucbac5(){
    int tien;
    if (n <= 100) {
        tien = n * 1728; 
    } 
    else if (n <= 200) {
        tien = 100 * 1728 + (n - 100) * 2074; 
    } 
    else if (n <= 400) {
        tien = 100 * 1728 + 100 * 2074 + (n - 200) * 2612; 
    } 
    else if (n <= 700) {
        tien = 100 * 1728 + 100 * 2074 + 200 * 2612 + (n - 400) * 3111; 
    } 
    else {
        tien = 100 * 1728 + 100 * 2074 + 200 * 2612 + 300 * 3111 + (n - 700) * 3457; 
    }
    return tien;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    double output = -1.1*( mucbac6()-mucbac5() );
    if(output == 0.0) output =0.0;
    printf("%.2f",output );

}