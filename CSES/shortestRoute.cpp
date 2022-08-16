#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


const ll mx = 2e5+7;


vector <ll> dist(mx); 
vector <ll> vis(mx);


vector < pair < ll, ll > > adj[mx];
            // cost, dest


void dijkstra(ll source, ll n){

    for(ll i = 1; i <= n; i++){
        dist[i] = LLONG_MAX;
    }

    dist[source] = 0;

    priority_queue < pair < ll, ll > > q;

    q.push({-0, source});


    while(!q.empty()){

        pair < ll, ll > u = q.top();

        q.pop();

        // cost, vertex

        if(vis[u.second]){
            continue;
        }

        vis[u.second] = 1;

        for(auto v: adj[u.second]){

            if(dist[u.second] + v.first < dist[v.second]){
                q.push({-v.first, v.second});
                dist[v.second] = dist[u.second] + v.first;
            }

        }


    }


}

int main(){
    
    ll n, m;

    cin >> n >> m;

    for(ll i = 0; i < m; ++i){
        ll u, v, c;
        cin >> u >> v >> c;
        
        adj[u].push_back({c, v});

    }   


    dijkstra(1, n);


    for(ll i = 1; i <= n; i++){
        cout << dist[i] << " ";
    }




}