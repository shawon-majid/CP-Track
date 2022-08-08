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

ll power(ll a, ll b){
    if(b == 0) return 1;
    if(b == 1) return a;

    ll x = power(a, b/2);
    if( b % 2 == 0){
        return x*x;
    }
    else{
        return x*x*a;
    }
}

ll findNumberOfDigit(ll k){
    ll base = 0;
    for(ll i = 1; i <= 18; i++){
        ll x = i*power(10, i-1);
        x = base + 9*x;
        if((k / x) == 0){
            // debug(x);
            return i;
        }

        // debug(x);
        base = x;
    }
    return -1;
}

ll f(ll k){
    ll numberOfDigit = findNumberOfDigit(k); 
    // debug(numberOfDigit);   
    ll elapsed;
    ll base = 0;
    for(ll i = 0; i < numberOfDigit; i++){
        elapsed = i*power(10, i-1);
        elapsed = base + 9*elapsed;
        base = elapsed;
    }
    // debug(elapsed);
    elapsed++;
    k -= elapsed;
    // debug(k);

    if(k < 0) return 9;
    ll pos = k % numberOfDigit;
    ll increase = k/numberOfDigit;

    ll desiredNumber = power(10, numberOfDigit-1) + increase;

    while(pos < (numberOfDigit-1)){
        desiredNumber /= 10;
        pos++;
    }

    return desiredNumber%10;

}
// expected : 7
// found : 6


int main(){

    ll T;
    cin >> T;
    while(T--){
        ll k;
        cin >> k;
        cout << f(k) << endl;
    }

    return 0;
}