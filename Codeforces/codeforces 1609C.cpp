//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;

const ll mx =  1e6+7;

ll isPrime[mx]; // 0 for prime, 1 for not prime

void sieve(ll n){
    isPrime[0] = 1;
    isPrime[1] = 1;

    for(ll i = 2; i*i <= n; i++){
        if(isPrime[i] == 0){ // its prime
            for(ll j = i*i; j <= n; j += i){
                isPrime[j] = 1;
            }    
        }
    }
}

int main(){

    sieve(1e6);

    ll T;
    cin >> T;
    while(T--){
        ll n, e;
        cin >> n >> e;
        
        vector <ll> ara(n);
        for(auto &x: ara) cin >> x;

        // if i find a prime number i'll check its left and right e places and see if there is 1's


        ll leftDp[n];
        ll rightDp[n];

        // get leftDp
        for(ll i = 0; i < n; i++){
            if(ara[i] == 1){
                leftDp[i] = 1;
                if(i - e >= 0){
                    leftDp[i] += leftDp[i-e];
                }
            }
            else{
                leftDp[i] = 0;
            }
        }


        // get right dp
        for(ll i = n-1; i >= 0; i--){
            if(ara[i] == 1){
                rightDp[i] = 1;
                if(i + e < n){
                    rightDp[i] += rightDp[i+e];
                }
            }
            else{
                rightDp[i] = 0;
            }
        }

        // now calculate
        ll ans = 0;
        for(ll i = 0; i < n; i++){
            if(isPrime[ara[i]] == 0){ // prime
                ll leftOne = 0, rightOne = 0;
                if(i - e >= 0){
                    leftOne = leftDp[i - e];
                }

                if(i + e < n){
                    rightOne = rightDp[i+e];
                }

                ans += leftOne*rightOne + leftOne + rightOne;

            }
        }

        cout << ans << endl;

    }

    return 0;
}