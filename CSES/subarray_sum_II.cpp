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
    ll n, x;
    cin >> n >> x;
    vector <ll> ara(n+1), pre(n+1);
    for(ll i = 1; i <= n; i++){
        cin >> ara[i];
    }
    map <ll, ll> m;
    m[0]++;
    ll ans = 0;
    for(ll i = 1; i <= n; i++){
        pre[i] = pre[i-1] + ara[i];
        ll need = x - pre[i];
        
        if(m.find(-need) != m.end()){
            ans += m[-need];
        }

        m[pre[i]]++;
    }

    cout << ans  << endl;


    return 0;
}