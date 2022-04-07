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


bool cmp(pair <ll, ll> a, pair <ll, ll> b){
    return a.second > b.second;
}

int main() {

    setIO("rental");

    ll n, m, r;
    cin >> n >> m >> r;

    vector <ll> cows(n);
    vector <pair <ll, ll> > buyers(m);
    vector <ll> rent(r);

    for (ll i = 0; i < n; ++i){
        cin >> cows[i];
    }
    for(ll i = 0; i < m; i++){
        cin >> buyers[i].first >> buyers[i].second;
    }
    for(ll i = 0; i < r; i++){
        cin >> rent[i];
    }
    
    sort(cows.rbegin(), cows.rend());
    sort(all(buyers), cmp);
    sort(rent.rbegin(), rent.rend());

    ll left = 0, right = n-1;
    ll buyersIndex = 0;
    ll rentIndex = 0;
    ll ans = 0;
    while(left <= right){
        ll buyProfit, rentProfit, get;
        if(buyersIndex >= m){
            buyProfit = 0;
        }
        else{
            get = min(cows[left], buyers[buyersIndex].first);
            buyProfit = get*buyers[buyersIndex].second;
        }
        if(rentIndex >= r){
            rentProfit = 0;    
        }
        else{
            rentProfit = rent[rentIndex];
        }
        if(buyProfit >= rentProfit){
            ans += buyProfit;
            debug(buyProfit);
            cows[left] -= get;
            buyers[buyersIndex].first -= get;
            if(cows[left] == 0){
                left++;
            }
            if(buyers[buyersIndex].first == 0){
                buyersIndex++; // check what happens when there are no buyes
            }
        }
        else{
            ans += rentProfit;
            debug(rentProfit);
            right--;
            rentIndex++; // check if there is no rent left
        }
    }

    cout << ans << endl;

    
    return 0;
}
