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
The idea is to find longest path of every node using DFS.
once we found the longest path of any node we can save it to 
dp[node]. Now whenever we come back to this node, we get the
value of longest path and add a one for going to current node
*/



const ll mxSz = 1e5+10;

vector < ll > adj[mxSz];

vector < ll > dp(mxSz);
vector < ll > vis(mxSz);


ll dfs(ll n){

    vis[n] = 1;

    if(dp[n] != -1){
        return dp[n];
    }

    dp[n] = 0;

    for(auto v: adj[n]){
        dp[n] = max(dp[n], dfs(v) + 1);
    }


    return dp[n];


}




int main(){

    ll n, m;
    cin >> n >> m;

    for(ll i = 1; i <= n; i++){
        dp[i] = -1;
    }

    for(ll i = 0; i < m; i++){
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for(ll i = 1; i <= n; i++){
        if(!vis[i]){
            // cout << "ok\n";
            dfs(i);
        }
    }

    ll mx = 0;

    for(ll i = 1; i <= n; i++){
        mx = max(dp[i], mx);
    }

    cout << mx << "\n";



    return 0;
}