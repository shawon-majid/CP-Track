//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;

int times = 0;
vector <int> adj[500];

vector <int> starttimes(500);
vector <int> endtimes(500);

vector <int> vis(500);

void dfs(int node){

	times++;
	vis[node] = 1;

	starttimes[node] = times;

	for(auto v: adj[node]){
		if(!vis[v]){
			dfs(v);
		}
	}

	endtimes[node] = times;

}

int main(){

	int n, e;
	cin >> n >> e;

	for(int i = 0; i < e; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}

	dfs(1);

	for(int i = 1; i <= n; i++){
		cout << "node " << i << ": " << starttimes[i] << " | " << endtimes[i] << endl; 
	}




    return 0;
}