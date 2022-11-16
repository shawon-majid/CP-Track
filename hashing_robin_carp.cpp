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
const ll base = 347;


ll myHash(string str, ll l , ll r){

    ll ret = 0;
    ll p_pow = 1;

    for(ll i = r; i >= l; i--){
        ll val = str[i]- 'a' + 1;
        ret += (val * p_pow) % mod;
        ret = ret % mod;
        p_pow *= base;
    }

    return ret;

}

vector < ll > getHash(string text, ll m){

    ll n = text.size();

    vector < ll > h(n-m+1);

    h[0] = myHash(text, 0, m-1); 


    ll p_pow = 1;
    for(ll i = 1; i <= m-1; i++){
        p_pow = (p_pow * base) % mod;
    }

    for(ll i = 1; i < n-m+1; i++){

        ll val = text[i-1] - 'a' + 1;


        h[i] = (h[i-1] - (val*p_pow)) % mod;
        if(h[i] < 0) h[i] += mod;

        ll val2 = text[i+m-1] - 'a' + 1;

         h[i] = ((h[i] * base) % mod + val2) % mod;
    }

    return h;

}


int match(string text, string pattern){


    ll n = text.size();
    ll m = pattern.size();

    vector < ll > h = getHash(text, m); 

    ll patternHash = myHash(pattern, 0, m-1);

    for(ll i = 0; i < n-m+1; i++){
        if(h[i] == patternHash){
            return i;
        }
    }


    return -1;

}


int main(){


    string text, pattern;

    cin >> text >> pattern;


    cout << match(text, pattern) << "\n";


    // if(match(text, pattern)){
    //     cout << "Matched\n";
    // }
    // else{
    //     cout << "Did not match\n";
    // }




    return 0;
}