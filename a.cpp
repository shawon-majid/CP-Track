//Bismiintahir Rahman-ir Rahim
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef unsigned long long ull;
typedef long long ll;

int tree[505][2025];

int query(int node, int nodeLeft, int nodeRight, int queryLeft, int queryRight, int i){

    if((nodeLeft >= queryLeft) and (nodeRight <= queryRight)){
        return tree[i][node];
    }
    if((nodeLeft > queryRight) || (nodeRight < queryLeft)){
        return 0;
    }
    int lastInLeft = nodeLeft + (nodeRight - nodeLeft)/2;
    return max(query(2*node, nodeLeft, lastInLeft, queryLeft, queryRight, i) 
         ,query(2*node+1, lastInLeft+1, nodeRight, queryLeft, queryRight, i)); 
}

int main(){

    fastIO

    int T, cs = 1;
    cin >> T;   
    while(T--){
        int n, q;
        cin >> n >> q;

        int st = n;

        while(__builtin_popcount(st) != 1){
            st++;
        }
    

        for(int i = 0; i < n; i++){
            
            for(int j = 0; j < n; j++){
                cin >> tree[i][st+j];
            }

            for(int j = st-1; j >= 1; j--){

                int child1 = 2*j;
                int child2 = child1+1;

                if(child1 < (st+n) && child2 < (st+n)){
                    tree[i][j] = max(tree[i][child1], tree[i][child2]);
                }
                else if(child1 < (st+n)){
                    tree[i][j] = tree[i][child1];
                }
            }
            
            
        }

        cout << "Case " <<cs++ << ":\n";


        while(q--){
            int x, y, s;
            cin >> x >> y >> s;

            x--;
            y--;

            int ans = -1;

            for(int i = x; i < x+s; i++){
                ans = max(ans, query(1, 0, n-1, y, y+s-1, i));
            }

            cout << ans << "\n";

        }   

    }

    return 0;
}