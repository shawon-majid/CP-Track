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

// if I find the previous number than it won't take any new round 
// but if I do not find the prev number than it'll take new round

int main(){

    int n;

    cin >> n;

    vector< int > ara(n);

    for(auto &x: ara) cin >> x;

    map < int , int > f;
    
    int cnt=0;
    for(int i = 0; i < n; i++){
        if(f[ara[i]-1] == 0){
            cnt++;
        }
        f[ara[i]] = 1;
    }

    cout << cnt << endl;


    return 0;
}