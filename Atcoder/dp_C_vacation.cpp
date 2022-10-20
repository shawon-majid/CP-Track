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

last = 1,2,3, -1



f(n, last) {
    

    if(last == -1){
        3 options
        max(f(n+1, 1), f(n+1, 2), f(n+1, 3))
    }
    else if(last == 1){
        max(f(n+1, 2), f(n+1, 3))
    }
    else if(last == 2){
        max(f(n+1, 1), f(n+1, 3))
    }
    else{
        max(f(n+1, 1), f(n+1, 2))
    }

    max( f(n-1)        
}

dp[pos][last]
dp[pos][1] = max(dp[pos-1][2], dp[pos-1][3]);
do[pos][2] = max(dp[pos-1][1], dp[pos-1][3]);
dp[pos][3] = max(dp[pos-1][1], dp[pos-1][2]);



*/
int main(){

    int n;
    cin >> n;
    vector < int > a(n+1), b(n+1), c(n+1);

    for(int i = 1; i <= n; i++){
        cin >> a[i] >> b[i] >> c[i];
    }

    int dp[n+1][4];

    memset(dp, -1, sizeof dp);

    dp[1][1] = a[1];
    dp[1][2] = b[1];
    dp[1][3] = c[1];

    for(int i = 2; i <= n; i++){
        
        dp[i][1] = max(dp[i][j], max(dp[i-1][2], dp[i-1][3]) + a[i]);
        dp[i][2] = max(dp[i][j], max(dp[i-1][1], dp[i-1][3]) + b[i]);
        dp[i][3] = max(dp[i][j], max(dp[i-1][1], dp[i-1][2]) + c[i]);
        
    }

    cout << max(dp[n][1], max(dp[n][2], dp[n][3])) << "\n";

    


    return 0;
}