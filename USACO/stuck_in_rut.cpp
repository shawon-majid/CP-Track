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

vector <int> adj[1005];
unordered_map <int, int> vis;


int bfs(int source){
    queue <int> q;
    vis[source] = 1;
    q.push(source);
    int cnt = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        
        for(auto v: adj[u]){
            if(!vis[v]){
                vis[v] = 1;
                q.push(v);
                cnt++;
            }
        }

    }
    return cnt;

}


bool cmp(pair <int, int> a, pair <int, int> b){
    return a.second < b.second;
}


int done[1005];

int main() {

    //setIO("");
    
    int n;
    cin >> n;
    vector <pair <int, int> > north, east;
    map < pair <int, int>, int > id;

    for(int i = 0; i < n; i++){
        char c;
        cin >> c;
        int x, y;
        cin >> x >> y;
        if(c == 'N') north.push_back({x, y});
        else east.push_back({x, y});
        id[{x, y}] = i;
    }

    sort(all(east), cmp);
    sort(all(north));
    
    for(auto x: east){

        for(auto y:north){
            int xDif = y.first - x.first;
            int yDif = x.second - y.second;
    
            if(xDif == yDif){
                continue;
            }
            
            else if((yDif) < (xDif) and yDif > 0){
                if(!done[id[y]] and !done[id[x]]){
                    adj[id[y]].push_back(id[x]);
                    done[id[x]] = 1; 
                }
            }
            else if(yDif > xDif and xDif > 0){
                if(!done[id[x]] and !done[id[y]]){
                    adj[id[x]].push_back(id[y]);
                    done[id[y]] = 1;
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << bfs(i) << endl;
        vis.clear();
    }

    return 0;
}