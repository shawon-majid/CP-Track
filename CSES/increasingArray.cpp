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


int main(){

    ll n;
    cin >> n;
    vector < ll> ara(n);
    for(auto &x: ara) cin >> x;

    ll prev = 0;
    ll ans = 0;
    for(auto x: ara){
        if(prev > x){
            ans += (prev-x);
        }
        else{
            prev = x;    
        }
        
    }

    cout << ans << endl;


    return 0;
}