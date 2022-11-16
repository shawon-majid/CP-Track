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


int main(){

    ll n, m;
    cin >> n >> m;

    string str[n];

    ll dp[n][m];

    memset(dp, 0, sizeof dp);

    for(ll i = 0; i < n; i++){
        cin >> str[i];
    }

    dp[0][0] = 1;

    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){

            if(str[i][j] == '#'){
                dp[i][j] = 0;
                continue;  
            } 


            if(i > 0) dp[i][j] += (dp[i-1][j] % mod);
            if(j > 0) dp[i][j] += (dp[i][j-1] % mod);
        }
    }

    cout << dp[n-1][m-1] % mod << "\n";


    return 0;
}