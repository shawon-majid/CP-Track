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

    ll n, k;
    cin >> n >> k;

    vector < ll > h(n+10);

    vector < ll > dp(n+10, LLONG_MAX);

    for(ll i = 1; i <= n; i++){
        cin >> h[i];
    }

    dp[1] = 0;

    for(ll i = 2; i <= n; i++){
        for(ll j = 1; j <= k; j++){
            if(i-j < 1) break;
            dp[i] = min(dp[i], dp[i-j] + abs(h[i] - h[i-j]));
        }
    }

    cout << dp[n] << "\n";


    return 0;
}