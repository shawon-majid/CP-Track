//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;

const int mx = 2e5+7;
vector <int> adj[mx];

int cnt[mx];




int main(){

    int n;
    cin >> n;

    for(int i = 1; i <= n-1; i++){
        int u, v;
        cin >> u >> v;
    }



    int farthestNode = dfsNode(1, -1);
    int diameter = dfsLenght(farthestNode, -1);

    cout << diameter << endl;

    return 0;
}