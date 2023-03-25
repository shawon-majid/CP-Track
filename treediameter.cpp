#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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
