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

// generating all the subsequences

// the best way to generate all the subsequence is using bits


int main(){

    ll n;
    cin >> n;
    vector < ll > ara(n);
    ll sum = 0;
    for(ll i = 0; i < n; i++){
        cin >> ara[i];
        sum += ara[i];
    }

    ll ans = LLONG_MAX;
    ll limit = pow(2, n);
    for(ll i = 0; i < limit; i++){
        ll sum1 = 0, sum2 = 0;
        for(ll j = 0; j < n; j++){
            if( (i & (1 << j)) ){ // check if i'th bit set or not set
                sum1 += ara[j];
            }
        }
        sum2 = sum - sum1;
        ans = min(ans, abs(sum1-sum2));
    }

    cout << ans << endl;

    return 0;
}