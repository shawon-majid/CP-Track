//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef unsigned long long ull;
typedef long long ll;

const ll mx = 1e8;
const ll sz = 1e3+10;

ll onColumn[sz];

ll n, m;

ll dp[sz][sz];

ll f(ll r, ll c){

    // base cases

    if(r >= n || r < 0){
        return mx;
    }

    if(dp[r][c] != -1){
        return dp[r][c];
    }


    if(c == m-1){
        return dp[r][c] = abs(r - onColumn[c]);
    }




    ll op1 = f(r, c+1) + abs(r - onColumn[c]);
    ll op2 = f(r+1, c+1) + abs(r - onColumn[c]);
    ll op3 = f(r-1, c+1) + abs(r - onColumn[c]);


    return dp[r][c] = min(op1, min(op2, op3));


}

int main(){

    cin >> n >> m;

    ll grid[n][m];


    memset(dp, -1, sizeof dp);

    
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 1) onColumn[j] = i;
        }
    }


    ll ans = mx;

    for(ll i = 0; i < n; i++){

        ans = min(ans, f(i, 0) + abs(i - onColumn[0]));
    }


    cout << ans << "\n";


    return 0;
}