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
    vector <ll> tree;
    vector <ll> ara;
    STree(vector < ll > pArray){
        ara = pArray;
        ll n = ara.size();
        tree.resize(2*n);
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
    
    ll query(ll node, ll nodeLeft, ll nodeRight, ll queryLeft, ll queryRight){
        if((nodeLeft >= queryLeft) and (nodeRight <= queryRight)){
            return tree[node];
        }
        if((nodeLeft > queryRight) || (nodeRight < queryLeft)){
            return 0;
        }
        ll lastInLeft = nodeLeft + (nodeRight - nodeLeft)/2;
        return query(2*node, nodeLeft, lastInLeft, queryLeft, queryRight) 
             + query(2*node+1, lastInLeft+1, nodeRight, queryLeft, queryRight); 
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
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        cout << t.query(1, 0, n-1, a, b) << endl;    
    }


    return 0;
}           