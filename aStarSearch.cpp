//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef unsigned long long ull;
typedef long long ll;

const int inf = 2e5+10;

map < string, vector < pair < int, string > > > adj;
                            // cost, node
set < string > nodes;


int aStarSearch(string source, string goal, map < string, int > heuristics){

    map < string, int > dist;
    map < string, int > fngn;

    for(auto x: nodes){
        dist[x] = inf;
    }

    dist[source] = 0;



    priority_queue < pair < int, string > > pq;

    pq.push({-(dist[source] + heuristics[source]), source});

    fngn[source] = dist[source] + heuristics[source];
    bool found = 0;

    while(!pq.empty()){
        string u = pq.top().second;
        // int cost = pq.top().first;

        pq.pop();

        for(auto [cost, v]: adj[u]){
            if(dist[u] + cost + heuristics[v] < dist[v] + heuristics[v] ){

                dist[v] = dist[u] + cost;
                pq.push({-(dist[v]+heuristics[v]) , v});
                fngn[v] = (dist[v]+heuristics[v]);
                if(v == goal){
                    found = 1;
                    break;
                }
            }
        }
        if(found) break;
    }

    cout << "\n";
    cout <<setw(10) << left << "Node | Cost | f(n)+g(n)\n";
    for(auto x: nodes){
        if(dist[x] != inf)  cout<< x <<":\t\t" << dist[x] << "\t\t" << fngn[x] << "\n";
        else cout<< x <<": not visited\n";

    }


    return dist[goal];

}

int main(){

    cout << "Enter number of nodes: ";
    int n; cin >> n;

    cout << "Enter the heuristics for each node(node heuristics): ";


    map < string, int > heuristics;
    for(int i = 0;i < n; ++i){
        string u;
        int hc;
        cin >> u >> hc;
        heuristics[u] = hc;

        nodes.insert(u);
    }

    cout << "Enter number of edges: ";
    int e;
    cin >> e;

    cout << "Enter the Edges: ";

    for(int i = 0; i < e; i++){
        string u, v;
        int c;
        cin >> u >> v >> c;

        adj[u].push_back({c, v});

    }

    cout << "Enter source and goal: ";

    string source, goal;
    cin >> source >> goal;

    int c = aStarSearch(source, goal, heuristics);

    cout << c << "\n";


    return 0;
}