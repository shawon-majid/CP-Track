#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mx = 2e5+10;

vector < ll > parent(mx);
vector < ll > sz(mx);

ll numberOfComponents;

void init(ll n){
    for(ll i = 1; i <= n; i++){
        parent[i] = i;
        sz[i] = 1;
    }
}


ll findSet(ll a){
    if(parent[a] == a){
        return a;
    }
    parent[a] = findSet(parent[a]);
    return parent[a];
}

void unionSet(ll a, ll b){
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
        numberOfComponents--;
    }
}


int main(){
    ll n, m;
    cin >> n >> m;

    vector < pair < ll, pair < ll, ll > >  > edges;

    for(ll i = 0; i < m; i++){
        ll u, v, c;
        cin >> u >> v >> c;

        edges.push_back({c, {u, v}});


    }

    sort(edges.begin(), edges.end());

    ll cnt = 0;
    ll ans = 0;

    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    for(ll i = 0; i < m; i++){
        if(cnt == n-1){
            break;
        }

        ll u = edges[i].second.first;
        ll v = edges[i].second.second;

        u = findSet(u);
        v = findSet(v);

        if(u != v){
            unionSet(u, v);
            cnt++;
            ans += edges[i].first;
        }

    }

    if(cnt == n-1) cout << ans << endl;
    else cout << "IMPOSSIBLE" << endl;

}