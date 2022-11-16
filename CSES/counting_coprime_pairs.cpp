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

    vector < ll > ara(n);

    map < ll, ll > cnt;

    for(ll i = 0; i < n; i++){
        cin >> ara[i];
    }

    for(ll i = 0; i < n; i++){
        ll temp = ara[i];

        for(ll j = 2; j*j <= temp; j++){
            if(temp % j == 0){
                while(temp % j == 0){
                    temp /= j;
                }
                cnt[j]++;
            }
        }

        if(temp > 1){
            cnt[temp]++;
        }

    }

    ll ans = 0;

    for(auto x: cnt){
        if(x.second >= 2){
            ans += (x.second*(x.second-1))/2;
        }
    }

    cout << (n*(n-1))/2 - ans << "\n";


    return 0;
}