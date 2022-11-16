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

This problem has a observation. Which is,

Taro wants to maximize X-Y
Jiro wants to minimize X-Y

X+Y = C (sum of all ara)

So X-Y = X-(C-X) = 2X - C

So, if we maximize X, we will maximize X-Y

    if we minimize X, we will minimize X-Y

So, Taro wants to maximize X
    Jiro wants to minimize X

Now, we will use dp[L][R][TURN] as
the maximum value of x in L to R range if TURN is 0 (0 stands for Taro)
the minimum value fo x in L to R range if TURN is 1 (1 stands for Jiro)

Now, the answer will be, 2*X - C


*/
    
const ll mx = 3005;

ll dp[mx][mx][2];

int main(){

    ll n;
    cin >> n;

    vector < ll > ara(n);
    ll sum = 0;

    for(ll i = 0; i < n; i++){
        cin >> ara[i];
        sum += ara[i];
    }


    // for only 1 element
    for(ll i = 0; i < n; i++){
        dp[i][i][0] = ara[i]; // if Taro plays, then, he will add the element in X
        dp[i][i][1] = 0; // if Jiro plays, then he will add the element if Y, so X will 0
    }


    
    for(ll L = n-1; L >= 0; L--){
        for(ll R = L+1; R < n; R++){
            dp[L][R][0] = max(ara[L] + dp[L+1][R][1], ara[R] + dp[L][R-1][1]);
            dp[L][R][1] = min(dp[L+1][R][0], dp[L][R-1][0]);
        }
    }



    ll X = dp[0][n-1][0];


    cout << 2*X - sum << "\n";


    return 0;
}