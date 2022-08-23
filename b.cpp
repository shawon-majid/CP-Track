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

const int mx = 1e6+10;

vector < ll > ara(mx); // speed / distance per second 

int main(){

    fastIO

    ll n, m, q;

    cin >> n >> m >> q;

    

    for(ll i = 0; i < n; i++){
        cin >> ara[i];
    }

    while(q--){
        ll p, k;
        cin >> p >> k;

        k--;

        ll speed = ara[k];

        ll distance = speed*p; // maybe unsigned needed

        ll rem = distance % (2*m);

        if(rem <= m){
            cout << rem << '\n';
        }
        else{
            cout << 2*m  - rem << '\n';
        }

    }

    return 0;
}