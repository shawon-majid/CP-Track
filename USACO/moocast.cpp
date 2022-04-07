#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
#define all(x) begin(x), end(x)
using pi = pair<int,int>;
#define F first
#define S second
#define debug(x) cout << '>' << #x << " : " << x << endl;

void setIO(string name = "") { // name is nonempty for USACO file I/O

    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output

    // alternatively, cin.tie(0)->sync_with_stdio(0);

    if (name.size()) {

        freopen((name+".in").c_str(), "r", stdin); // see Input & Output

        freopen((name+".out").c_str(), "w", stdout);

    }

}



int n;
const int mx = 1e5;

vector <int> adj[mx];

vector <bool> vis;

int dfs(int source){
    int cnt = 1;
    vis[source] = 1;

    for(auto v:adj[source]){
        if(!vis[v]){
            cnt += dfs(v);
        }
    }

    return cnt;
}


int dfsCon(){

    int ans = INT_MIN;

    for(int i = 0; i < n; i++){
    	vis.assign(n, false);
        if(!vis[i]){
            ans = max(ans, dfs(i));
        }
    }
    return ans;
}



int main() {

    setIO("moocast");
    cin >> n;

    vector < pair < pair <int, int>, int > > cows(n);
    
    for(int i = 0; i < n; i++){
        cin >> cows[i].first.first >> cows[i].first.second >> cows[i].second;
    }
    
    for(int i = 0; i < n; i++){
        ll pSquare = cows[i].second*cows[i].second;
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            ll xSquare = (cows[i].first.first - cows[j].first.first)*(cows[i].first.first - cows[j].first.first);
            ll ySquare = (cows[i].first.second - cows[j].first.second)*(cows[i].first.second - cows[j].first.second);
            ll difSqaure = xSquare + ySquare;
            if(pSquare >= difSqaure){
                adj[i].push_back(j);
            }
        }
    }

    cout << dfsCon() << endl;

    return 0;
}