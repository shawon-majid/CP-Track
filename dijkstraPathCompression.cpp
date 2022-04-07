//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;


unordered_map < ll, vector < pair < ll, ll> > > adj;

const ll inf = LLONG_MAX;
ll cost[500000];
vector < ll > p(500000, 0);


void dijkstra(ll source, ll n){
    for(ll i = 1; i <= n; i++){
        cost[i] = inf;
    }

    cost[source] = 0;

    priority_queue < pair < ll, ll > > pq;
                     // cost, node

    pq.push({-cost[source], source});

    while(!pq.empty()){
        ll currentNode = pq.top().second;
        pq.pop();

        for(auto v: adj[currentNode]){   
    
            if( cost[currentNode] + v.first < cost[v.second] ){
                cost[v.second] = cost[currentNode] + v.first;

                p[v.second] = currentNode;

                pq.push({-cost[v.second], v.second});
            }
        }
    }


}

vector<ll> restore_path(ll s, ll t) {
    vector<ll> path;

    for (ll v = t; v != s; v = p[v]){
        path.push_back(v);
        if(v == 0){
            path.clear();
            return path;
        }
    }
    path.push_back(s);

    reverse(path.begin(), path.end());
    return path;
}

int main(){

    
    ll n, e;
    cin >> n >> e;

    for(ll i = 0; i < e; i++){
        ll u, v, x;
        cin >> u >> v >> x;
        adj[u].push_back({x, v});
        adj[v].push_back({x, u}); // don't know wheather to add or not
    }

    dijkstra(1, n);

    vector <ll> path = restore_path(1, n);

    if(path.size() == 0){
        cout << -1 << endl;
    }
    else{
        for(auto x: path){
            cout << x << " ";
        }
        cout << endl;    
    }

    

    return 0;
}