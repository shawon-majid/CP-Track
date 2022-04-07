#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
#define all(x) begin(x), end(x)
using pi = pair<int,int>;
#define F first
#define S second
#define debug(x) cout << '>' << #x << " : " << x << endl;

void setIO(string name = "") { // name is nonempty for USACO file I/O

    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output

    // alternatively, cin.tie(0)->sync_with_stdio(0);

    if (name.size()) {

        freopen((name+".in").c_str(), "r", stdin); // see Input & Output

        freopen((name+".out").c_str(), "w", stdout);

    }

}

bool ok(ll radius, ll cows, vector <ll> ara){
    ll n = ara.size();
    ll range = 2*radius;

    ll i = 0, j = 0;
    ll cnt = 0;
    while(i < n and j < n){
        ll dif = ara[j] - ara[i];
        if(dif <= range){
            j++;
        }
        else{
            cnt++;
            i = j;
        }
    }
    cnt++;

    if(cnt <= cows){
        return true;
    }
    else return false;

}


int main() {

    setIO("angry");
    
 	ll n, k;

    cin >> n >> k;

    vector <ll> ara(n);

    for(auto &x: ara) cin >> x;

    sort(all(ara));
    
    ll low = 0, high = ara[n-1] - ara[0];
    ll ans = -1;

    while(low <= high){
        ll mid = low + ((high - low)/2);

        if(ok(mid, k, ara)){
            ans = mid;
            high = mid-1;
        }        
        else{
            low = mid+1;
        }
    }

    cout << ans << endl;

    return 0;
}