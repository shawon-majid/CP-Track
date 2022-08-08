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
    DP Variant 5
Count how many ordered ways are there to make sum of coins equal to n

for example you have to consider 1+2 and 2+1 as same combinations
*/




const int mod = 1e9+7;

vector < int > coins;

int ways[105][1000010];

void calculateWays(int n, int sum){
    memset(ways, 0, sizeof ways);
    for(int i = 1; i <= n; i++){
        ways[i][0] = 1;
    }

    for(int i = 1; i <= n; i++){
        for(int curSum = 0; curSum <= sum; curSum++){

            if(curSum != 0 && curSum - coins[i] >= 0){
                ways[i][curSum] = ways[i][curSum - coins[i]] % mod;    
                if(i != 1){
                    ways[i][curSum] += ways[i-1][curSum] % mod;
                }
            } 
            else if(curSum != 0){
                if(i != 1){
                    ways[i][curSum] = ways[i-1][curSum] % mod;
                }
            }
            
        }
    }
}

int main(){

    int n, x;
    cin >> n >> x;
    coins.resize(n+2);
    for(int i = 1; i <= n; i++){
        cin >> coins[i];
    }

    calculateWays(n, x);

    cout << ways[n][x] % mod << endl;

    return 0;
}