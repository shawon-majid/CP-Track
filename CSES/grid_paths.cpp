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

    
/*  
    idea of dp is simple, we can reach grid[i][j] from 
    grid[i-1][j] or grid[i][j-1], so, total number of 
    way for reaching grid[i][j] = grid[i-1][j] + grid[i][j-1]


    so, we define dp[i][j] = number of ways to reach (i, j)

    we just need to check the trap.
    and base cases are tricky for trap

*/



const ll mod = 1e9+7;


int main(){

    ll n;
    cin >> n;


    string str[n];
    ll dp[n][n];

    for(ll i = 0; i <n; i++){
        cin >> str[i];
    }

    (str[0][0] == '*') ? dp[0][0] = 0 : dp[0][0] = 1;

    for(ll i = 1; i < n; i++){
        (str[i][0] != '*') ? dp[i][0] = dp[i-1][0] : dp[i][0] = 0;
        (str[0][i] != '*') ? dp[0][i] = dp[0][i-1] : dp[0][i] = 0;
    }


    for(ll i = 1; i < n; i++){
        for(ll j = 1; j < n; j++){

            if(str[i-1][j] == '*') dp[i-1][j] = 0;
            if(str[i][j-1] == '*') dp[i][j-1] = 0;

            if(str[i][j] != '*')dp[i][j] = ((dp[i-1][j] % mod) + (dp[i][j-1] % mod)) % mod;
            else dp[i][j] = 0;
        }
    }

    cout << dp[n-1][n-1] % mod<< "\n";

    return 0;
}