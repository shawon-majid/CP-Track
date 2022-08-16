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

string clair, bob;

ll n, m;

ll dp[5010][1010];

ll f(ll clairSize, ll bobSize){

    if(clairSize == 0 && bobSize == 0){
        return 1;
    }
    if(bobSize == 0){
        return 1;
    }

    if(clairSize == 0){
        return 0;
    }

    if(dp[clairSize][bobSize] != -1){
        return dp[clairSize][bobSize];
    }

    if(clair[clairSize-1] == bob[bobSize-1]){
        return dp[clairSize][bobSize] = (f(clairSize-1, bobSize-1) % mod + f(clairSize-1, bobSize) % mod) % mod;
    }
    else{
        return dp[clairSize][bobSize] = f(clairSize-1, bobSize) % mod;
    }
    


}


int main(){
    

    while(cin >> clair){
        cin >> bob;

        n = clair.size();
        m = bob.size();

        memset(dp, -1, sizeof(dp));

        cout << f(n, m) << endl;


    }


    return 0;
}