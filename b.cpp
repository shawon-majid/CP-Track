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


int g[1005][1005];

int f(int x, int n, int m, int maxSoFar, int minSoFar){
    if(x == n-1){
        // terminal case

        int a = INT_MAX;

        // cout << "At n-1\n";
        // debug(maxSoFar);
        // debug(minSoFar);
        // cout << "\n";

        for(int i = 0; i < m; i++){
            // maxSoFar = 
            // minSoFar =
            // debug(max(maxSoFar, g[x][i]));
            // debug(min(minSoFar, g[x][i]));

            a = min(a, max(maxSoFar, g[x][i]) -   min(minSoFar, g[x][i]));
            // debug(a);

        }

        // debug(maxSoFar);
        // debug(minSoFar);

        // min(ans, f(x+1, n, m, min(minSoFar, g[x][i]), max(maxSoFar, g[x][i])));

        return a;
    }

    int ans = INT_MAX;

    // for(int i = 0; i < m; i++){
    //     maxSoFar = max(maxSoFar, g[x][i]);
    //     minSoFar = min(minSoFar, g[x][i]);
    // }

    // if(x == 1){
    //     // cout << "at 1\n";
    //     // debug(minSoFar);
    //     // debug(maxSoFar);
    //     // cout << "\n";
    // }


    for(int i = 0; i < m; i++){
        ans = min(ans, f(x+1, n, m, max(maxSoFar, g[x][i]), min(minSoFar, g[x][i])));
    }

    return ans;

}


int main(){


    int n, m;
    cin >> n >> m;

    // int g[n][m];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> g[i][j];
        }
    }

    cout << f(0, n, m, INT_MIN, INT_MAX) << "\n";


    return 0;
}