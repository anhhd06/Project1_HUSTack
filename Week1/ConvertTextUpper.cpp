#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string line;
    while( getline(cin,line) ){
        for( char & c : line){
            c = toupper(c);
        }
        cout << line << endl;
    }
}