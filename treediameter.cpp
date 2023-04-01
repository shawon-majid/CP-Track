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

const int MAXN = 1005;

vector<int> adj[MAXN];
int to_leaf[MAXN], max_length[MAXN];

// to_leaf[x] = maximum length of a path from node x to any leaf
// max_length[x] = maximum length of a path that contains node x


void dfs(int u, int p) {
    to_leaf[u] = 0;
    int max1 = 0, max2 = 0;

    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
            to_leaf[u] = max(to_leaf[u], to_leaf[v] + 1);

            if (to_leaf[v] + 1 > max1) {
                max2 = max1;
                max1 = to_leaf[v] + 1;
            } else if (to_leaf[v] + 1 > max2) {
                max2 = to_leaf[v] + 1;
            }
        }
    }

    max_length[u] = max1 + max2;
}


int main() {
    int n;
    cin >> n;

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, max_length[i]);
    }
    cout << ans << endl;

    cout << max_length[3] << "\n";

    return 0;
}
