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

const ll mx = 1e5+10;

const ll INF = 1e16;

vector < pair < ll, ll > > adj[mx];
            // cost, node
vector < ll > dist(mx);
vector < ll > vis(mx, 0);

void dijkstra(ll source, ll n){
    priority_queue < pair < ll, ll > > ms;
                   //cost, node

    for(ll i = 1; i <= n; i++){
        dist[i] = INF;
    }

    dist[source] = 0;

    ms.push({-0, source});

    while(!ms.empty()){
        ll u = (ms.top()).second;
        ms.pop();
        // if(vis[u]) continue;

        // vis[u] = 1;

        for(auto v: adj[u]){
            // shob che kom cost or ta paisi
            if(dist[u] + v.first < dist[v.second]){
                dist[v.second] = dist[u] + v.first;
                ms.push({-v.first, v.second});
            }
        }
    }

}

int main(){

    ll n, m;
    cin >> n >> m;

    for(ll i = 0; i < m; i++){
        ll a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({c, b});
    }

    dijkstra(1, n);

    for(ll i = 1; i <= n; i++){
        cout << dist[i] << " ";
    }
    cout << "\n";

    return 0;
}