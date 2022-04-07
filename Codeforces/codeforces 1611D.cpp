//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;

const int mx = 2e5 + 7;

//vector <int> adj[mx];

unordered_map <int, vector <int> > adj;

vector <int> level(mx), vis(mx);

void bfs(int source){
    level[source] = 1;
    vis[source] = 1;
    queue <int> q;
    q.push(source);

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v: adj[u]){
            if(!vis[v]){
                vis[v] = 1;
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
}


int main(){

    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;

        // get the tree

        map < pair <int, int> , int > cost;

        int root;

        vector <int> parent(n+1);
        for(int i = 1; i <= n; i++){
            int x;
            cin >> x;

            if(x == i){
                root = i;
                continue;
            }

            parent[i] = x;

            adj[i].push_back(x);
            adj[x].push_back(i);

            cost[{x, i}] = 1;
            cost[{i, x}] = 1;

        }

        // assign levels i.e. distance from the root
        
        bfs(root);

        vector <int> p(n+1);

        for(int i = 1; i <= n; i++){
            cin >> p[i];
        }

        if(root != p[1]){
            cout << -1 << endl;
        }
        else{
            int curMax = 0;
            for(int i = 2; i <= n; i++){
                int need = curMax+1;
                level[p[i]] = level[parent[p[i]]] + 1;
                if(level[p[i]] >= need){ // no problems keep it up
                    curMax = level[p[i]];
                }
                else{
                    int increase = need - level[p[i]];
                    level[p[i]] = need;
                    curMax = need;
                    cost[{parent[p[i]], p[i]}] += increase;
                }
            }

            bool ok = 1;
            for(int i = 1; i <= n; i++){
                if(level[parent[i]] >= level[i]){
                    ok = 0;
                }
            }
            
            if(ok){
                for(int i = 1; i <= n; i++){
                    if(i != root){
                        cout << cost[{parent[i], i}] << " ";
                    }
                    else{
                        cout << 0 << " ";
                    }
                }
                cout << endl;    
            }
            else{
                //assert(ok);
                cout << -1 << endl;
            }
            
        }

        
        
        adj.clear();
        level.clear();
        vis.clear();
    }

    return 0;
}