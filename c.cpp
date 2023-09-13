//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;


set < pair < int, int > >  adj[10000+7];

const ll inf = 1e17;
int cost[10000+7];

void dijkstra(int source, int n){
    for(int i = 1; i <= n; i++){
        cost[i] = inf;
    }

    cost[source] = 0;

    priority_queue < pair < int, int > > pq;
                     // cost, node

    pq.push({-cost[source], source});

    while(!pq.empty()){
        int currentNode = pq.top().second;
        pq.pop();
        
        for(auto v: adj[currentNode]){   
    
            if( cost[currentNode] + v.first < cost[v.second] ){
                cost[v.second] = cost[currentNode] + v.first;
                pq.push({-cost[v.second], v.second});
            }
        }
    }
}

int main(){

    int T;
    while(T--){
        int n, m, k, s, t;
        cin >> n >> m >> k >> s >> t;

        for(int i = 0; i < m; i++){
            int u, v, c;
            cin >> u >> v >> c; 
            adj[u].push_back({c, v});
        }


        for(int i = 0; i < k; i++){
            int u, v, c;
            cin >> u >> v >> c;



            adj[u].push_back({c, v});
            adj[v].push_back({c, u});
        }

    }




    return 0;
}