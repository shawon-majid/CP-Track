//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;

const int mx = 1e5+7;
vector <int> adj[mx];

vector <int> level(mx);

int mxLevel = 0;
int farthestNode = -1;


void dfsNode(int curNode, int prevNode){
    level[curNode] = level[prevNode] + 1;
    if(level[curNode] > mxLevel){
        mxLevel = level[curNode];
        farthestNode = curNode;
    }
    for(auto v: adj[curNode]){
        if(v != prevNode){
            dfsNode(v, curNode);
        }
    }
}

int dfsLenght(int curNode, int prevNode){
    int cnt = 1;
    int maxx = 0;    

    for(auto v: adj[curNode]){
        if(v != prevNode){
            maxx = max(maxx, dfsLenght(v, curNode));

        }
    }
    cnt += maxx;
    return cnt;
}

int main(){

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfsNode(1, 0);

    //debug(farthestNode);

    int latency = dfsLenght(farthestNode, 0);

    cout << latency-1 << endl;

    return 0;
}