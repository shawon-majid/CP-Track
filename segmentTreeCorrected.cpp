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

struct STree{   

    // the array size must be 2^n for using this structure
    // make it sure before passing the array

    vector <ll> tree;
    vector <ll> ara;
    vector <ll> lazy;

    STree(vector < ll > pArray){
        ara = pArray;
        ll n = ara.size();
        tree.resize(2*n);
        lazy.resize(2*n,0);
        build(n);
    }   

    // build the tree
    void build(ll n){
        for(ll i = 0; i < n; i++){
            tree[n+i] = ara[i]; 
        }
        for(ll i = n-1; i >= 1; i--){
            tree[i] = tree[2*i] + tree[(2*i)+1];
        }
    }


    void updateOne(ll node, ll nodeLeft, ll nodeRight, ll rangeLeft, ll rangeRight, ll x){

        if((nodeLeft >= rangeLeft) and (nodeRight <= rangeRight)){
            tree[node] = x; // means the index
            return;
        }
        if((nodeLeft > rangeRight) || (nodeRight < rangeLeft)){
            return;
        }
        ll lastInLeft = nodeLeft + (nodeRight - nodeLeft)/2;
        updateOne(2*node, nodeLeft, lastInLeft, rangeLeft, rangeRight, x); 
        updateOne(2*node+1, lastInLeft+1, nodeRight, rangeLeft, rangeRight, x); 

        tree[node] = tree[2*node] + tree[2*node+1];
    }

    void updateRange(ll node, ll nodeLeft, ll nodeRight, ll rangeLeft, ll rangeRight, ll x){
        
        ll numberOfLeaf = nodeRight - nodeLeft + 1;

        if(nodeLeft >= rangeLeft && nodeRight <= rangeRight){
            
            tree[node] = x*numberOfLeaf;
            lazy[node] = x;
            return;
        }

        if((nodeLeft > rangeRight) || (nodeRight < rangeLeft)){
            return;
        }

        ll lastInLeft = nodeLeft + (nodeRight - nodeLeft)/2;
        updateRange(2*node, nodeLeft, lastInLeft, rangeLeft, rangeRight, x);
        updateRange(2*node+1, lastInLeft+1, nodeRight, rangeLeft, rangeRight, x);

        tree[node] = tree[2*node] + tree[2*node+1] + numberOfLeaf*lazy[node]; 
    }


    ll query(ll node, ll nodeLeft, ll nodeRight, ll queryLeft, ll queryRight, ll carry){
        ll numberOfLeaf = nodeRight - nodeLeft + 1;

        if((nodeLeft >= queryLeft) and (nodeRight <= queryRight)){
            return tree[node] + (numberOfLeaf* carry);
        }
        if((nodeLeft > queryRight) || (nodeRight < queryLeft)){
            return 0;
        }
        ll lastInLeft = nodeLeft + (nodeRight - nodeLeft)/2;
        return query(2*node, nodeLeft, lastInLeft, queryLeft, queryRight,  carry + lazy[node]) 
             + query(2*node+1, lastInLeft+1, nodeRight, queryLeft, queryRight, carry + lazy[node]); 
    }
};


int main(){

    ll n, q;
    cin >> n >> q;

    vector < ll > ara(n);

    for(auto &x: ara){
        cin >> x;
    }
    while(__builtin_popcount(n) != 1){
        ara.push_back(0);
        n++;
    }
    

    STree t(ara);

    while(q--){
        ll type, a, b;
        cin >> type;
        if(type == 1){
            ll k, u;
            cin >> k >> u;
            k--;
            t.updateRange(1, 0, n-1, k, k, u);
        }
        else{
            cin >> a >> b;    
            a--;
            b--;
            cout << t.query(1, 0, n-1, a, b, 0) << endl;    
        }
        
    }


    return 0;
}           