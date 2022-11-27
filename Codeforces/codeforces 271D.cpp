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

ll bad[500];




const ll mod = 1e9+7;
const ll base = 31;

const ll mod2 = 1e9+7;
const ll base2 = 29;


int main(){

    string str, off;
    cin >> str >> off;

    ll k;
    cin >> k;

    

    ll f = 0;

    for(char c = 'a'; c <= 'z'; c++, f++){

        if(off[f] == '0'){
            bad[c - 'a' + 1] = 1;
        }
    }

    ll n = str.size();

    // map < ll, ll > c1, c2;

    set < pair < ll, ll > > s;

    ll ans = 0;


    for(ll i = 0; i < n; i++){
        ll b = 0;
        ll temp = 0;
        ll p_pow = 1;
        ll temp2 = 0;
        ll p_pow2 = 1;
        for(ll j = i; j < n; j++){

            if(bad[str[j] - 'a' + 1]){
                b++;
            }
            if(b > k){
                break;
            }

            temp = (temp + ((str[j] * p_pow) % mod )) % mod; 
            temp2 = (temp2 + ((str[j] * p_pow2) % mod2 )) % mod2; 


            p_pow = (p_pow * base) % mod;
            p_pow2 = (p_pow2 * base2) % mod2;

            // temp += str[j];
            
            s.insert({temp, temp2});

        }
        // debug(temp);
        
    }


    cout << s.size() << "\n";

    // for(auto x: s){
    //     cout << x << "\n";
    // }



    return 0;
}