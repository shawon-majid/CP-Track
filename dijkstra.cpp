//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;


// floyd warshal algo

vector < pair < int, int > >  adj[50000];

const int inf = 1e8;
int cost[50000];



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

    int s;
    cin >> s;
    while(s--){
        int n;
        cin >> n;

        map <string, int> indexOf;

        for(int i = 1; i <= n; i++){
            string name; // name of the city
            cin >> name;
            indexOf[name] = i;

            int p; // number of neighbours
            cin >> p;
            while(p--){
                int v, c;
                cin >> v >> c;

                adj[i].push_back({c, v});

                adj[v].push_back({c, i}); // don't know whether to add or not <>;
            }
        }

        int r;
        cin >> r;
        while(r--){
            string source, destination;
            cin >> source >> destination;

            dijkstra(indexOf[source], n);

            cout << cost[indexOf[destination]] << endl;


        }
    }

    return 0;
}