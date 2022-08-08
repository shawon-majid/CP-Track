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
    DP variant 4
Count how many ways are there to make sum of coins equal to n
Now, you cannot use any coin more than once

*/

vector <int> coins;
int dp[10000][100];

int ways(int n, int i){
    if(n == 0) return 1;
    else if(n != 0 and i < 0) return 0;
    else if(dp[n][i] != -1) return dp[n][i];
    return dp[n][i] = ways(n, i-1) + ways(n-coins[i], i-1);
}

int main(){

    int m;
    cin >> m;
    coins.resize(m+1);
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < m; ++i){
        cin >> coins[i];
    }

    int n;
    cin >> n;

    cout << ways(n, m-1) << endl;



    return 0;
}