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

vector < int > adj[100006];
int vis[100006]; // 0
//
// unordered_map < int, vector <int > > adj;
int level[100006];
int parent[100006];

void bfs(int source){

    queue < int > q;
    q.push(source);
    vis[source] = 1;
    level[source] = 1;

    // cout << source << endl;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i];
            if(!vis[v]){
                vis[v] = 1;
                parent[v] = u;
                level[v] = level[u] + 1;
                // cout << v << endl;
                q.push(v);
            }
        }
    }

}


int main(){

    int n, e;
    cin >> n >> e;

    // memset(vis, 0, sizeof vis);

    for(int i = 0; i < e; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs(1);

    if(vis[n]){
        cout << level[n] << endl;
        vector < int > ans;
        int currentNode = n;
        ans.push_back(n);
        while(1){
            currentNode = parent[currentNode];
            ans.push_back(currentNode);
            if(currentNode == 1){
                break;
            }
            
        }
        // ans.push_back(1);
        reverse(all(ans));

        for(auto x: ans) cout << x << ' ';
        cout << endl;

    }
    else{
        cout << "IMPOSSIBLE" << endl; 
    }

    return 0;
}