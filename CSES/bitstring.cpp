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

const ll mod = 1e9+7;

ll power(ll n){
    if(n == 0) return 1;

    ll x = power(n/2) % mod;
    if((n & 1) == 0){ // even   
        return (x*x) % mod;
    }
    else{
        return (((x*x) % mod) * (2 % mod)) % mod;
    }
}

int main(){

    ll n;
    cin >> n;

    cout << power(n) << endl;

    return 0;
}