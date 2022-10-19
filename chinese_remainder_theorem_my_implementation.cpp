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

const ll MAX = 1e8;

ll mark[MAX];

void sieve(ll limit){
    mark[0] = mark[1] = 1;
    for(ll i = 2; i*i <= limit; i++){
        if(!mark[i]){
            for(ll j = i+i; j < limit; j+=i){
                mark[j] = 1;
            }
        }
    }
}

ll phi(ll n)
{
    ll ret = n;
    for(ll i = 2; i*i <= n; i++){
        if(n % i == 0){
            ret -= (ret/i);  // it simply means ret*(1 - 1/i)
            while(n % i == 0) {
                n /= i;
            }
        }
    }
    if(n > 1){ // which means n is a prime number
        ret -= (ret/n); 
    }
    return ret;
}
ll bigMod(ll a, ll b, ll M){
    if(b == 0) return 1 % M;

    ll x = bigMod(a, b/2, M);

    if(b % 2 == 1){
        return (x*x*a) % M;
    }

    return (x*x) % M;
}

ll inverse(ll a, ll m)
{
    if(__gcd(a, m) != 1) return -1; // not possible
    if(!mark[m]){ // m is prime
        return bigMod(a, m-2, m);
    }
    else{
        return bigMod(a, phi(m)-1, m);
    }
}


ll getChineseX(ll a1, ll m1, ll a2, ll m2){

    // get p and q;

    ll p = inverse(m1, m2);
    ll q = inverse(m2, m1);

    ll m = m1*m2;

    return ((((a1 * m2) % m) * q) % m + (((a2 * m1) % m) * p) % m) % m;

}


ll getXCRT(vector < ll > a, vector < ll > m){
    ll n = a.size();

    ll x = getChineseX(a[0], m[0], a[1], m[1]);

    for(ll i = 2; i < n; i++){
        x = getChineseX(x, m[i-1]*m[i-2], a[i], m[i]);
    }

    return x;

}

int main(){

    sieve(1000);

    ll n; 
    cin >> n;

    vector < ll > m(n);
    vector < ll > a(n);

    for(ll i = 0; i < n; i++){
        cin >> a[i] >> m[i];
    }

    cout << getXCRT(a, m) << endl;

    return 0;
}
