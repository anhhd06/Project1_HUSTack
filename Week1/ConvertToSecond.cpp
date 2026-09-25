#include<bits/stdc++.h>
using namespace std;
string s;
void input(){
    cin >> s;
}
int solve(){
    int seconds = 0;
    int n = int(s.size());
    if( n != 8 || isdigit(s[0])!=1 || isdigit(s[1])!=1 || s[2]!=':' || isdigit(s[3])!=1 || isdigit(s[4])!=1 || s[5]!=':' || isdigit(s[6])!=1 || isdigit(s[7])!=1 )
        return -1;
    int hours = stoi( s.substr(0,2) );
    if( hours >=0 && hours <= 23) seconds += hours*3600;
    else return -1;
    int minutes = stoi( s.substr(3,2) );
    if(minutes >= 0 && minutes <=59 ) seconds+=minutes*60;
    else return -1;
    int secondss = stoi(s.substr(6,2));
    if( secondss >=0 && secondss <= 59) seconds+=secondss;
    else return -1;
    return seconds;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    int output = solve();
    if( output == -1) cout<< "INCORRECT";
    else cout << output ;

}