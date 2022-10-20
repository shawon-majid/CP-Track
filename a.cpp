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




note: on the first attempt I wrote code like this:
    for(i : 1 to n){
        for(v : 0 to mx){
            if( v[i] can be placed ) dp[v] = min(dp[v], dp[v-values[i]] + w[i])
        }
    }

    but the problem is that, in this approach we can take one element multiple times
    for example,
    if the given case was:
    3 8
    3 30
    4 50
    5 60

    first we calculate dp[30] = min(dp[30], dp[30-values[i]] + w[i]) 
                              = min(lmx, dp[30-30] + 3) = 3

    then when we reach dp[60] = min(lmx, dp[60-30] + 3)
                              = 6
    but this is not possible because this problem is 0-1 knapsack

    
    then I reversed the order of taking v as:
        for(v : mx to 0)
    
    in that way we would calculate dp[60] before dp[30] is ready
    so, in that way, we cannot take dp[60] as 6

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