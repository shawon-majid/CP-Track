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

const ll mod = 1e9+7;

vector <ll> coins, dp;

ll f(ll sum){
    // base cases
    if(sum == 0){
        return 1;
    }
    if(sum < 0){
        return 0;
    }
    if(dp[sum] != -1){
        return dp[sum];
    }
    ll ans = 0;
    for(ll i = 0; i < coins.size(); i++){
        ans += f(sum - coins[i]) % mod; 
    }

    return dp[sum] = (ans % mod);
}


int main(){

    ll n, x;
    cin >> n >> x;

    dp.resize(x+10, -1);

    for(ll i = 0; i < n; i++){
        ll c;
        cin >> c;
        coins.push_back(c);
    } 

    cout << f(x) << endl;


    return 0;
}