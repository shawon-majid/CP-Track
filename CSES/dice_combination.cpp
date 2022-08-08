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

const ll mod = 1e9 + 7;
const int mx = 1e6 +10;

int dp[mx];

ll f(ll n){
    if(n == 0) return 1;
    if(n < 0) return 0;
    if(dp[n] != -1){
        return dp[n];
    }

    return dp[n] = ((f(n-1) % mod) + (f(n-2) % mod) + (f(n-3) % mod) + (f(n-4) % mod) + (f(n-5) % mod) + (f(n-6) % mod)) % mod ;
}

int main(){

    ll n;
    cin >> n;

    for(int i = 0; i <= n; i++){
        dp[i] = -1;
    }

    cout << f(n) << endl;

    return 0;
}