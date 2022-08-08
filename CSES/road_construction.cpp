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

const int mx = 2e5+10;

vector < int > parent(mx);
vector < int > sz(mx);

int numberOfComponents;

void init(int n){
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        sz[i] = 1;
    }
}


int findSet(int a){
    if(parent[a] == a){
        return a;
    }
    parent[a] = findSet(parent[a]);
    return parent[a];
}

void unionSet(int a, int b){
    a = findSet(a);
    b = findSet(b);

    if(a != b){
        if(sz[a] >= sz[b]){
            parent[b] = a;
            sz[a] += sz[b];
        }
        else{
            parent[a] = b;
            sz[b] += sz[a];
        }
        numberOfComponents--;
    }
}

int main(){

    int n, m;
    cin >> n >> m;

    init(n);
    numberOfComponents = n;

    int mx = 1;

    for(int i=0; i < m; i++){
        int a, b;
        cin >> a >> b;
        unionSet(a, b);
        if(sz[parent[a]] > mx || sz[parent[b]] > mx){
            mx = max(sz[parent[a]], sz[parent[b]]);
        }

        cout << numberOfComponents << ' ' << mx << endl;
    }

    return 0;
}