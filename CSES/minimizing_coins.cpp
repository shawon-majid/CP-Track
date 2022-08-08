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

const ll inf = 1e7;
int n;
vector <int> coins;
vector <int> dp;

int f(int sum){
    if(sum < 0) return inf;
    if(sum == 0) return 0;

    if(dp[sum] != -1){
        return dp[sum];
    }

    int mn = INT_MAX;
    for(int i = 0; i < n; i++){
        mn = min(mn, f(sum - coins[i]));
    }

    return dp[sum] = mn + 1;

}

int main(){

    int x;
    cin >> n >> x;

    dp.resize(x+10, -1);


    for(int i = 0; i < n; i++){
        int c;
        cin >> c;

        coins.push_back(c);
    }


    int ans = f(x);
    
    if(ans >= inf){
        cout << -1 << endl;
    }
    else cout << ans << endl;


    return 0;
}