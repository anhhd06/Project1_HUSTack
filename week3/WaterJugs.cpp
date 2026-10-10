#include<bits/stdc++.h>
using namespace std;
queue < pair<pair<int,int>,int> > q;
set < pair<int,int> > s;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,c;
    cin >> a >> b >> c;
    q.push(  {{0,0},0} );
    s.insert({0,0});
    while (!q.empty())
    {
        pair<pair<int,int>,int> fr = q.front();
        q.pop();
        int x = fr.first.first;
        int y = fr.first.second;
        if(x == c || y == c){
            cout << fr.second;
            return 0;
        }
        else{
            int k = fr.second + 1;
            pair < pair<int,int> , int > ds[6] = {
                {{0,y},k},
                {{x,0},k},
                {{a,y},k},
                {{x,b},k},
                {{x - min(x,b-y),y + min(x,b-y)},k},
                {{x + min(a-x,y),y - min(a-x,y)},k}
            } ;
            for (int i=0 ;i<6;i++){

                if(s.count(ds[i].first)==0){
                    q.push(ds[i]);
                    s.insert(ds[i].first);
                }

            }

        }
        
    }
    cout << -1;


    
}