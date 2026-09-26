#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,c;
    cin >> a>>b>>c;
    float denta = b*b - 4*a*c;
    if(denta > 0){
        float x1 = (-b-sqrt(denta))/(2*a);
        float x2 = (-b+sqrt(denta))/(2*a);
        printf("%.2f %.2f",x1,x2);
    }
    else if(denta == 0){
        float x0 = -b/(2*a);
        printf("%.2f",x0);
    }
    else cout << "NO SOLUTION";
}