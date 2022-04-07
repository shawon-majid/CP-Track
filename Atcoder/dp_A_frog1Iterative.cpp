//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;

const ll mx = 2e5 + 10;


ll n;

vector <ll> ara;

// return value is the minimum differencef

ll dp[mx];


// dhoro amr jana ase je pos-1 e total koto khoros oise aite ar pos-2 te aite koto koros oise
// ekhon jodi ami pos-1 taki pos e aite joto koros + pox-1 er khoros jug kori taile ami total khoros paimu
// ekhon ami same kaj pos-2 er lagi kormu
// minimum ta return kormu

int f(int pos){


    //f(pos-1) -> oilo 
    if(dp[pos] != -1){
        return dp[pos];
    }

    if(pos <= 0){
        return 0;
    }
    if(pos <= 1){
        dp[pos] = (abs(ara[pos] - ara[pos-1]) + f(pos - 1));
    }
    return dp[pos] = min((abs(ara[pos] - ara[pos-1]) + f(pos - 1)), (abs(ara[pos] - ara[pos-2]) + f(pos - 2) ) );
}


int main(){


    cin >> n;

    ara.resize(n);
        
    for(ll i = 0; i <= n; i++) dp[i] = -1;

    for(ll i = 0; i < n; i++){
        cin >> ara[i];
    }

    // age shob n-2 ta dp ready korte hobe 
    // then dp[n-1] return korbo

    dp[0] = 0;
    dp[1] = abs(ara[1]-ara[0]);
    for(int i = 2; i < n; i++){
        dp[i] = min(abs(ara[i] - ara[i-1]) + dp[i-1], abs(ara[i] - ara[i-2]) + dp[i-2]);
    }

    cout << dp[n-1] << endl;

    return 0;
}