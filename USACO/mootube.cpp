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

struct Edge{

    int u, v, c;

    Edge(int uu, int vv, int cc){
        u = uu; v = vv; c = cc;
    }

};

const int mx = 2e5+10;

vector < int > parent(mx);
vector < int > sz(mx);

void init(int n){
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        sz[i] = 1;
    }
}


int findSet(int a){
    if(parent[a] == a){
        return a;
    }
    parent[a] = findSet(parent[a]);
    return parent[a];
}

void unionSet(int a, int b){
    a = findSet(a);
    b = findSet(b);

    if(a != b){
        if(sz[a] >= sz[b]){
            parent[b] = a;
            sz[a] += sz[b];
        }
        else{
            parent[a] = b;
            sz[b] += sz[a];
        }
    }
}

bool cmp(Edge a, Edge b){
    return a.c > b.c;
}
int main() {

    setIO("mootube");



    int n, q;
    cin >> n >> q;

    init(n);

    vector < Edge > edges;
    set < int > costs;

    for(int i = 0; i < n-1; i++){
        int u, v, c;
        cin >> u >> v >> c;
        edges.push_back(Edge(u, v, c));
        costs.insert(c);
    }

    sort(all(edges), cmp);



    map < int, vector < pair < int, int > > > m;

    vector < int > ans(q);

    for(int i = 0; i < q; i++){
        int k, v;
        cin >> k >> v;

        k = *costs.lower_bound(k);

        m[k].push_back({v, i});
    }


    // TODO: eki cost bar bar thakle

    for(auto e: edges){
        // cout << e.c << "\n";

        unionSet(e.u, e.v);

        if(m.count(e.c)){
            // do work

            for(auto [v, i]: m[e.c]){
                ans[i] = sz[findSet(v)]-1;
            }

            // ans[m[e.c].second] = sz[findSet(m[e.c].first)]-1;
        }

    }

    for(int i = 0; i < q; i++){
        cout << ans[i] << "\n";
    }

    return 0;
}