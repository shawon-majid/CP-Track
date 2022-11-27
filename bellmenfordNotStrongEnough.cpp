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

const int mx = 2005;
const int inf = 1e8+7;

// vector < int > adj[mx];
map < int, vector < int > > adj;
vector < int > dist;
vector < int > vis;

struct Edge{
    int u, v, c;
};

vector < Edge > edges;

set < int > ans;

void bellmanFord(int source, int n){
    dist[source] = 0;

    vector < int > parent(n);

    int lastNode;

    for(int i = 0; i < n; i++){

        lastNode = -1;

        for(auto e: edges){
            if(dist[e.u] < inf){
                if(dist[e.u] + e.c < dist[e.v]){
                    dist[e.v] = dist[e.u] + e.c;
                    parent[e.v] = e.u;
                    lastNode = e.v;
                }
            }
        }
    }


    if(lastNode != -1){
        int nodeInCycle = lastNode;

        for(int i = 0; i < n; i++){
            nodeInCycle = parent[nodeInCycle];
        }

        int first = 1;

        int curr = nodeInCycle;

        while(1){
            // debug(curr);
            // debug(nodeInCycle);
            if(curr == nodeInCycle && !first){
                break;
            }
            ans.insert(curr);
            first = 0;
            curr = parent[curr];
        }

    }
}


void dfs(int source){

    vis[source] = 1;

    ans.insert(source);

    for(auto v: adj[source]){
        if(!vis[v]){
            dfs(v);
        }
    }

}

int main(){

    int T, cs = 1;
    cin >> T;
    while(T--){
        int n, m;
        cin >> n >> m;

        dist.resize(n+1);
        vis.resize(n+1, 0);
        edges.resize(m);

        for(int i = 0; i < n; i++){
            dist[i] = inf;
        }

        

        for(int i = 0; i < m; i++){
            cin >> edges[i].u >> edges[i].v >> edges[i].c;
            adj[edges[i].v].push_back(edges[i].u);
        }

        bellmanFord(0, n);

        cout << "Case "<<cs++ << ": ";

        if(ans.size()){


            // cout << "cycle : ";
            // for(auto x: ans){
            //     cout << x << " ";
            // }
            // cout << "\n";


            for(int i = 0; i < n; i++){
                vis[i] = 0;
            }

            dfs(*ans.begin());

            for(auto it = ans.begin(); it != ans.end(); it++){
                if(it == prev(ans.end(), 1)){
                    cout << *it << '\n';
                }    
                else cout << *it << " ";
            }
            
        }
        else{
            cout << "impossible\n";
        }

        

        dist.clear();
        edges.clear();
        ans.clear();
        vis.clear();
        adj.clear();

    }

    return 0;
}