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

const int mx = 1e5+10;

vector < int > adj[mx];
vector < int > parent(mx);
vector < int > color(mx, 0);
vector < int > ans;

int cycle_start, cycle_end;
int n, m;

bool dfs(int v) {
    color[v] = 1;
    for (int u : adj[v]) {
        if (color[u] == 0) {
            if (dfs(u))
                return true;
        } else if (color[u] == 1) {
            return true;
        }
    }
    color[v] = 2;
    return false;
}

void dfsTop(int u){
    color[u] = 1;
    for(auto v: adj[u]){
        if(color[v] == 0){
            dfsTop(v);
        }
    }
    ans.push_back(u);
}

void topSort(){
    color.assign(n+5, 0);
    for(int v = 1; v <= n; v++){
        if(color[v] == 0){
            dfsTop(v);
        }
    }

    reverse(all(ans));
}
bool find_cycle() {
    color.assign(n+5, 0);
    parent.assign(n+5, -1);

    for (int v = 1; v <= n; v++) {
        if (color[v] == 0 && dfs(v))
            return true;
    }
    return false;
}


int main(){

    
    cin >> n >> m;
    
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    if(find_cycle()){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        topSort();
        // debug(ans.size());
        for(auto x: ans){
            cout << x << ' ';
        }
        cout << endl;
    }


    return 0;
}