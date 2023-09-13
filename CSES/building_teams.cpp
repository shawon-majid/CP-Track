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


const int mx = 1e5+10;

vector < int > adj[mx];
vector < int > vis(mx), color(mx);


bool dfs(int node, int assignedColor){
  
    vis[node] = 1;
    color[node] = assignedColor;
    int nextColor = (assignedColor == 1) ? 2 : 1;

    for(int neighbor: adj[node]){
        if(!vis[neighbor]){
            if(!dfs(neighbor, nextColor)){
                return false;
            }
        }
        else{
            if(color[neighbor] == assignedColor) return false;
        }
    } 
    return true;
}


int main(){

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);


    }


    bool possible = 1;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            possible &= dfs(i, 1);
        }
    }

    if(possible){
        for(int i = 1; i <= n; i++){
            cout << color[i] << " ";
        }
        cout << "\n";
    }
    else{
        cout << "IMPOSSIBLE\n";
    }


    return 0;
}






