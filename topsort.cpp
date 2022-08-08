//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;

int n;


vector < int > adj[5000]; // max unique node
vector < int > ans;
vector < bool > visited;

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
    ans.push_back(v);
}

void topological_sort() {
    visited.assign(n, false);
    ans.clear();
    for (int i = 1; i <= n; ++i) {
        if (!visited[i])
            dfs(i);
    }
    reverse(ans.begin(), ans.end());
}

int main(){


	int T;
	cin >> T;

	while(T--){
		cin >> n;
		int m = (n*(n-1))/2;
		map < pair < int, int > , int > mp;


		for(int i = 0; i < m; i++){
			int u, v, w;
			cin >> u >> v >> w;
			if(u == w){
				adj[v].push_back(u);
			}
			else if(v == w){
				adj[u].push_back(v);
			}
			else{
				adj[u].push_back(v);
				adj[v].push_back(u);
				mp[{u, v}] = 1;
				mp[{v, u}] = 1;
			}

		}

		topological_sort();

		vector < int > strength(n+1, 0);
		int st = 1;
		for(int i = 0; i < ans.size()-1; i++){
			// debug(i);
			// debug(st);
			// debug(ans[i]);
			if(mp[{ans[i], ans[i+1]}] == 1){
				// debug(ans[i]);
				// debug(ans[i+1]);
				strength[ans[i]] = st;
				strength[ans[i+1]] = st;
				i++;
			} 
			else{
				strength[ans[i]] = st;
			}
			st++;
		}

		for(int i = 1; i <= n; i++){
			if(strength[i] == 0){
				strength[i] = st;
			}
		}


		for(int i = 1; i <= n; i++){
			cout << strength[i] << ' ';
		}
		cout << endl;



	}

	 

    return 0;
}