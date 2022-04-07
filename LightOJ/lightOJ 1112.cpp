//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;

vector <ll> tree;

ll f(ll node, ll nodeLeft, ll nodeRight, ll rangeLeft, ll rangeRight, ll v){
    if(nodeLeft >= rangeLeft and nodeRight <= rangeRight){
        if(v == -1){ // show
            return tree[node];
        }
        else if(v == -2){ // empty the sack and show
            ll val = tree[node];
            tree[node] = 0;
            return val;
        }
        else{ // update the range i.e update the index
            tree[node] += v;
            return tree[node];
        }
    }
    if(nodeLeft > rangeRight or nodeRight < rangeLeft){
        return 0;
    }

    ll lastInLeft = (nodeLeft + nodeRight) / 2;

    ll sum = f(2*node, nodeLeft, lastInLeft, rangeLeft, rangeRight, v) + f(2*node + 1, lastInLeft+1, nodeRight, rangeLeft, rangeRight, v);

    tree[node] = tree[2*node] + tree[2*node + 1];

    return sum;

}



ll showInd();

int main(){

    ll T, cs = 1;
    cin >> T;
    while(T--){
        ll n, q;
        cin >> n >> q;
        vector <ll> ara(n);

        for(ll i = 0; i < n; i++){
            cin >> ara[i];
        }

        while(__builtin_popcount(n) != 1){
            ara.push_back(0);
            n++;
        }

        // build the tree
        tree.resize(4*n);
        for(ll i = 0; i < n; i++){
            tree[n+i] = ara[i];
        }
        for(ll i = n-1; i >= 1; i--){
            tree[i] = tree[2*i] + tree[2*i + 1];
        }

        cout << "Case "<<cs << ":" << endl;
        cs++;
        while(q--){
            ll type;
            cin >> type;
            if(type == 1){
                ll ind;
                cin >> ind;

                cout << f(1, 0, n-1, ind, ind, -2) << endl; 
            }
            else if(type == 2){
                ll ind, v;
                cin >> ind >> v;
                f(1, 0, n-1, ind, ind, v);
            }
            else{
                ll left, right;
                cin >> left >> right;
                cout << f(1, 0, n-1, left, right, -1) << endl;
            }
        }

    }

    return 0;
}