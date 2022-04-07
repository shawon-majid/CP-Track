//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef unsigned long long ull;
typedef long long ll;


int main(){

    ll T;
    cin >> T;
    while(T--){
        ll row, col;
        cin >> row >> col;
        if(row == col){
            cout << row*(row-1) + 1 << endl;
        }
        else if(row > col){
            ll corner = row*(row-1) + 1;
            if(row % 2 == 0){
                cout << corner + (row - col) << endl;
            }
            else{
                cout << corner - (row - col) << endl;
            }
        }
        else{ // col > row
            ll corner = col*(col-1) + 1;
            if(col % 2 == 0){
                cout << corner - (col - row) << endl;
            }
            else{
                cout << corner + (col - row) << endl;
            }
        }
    }


    return 0;
}