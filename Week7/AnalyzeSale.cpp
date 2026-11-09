#include<bits/stdc++.h>
using namespace std;
int total  =  0 , revenue = 0; // Tổng số đơn hàng,doanh thu
int rev_at_sec[86405]; // Lưu doanh thu tại giây thứ i
int pref[86406]; //Tổng doanh thu từ 0 đến giây i
unordered_map<string,int> Shop_revenue; // Lưu tổng doanh thu của shop
unordered_map< string , int > Cus_Shop; //Lưu số lượng mà khánh Cus mua cho Shop

int timetoSec(string time){
    int sec = 0;
    sec += 3600* ( 10*(time[0] - '0') + (time[1] - '0') );
    sec += 60 * ( 10*(time[3] - '0') + (time[4] - '0') );
    sec += 10*(time[6] - '0') + (time[7] - '0');
    return sec;
}
void input(){
    string CusID,ProID,Price,ShopID,TimePoint;
    cin >> CusID;
    while (CusID != "#")
    {
        cin >> ProID >> Price >> ShopID >> TimePoint;
        int price = stoi(Price);
        // Bán đơn thanh công
        total ++ ; // Tăng số đơn
        revenue += price; //Tăng tổng doanh thu
        Shop_revenue[ShopID] += price; // Tăng doanh thu cho shop
        Cus_Shop[CusID + "#" + ShopID] += price;
        rev_at_sec[timetoSec(TimePoint)] += price;
        cin >> CusID;
    }  
}

void solve(){
    // Tinh doanh thu tu 0 den i
    for(int i=1;i < 86405;i++){
        pref[i] = pref[i-1] + rev_at_sec[i];
    }
    string query;
    cin >> query ;
    while (query != "#")
    {
        if( query == "?total_number_orders") cout << total << "\n";
        else if ( query == "?total_revenue") cout << revenue << "\n";
        else if ( query == "?revenue_of_shop"){
            string ShopID;
            cin >> ShopID;
            cout << Shop_revenue[ShopID] << "\n";
        }
        else if ( query ==  "?total_consume_of_customer_shop"){
            string Cus,Shop;
            cin >> Cus >> Shop;
            cout << Cus_Shop[Cus + "#" + Shop] << "\n";
        }
        else if ( query == "?total_revenue_in_period"){
            string fTime,tTime;
            cin >> fTime >> tTime;
            cout << pref[timetoSec(tTime)] - pref[timetoSec(fTime)] + rev_at_sec[timetoSec(fTime)] << "\n";
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