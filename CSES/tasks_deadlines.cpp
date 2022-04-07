//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;

int main(){

    ll n;

    cin >> n;

    vector < pair <ll, ll> > p(n);

    for(auto &x: p) cin >> x.first >> x.second;

    sort(all(p));
    
    ll ans = 0, t = 0;
    for(int i = 0; i < n; i++){
        t += p[i].first;
        ans += p[i].second - t;
    }

    cout << ans << endl;
    

    return 0;
}