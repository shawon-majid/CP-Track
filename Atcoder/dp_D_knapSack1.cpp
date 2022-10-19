//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef unsigned long long ull;
typedef long long ll;

ll dp[105][100005];


/*

    f(n, remainingWeight) as the highest value after going n positions
    
    

    // options for getting dp[n][w]
    1. don't take the element so, the result will be just ase previous one i.e. dp[n-1][w]
    2. take the element so, for getting 'w' we have to come from w-weight[n] and add the value
       which means, we can get dp[n-1][w - weight[n]]+value[n]
    
    for all dp[1--n][w--W]
    
    dp[n][w] = max(dp[n-1][w], dp[n-1][w-weight[n]] + value[n]);
    
    

*/

int main(){


    ll n, W;
    cin >> n >> W;
    vector < ll > weights(n+1), values(n+1);

    for(ll i = 1; i <= n; i++){
        cin >> weights[i] >> values[i];
    }

    // setting base cases
    for(ll i = 0; i <= n; i++) dp[i][0] = 0;
    for(ll w = 0; w <= W; w++) dp[0][w] = 0;

    for(ll i = 1; i <= n; i++){
        for(ll w = 0; w <= W; w++){
            if(weights[i] <= w ) dp[i][w] = max(dp[i-1][w], dp[i-1][w - weights[i]] + values[i]);
            else dp[i][w] = dp[i-1][w];
        }
    }

    cout << dp[n][W] << "\n";

    return 0;
}