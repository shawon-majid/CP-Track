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

// reference: CP handbook

const ll mod = 1e9+7;
const ll base = 347;

ll match(string text, string pattern){

    ll n = text.size();
    ll m = pattern.size();


    // preprocess powers
    vector < ll > p(n+1);
    p[0] = 1;
    for(ll i = 1; i <= n; ++i){
        p[i] = (p[i-1]*base) % mod; 
    }


    // preprocess hashes
    vector < ll > hashT(n);
    hashT[0] = text[0];

    for(ll i = 1; i < n; i++){
        hashT[i] = ((hashT[i-1]*base) % mod + text[i]) % mod;
    }


    vector < ll > hashP(m);
    hashP[0] = pattern[0];

    for(ll i = 1; i < m; i++){
        hashP[i] = ((hashP[i-1]*base) % mod + pattern[i]) % mod;
    }


    for(ll i = 0; i < n-m+1; i++){
        // match hash

        ll b = i+m-1;
        ll a = i;

        ll textHash = (a != 0) ? (hashT[b] - ((hashT[a-1] * p[b-a+1]) % mod) ) : hashT[b];
        if(textHash < 0) textHash += mod;


        if(textHash == hashP[m-1]){
            return i;
        }

    }

    return -1;

}


int main(){


    string text, pattern;

    cin >> text >> pattern;


    cout << match(text, pattern) << "\n";


    return 0;
}