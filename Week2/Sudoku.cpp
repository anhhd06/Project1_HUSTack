#include<bits/stdc++.h>
using namespace std;
int a[9][9];
vector< unordered_set<int> > row(9),col(9),grid(9);
vector< pair<int,int> > empty_cells;
int sum = 0;
void input(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin >> a[i][j];
            if(a[i][j] != 0){
                row[i].insert(a[i][j]);
                col[j].insert(a[i][j]);
                grid[ 3*(i/3)+(j/3) ].insert(a[i][j]);
            }
            else{
                empty_cells.push_back( {i,j} );
            }
        }
    }
}

void Try(int k){
    if(k == empty_cells.size()) {
        sum ++;
        return ;
    }
    int i = empty_cells[k].first, j = empty_cells[k].second;
    for(int x=1;x<=9;x++){
        if( row[i].count(x) == 0 && col[j].count(x) == 0 && grid[ 3*(i/3)+(j/3) ].count(x) == 0){
            a[i][j] = x;
            row[i].insert(x);
            col[j].insert(x);
            grid[ 3*(i/3)+(j/3) ].insert(x);
            Try(k+1);
            a[i][j] = 0;
            row[i].erase(x);
            col[j].erase(x);
            grid[ 3*(i/3)+(j/3) ].erase(x);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    Try(0);
    cout << sum ;

}