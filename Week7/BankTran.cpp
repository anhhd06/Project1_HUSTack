#include<bits/stdc++.h>
using namespace std;
int num = 0, total_money = 0,k;
set<string> accounts;
unordered_map<string,int> total_money_tran_from;
unordered_map<string, set<string> > tran ; // Lưu các tài khoản được chuyển khoản đến 
unordered_set< string > check_cycle;
void input(){
    string f_acc,t_acc,money,time,atm;
    cin >> f_acc;
    while (f_acc != "#")
    {
        cin >> t_acc >> money >> time >> atm;
        int tien = stoi(money);
        num ++;
        total_money += tien;
        accounts.insert(f_acc);
        accounts.insert(t_acc);
        tran[f_acc].insert(t_acc);
        total_money_tran_from[f_acc] += tien ;
        cin >> f_acc;
    }  
}
bool Try(int i,string before,string start){ // tim thang thu i , them thang da di qua truoc do
    if(i == k+1){
        if(tran[before].find(start) != tran[before].end()) return true;
        return false;
    }
    for(const string &v : tran[before]){
        if(check_cycle.find(v) == check_cycle.end()){
            check_cycle.insert(v);
            if(Try(i+1,v,start)) return true;
            check_cycle.erase(v);
        }
    }
    return false;
}
void solve(){
    string query;
    cin >> query ;
    while (query != "#")
    {
        if( query == "?number_transactions") cout << num << "\n";
        else if ( query == "?total_money_transaction") cout << total_money << "\n";
        else if ( query == "?list_sorted_accounts"){
            for( string acc : accounts){
                cout << acc << " ";
            }
            cout << "\n";
        }
        else if ( query ==  "?total_money_transaction_from"){
            string acc;
            cin >> acc;
            cout << total_money_tran_from[acc] << "\n";
        }
        else if ( query == "?inspect_cycle"){
            string acc;
            cin >> acc >> k;
            check_cycle.clear();
            check_cycle.insert(acc);
            cout << Try(2,acc,acc) << "\n";

        }
        cin >> query;
    }
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    solve();
}