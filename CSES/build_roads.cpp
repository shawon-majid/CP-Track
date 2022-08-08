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

void bfs(int source){

    queue < int > q;
    q.push(source);
    vis[source] = 1;
    // level[source] = 0;

    // cout << source << endl;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i];
            if(!vis[v]){
                vis[v] = 1;
                // level[v] = level[u] + 1;
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

    int cnt = 0;
    vector < int > ans;
    for(int i = 1; i <= n; i++){
        if(vis[i] != 1){
            bfs(i);
            cnt++;
            ans.push_back(i);
        }
    }

    cout << cnt-1 << endl;

    for(int i = 0; i < ans.size(); i++){
        if((i == 0)){
            cout << ans[i] << ' ';
        }
        else if(i == ans.size()-1){
            cout << ans[i] << endl;
        }
        else{
            cout << ans[i] << endl;
            cout << ans[i] << ' ';
        }
    }

    return 0;
}