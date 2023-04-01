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

const int mx = 2e5+10;
const int LOG = 18;

int table[mx][LOG];
// [size of array][representative of size of length 2^p]


void build(vector < int > &ara){

    int n = ara.size();

    int lg = log2(n); 

    for(int i = 0; i < n; i++){
        table[i][0] = ara[i];
    }

    for(int j = 1; j <= lg; j++){
        for(int i = 0; i+(1 << j)-1 < n; i++){
            table[i][j] = min(table[i][j-1], table[i + (1 << (j-1))][j-1]);
        }
    }

}

int query(int a, int b){

    int len = b-a+1;
    int k = log2(len);

    return min(table[a][k], table[b-(1 << k)+1][k]);

}

int main(){

    int n, q;
    cin >> n >> q;
    vector < int > ara(n);

    int lg = log2(n);

    int m[n][lg];

    for(int i = 0; i < n; i++){
        cin >> ara[i];
    }

    build(ara);


    while(q--){
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        cout << query(a, b) << "\n";


    }

    return 0;
} 