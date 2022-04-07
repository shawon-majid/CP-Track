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
    vector <ll> ara(n+1), pre(n+1);

    for(ll i = 1; i <= n; i++){
        cin >> ara[i];
    }

    pre[0] = 0;
    map <ll, ll> m;
    m[0]++;
    ll ans = 0;
    for(ll i = 1; i <= n; i++){
        pre[i] = pre[i-1] + ara[i];
        // taking care of negative mod
        ll mod = (pre[i] % n + n) % n; 
        if(m.find(mod) != m.end()){
            if(m[mod] == 0) ans++;
            ans += m[mod];

        }
        m[mod]++;
    }

    cout << ans << endl;

    return 0;
}