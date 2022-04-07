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


int main() {

    setIO("diamond");

    ll n, k;
    cin >> n >> k;

    vector <ll> ara(n);

    for(auto &x : ara) cin >> x;

    sort(all(ara));
    
    // check the maximum number of diamonds in the first case
    
    ll left = 0, right = -1;
    ll indI, indJ;
    ll ans1 = 0;
    while(right < n){

        ll dif = ara[right+1] - ara[left];

        if(dif <= k){
            // take right
            right++;
            ll temp = right - left + 1;
            if(temp > ans1){
                ans1 = temp;
                indI = left;
                indJ = right;
            }
        }
        else{
            // if i cant take it i've to increase left
            // but if left == right then i have to increase both
            if(left == right){
                left++;
                right++;
            }
            else{
                left++;
            }
        }

    }

    vector <ll> ara2;

    for(ll i = 0; i < n; i++){
        if(i >= indI and i <= indJ){
            continue;
        }
        else{
            ara2.push_back(ara[i]);
        }
    }

    // apply the same thing for ara2

    n = ara2.size();

    left = 0, right = -1;
    ll ans2 = 0;
    while(right < n){

        ll dif = ara2[right+1] - ara2[left];

        if(dif <= k){
            // take right
            right++;
            ll temp = right - left + 1;
            if(temp > ans2){
                ans2 = temp;
                indI = left;
                indJ = right;
            }
        }
        else{
            // if i cant take it i've to increase left
            // but if left == right then i have to increase both
            if(left == right){
                left++;
                right++;
            }
            else{
                left++;
            }
        }

    }

    cout << ans1 + ans2 << endl;
    

    return 0;
}