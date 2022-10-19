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

const ll lmx = 1e18+1;

const ll mx = 1e5+10;


/*

def: dp[v] = minimum weight needed to get value v

*/

ll dp[mx];



int main(){

    int n, W;
    cin >> n >> W;
    vector < ll > values(n+1), weights(n+1);


    for(int i = 0; i <= mx; i++) dp[i] = lmx;

    dp[0] = 0;

    for(int i = 1; i <= n; i++){
        cin >> weights[i] >> values[i];
    }

    for(int i = 1; i <= n; i++){
        for(int v = mx; v >= 0; v--){
            if(v - values[i] >= 0 ) dp[v] = min(dp[v], dp[v - values[i]] + weights[i]);
        }
    }


    ll ans = -1;

    for(int v = 0; v <= mx; v++){
        if(dp[v] < lmx && dp[v] <= W){
            ans = v;
        }
    }


    cout  << ans << "\n";




    return 0;
}