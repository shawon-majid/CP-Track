//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;

vector <int> tree;


int rangeMin(int node, int nodeLeft, int nodeRight, int rangeLeft, int rangeRight){
    if(nodeLeft >= rangeLeft and nodeRight <= rangeRight){ // completely inside the given range
        return tree[node];
    }
    if(nodeRight < rangeLeft || nodeLeft > rangeRight){ // completely outside the given range
        return INT_MAX;
    }

    int lastInLeft = (nodeLeft + nodeRight)/2;

    return min(rangeMin(2*node, nodeLeft, lastInLeft, rangeLeft, rangeRight) , rangeMin(2*node+1, lastInLeft+1, nodeRight, rangeLeft, rangeRight));
}

void update(int pos, int value, int n){
    tree[n+pos] = value;
    for(int i = (n+pos)/2; i >= 1; i /= 2){
        tree[i] = min(tree[2*i], tree[2*i + 1]);
    }
}



int main(){

    int n, q;
    cin >> n >> q;

    vector <int> ara(n);

    for(auto &x : ara){
        cin >> x;
    }

    //make it power of two

    while(__builtin_popcount(n) != 1){
        ara.push_back(INT_MAX);
        n++;
    }


    // build the tree

    tree.resize(4*n);

    for(int i = 0; i < n; i++){
        tree[n+i] = ara[i];
    }

    for(int i = n-1; i >= 1; i--){
        tree[i] = min(tree[2*i], tree[2*i + 1]);
    }

    while(q--){
        int type;
        cin >> type;
        if(type == 1){ // update
            int pos, value;
            cin >> pos >> value;
            pos--;
            update(pos, value, n);
        }
        else{ // show min
            int left, right;
            cin >> left >> right;
            left--; right--;
            cout << rangeMin(1, 0, n-1, left, right) << endl;
        }
    }


    return 0;
}