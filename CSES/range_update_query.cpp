//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;

vector <ll> tree, lazy;


void rangeUpdate(ll node, ll nodeLeft, ll nodeRight, ll rangeLeft, ll rangeRight, ll value){
    if(nodeRight < rangeLeft or nodeLeft > rangeRight){
        return;
    }
    if(nodeLeft >= rangeLeft and nodeRight <= rangeRight){
        tree[node] = tree[node] + (nodeRight - nodeLeft + 1) * value;
        lazy[node] += value; // not sure
        return;
    }

    ll lastInLeft = (nodeLeft + nodeRight) / 2;

    rangeUpdate(2*node, nodeLeft, lastInLeft, rangeLeft, rangeRight, value);
    rangeUpdate(2*node+1, lastInLeft+1, nodeRight, rangeLeft, rangeRight, value);

}

ll showIndex(ll node, ll nodeLeft, ll nodeRight, ll rangeLeft, ll rangeRight, ll tot){
    if(nodeRight < rangeLeft or nodeLeft > rangeRight){
        return 0;
    }
    if(nodeLeft >= rangeLeft and nodeRight <= rangeRight){
        return tree[node] + tot;
    }

    tot += lazy[node];

    ll lastInLeft = (nodeLeft+nodeRight)/2;

    return showIndex(2*node, nodeLeft, lastInLeft, rangeLeft, rangeRight, tot) + showIndex(2*node + 1, lastInLeft+1, nodeRight, rangeLeft, rangeRight, tot);

}


int main(){

    ll n, q;
    cin >> n >> q;
    vector <ll> ara(n);

    for(auto &x: ara) cin >> x;

    while(__builtin_popcount(n) != 1){
        ara.push_back(0);
        n++;
    }

    // build the tree
    tree.resize(4*n);
    lazy.resize(4*n, 0);

    for(ll i = 0; i < n; i++){
        tree[n+i] = ara[i];
    }

    for(ll i = n-1; i >= 1; i--){
        tree[i] = tree[2*i] + tree[2*i + 1];
    }

    while(q--){
        ll type;
        cin >> type;
        if(type == 1){ // update
            ll left, right, value;
            cin >> left >> right >> value;

            left--;
            right--;

            rangeUpdate(1, 0, n-1, left, right, value);

        }
        else{ // show index
            ll x;
            cin >> x;

            x--;
            cout << showIndex(1, 0, n-1, x, x, 0) << endl;

        }
    }




    return 0;
}