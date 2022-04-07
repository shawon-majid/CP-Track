//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;

ll choose2(ll n){
    return (n*(n-1))/2;
}

int main(){

    ll T;
    cin >> T;
    while(T--){
        ll n;

        cin >> n;
        vector <ll> ara(n);

        for(auto &x: ara) cin >> x;

        sort(all(ara));

        ll sum = accumulate(all(ara), 0LL);
        ll ans = 0;

        double d = (double)sum / n;

        d = d*(n-2);

        map <ll, ll> m;

        if(sum % n != 0 and d != floor(d) ){
            cout << 0 << endl;
        }
        else{
            double avg = (double)sum / n;
            ll need = (ll)((double)sum - avg*(double)(n-2));

            for(ll i = 0; i < n; i++){
                ll pneed = need - ara[i];
                if(m.find(pneed) != m.end()){
                    ans+= m[pneed];  
                } 
                m[ara[i]]++;
            }
            
            cout << ans << endl;
        }

    }

    return 0;
}