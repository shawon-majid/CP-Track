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


typedef struct 
{   
    ll u, v, c;

}edge;

const ll inf = 1e18;


int main(){

    ll T, cs = 1;
    cin >> T;
    while(T--){
        ll n;
        cin >> n;
        vector < ll > b(n+1);

        for(ll i = 1; i <= n; i++){
            cin >> b[i];
        }

        ll m;
        cin >> m;

        vector < edge > edges(m);

        for(ll i = 0; i < m; i++){
            ll u, v;
            cin >> u >> v;
            ll c = (b[v] - b[u])*(b[v] - b[u])*(b[v] - b[u]);

            edges[i].u = u;
            edges[i].v = v;
            edges[i].c = c;

        }

        vector < ll > dist(n+1);

        for(ll i = 0; i <= n; i++){
            dist[i] = inf;
        }   


        dist[1] = 0;


        for(int i = 1;i <= n-1; i++){
            for(auto e: edges){
                if(dist[e.u] < inf){
                    if(dist[e.u] + e.c < dist[e.v]){
                        dist[e.v] = dist[e.u] + e.c;
                    }    
                }
            }
        }

        // check for negative cycle and assign the lowest to the negative nodes

        while(1){

            bool any = 0;

            for(auto e: edges){
                if(dist[e.u] < inf){

                    if(dist[e.v] == -inf) continue;

                    if(dist[e.u] + e.c < dist[e.v]){
                        dist[e.v] = -inf;
                        any = 1;
                        break;
                    }
                }
            }

            if(!any) break;
        }

        // for(int i = 1; i <= n; i++){
        //     cout << dist[i] << "\n";
        // }


        cout << "Case "<<cs++<<":\n";

        ll q;
        cin >> q;
        while(q--){
            ll v;
            cin >> v;

            (dist[v] >= 3 && dist[v] != inf ) ? cout << dist[v] << "\n" : cout << "?\n";
        }
    }

    return 0;
}