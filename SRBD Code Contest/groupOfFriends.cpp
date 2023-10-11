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

int numberOfComponents = 0;

void makeSet(int v){
    parent[v] = v;
    sz[v] = 1;
    // numberOfComponents++;
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
        // numberOfComponents--;
    }
}


int main(){

    int n;
    cin >> n;




    vector < int > ara(n+1);

    for(int i = 1; i <= n; i++){
        cin >> ara[i];
        makeSet(i);
    }

    map < int, int > fo;

    for(int i = 1; i <= n; i++){

        int x = ara[i];
        // debug(numberOfComponents);
        // if(findSet(i))makeSet(i);

        for(int j = 2; j*j <= x; j++){
            if(x % j == 0){
                if(fo[j] != 0){
                    unionSet(i, fo[j]);
                }
                else{
                    fo[j] = i;
                }
                while(x % j == 0){
                    x /= j;
                }
            }
        }
        if(x > 1){ 
            if(fo[x] != 0){
                unionSet(i, fo[x]);
            }
            else{
                fo[x] = i;
            }

        }

    }


    set < int > ans;

    for(int i = 1; i <= n; i++){

        ans.insert(findSet(i));
    }

    cout << ans.size() << "\n";

    // cout << numberOfComponents << "\n";



    return 0;
}