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

const ll mx = 505;

vector < ll > adj[mx];

ll graph[mx][mx];
ll vis[mx];


ll bfs(ll source, ll dest, vector < ll > &parent){

    ll bottleneck = LLONG_MAX;

    for(ll i = 1; i <= dest; i++){
        vis[i] = 0;
    }

    vis[source] = 1;

    queue < ll > q;
    q.push(source);

    while(!q.empty()){
        ll u = q.front();
        q.pop();
    
        for(auto v: adj[u]){        
            if(graph[u][v] != 0 && !vis[v]){  
                vis[v] = 1;
                parent[v] = u;
                bottleneck = min(bottleneck, graph[u][v]);
                q.push(v);
                if(v == dest){
                    return bottleneck;
                }
            }
        }

    }

    return 0;
}


ll maximumFlow(ll source, ll dest){

    ll flow = 0;

    while(1){ // while augmenting path remains

        vector < ll > parent(dest+1);
        for(ll i = 1; i <= dest; i++) parent[i] = i;

        ll bottleneck = bfs(source, dest, parent);

        if(bottleneck == 0){ // no augmenting path remains
            break;
        }
        
        // go through the path and update residuals

        ll v = dest;

        // update the graph by using path constructed in bfs

        while(parent[v] != v){

            ll u = parent[v];

            graph[u][v] -= bottleneck;
            graph[v][u] += bottleneck;
            
            v = u;            
        }

        flow += bottleneck;
        
    }


    return flow;


}

int main(){

    ll n, m;
    cin >> n >> m;

    for(ll i = 0; i < m; i++){
        ll u, v, c;
        cin >> u >> v >> c;
        
        adj[u].push_back(v);
        adj[v].push_back(u);

        graph[u][v] += c;
        graph[v][u] = 0;
    }

    cout << maximumFlow(1, n) << "\n";


    return 0;
}