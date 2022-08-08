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

int power(int a, int b){
    if(b == 0) return 1;
    if(b == 1) return a;

    int x = power(a, b/2);
    if(b % 2 == 0){
        return x*x;
    }
    else{
        return x*x*a;
    }
}

string makeBin(int n, int length){
    string ans = "";
    while(n){
        if(n % 2 == 0){
            ans.push_back('0');
        }
        else ans.push_back('1');
        n /= 2;
    }
    while(ans.size() != length) ans.push_back('0');
    reverse(all(ans));
    return ans;
}

vector < int > adj[100000];
int vis[100000];


void dfs(int node, int n){
    
    cout << makeBin(node, n) << endl;
    vis[node] = 1;
    for(auto v : adj[node]){
        if(!vis[v]) dfs(v, n);
    }
}

int main(){

    int n;
    cin >> n;


    int tot = power(2, n);

    for(int i = 0; i < tot; i++){
        for(int j = i+1; j < tot; j++){
            if(__builtin_popcount(i^j) == 1){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    dfs(0, n);


    return 0;
}