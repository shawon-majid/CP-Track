//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef unsigned long long ull;
typedef long long ll;


long long bigmod(long long a, long long b, long long m) {
    long long res = 1;
    a %= m;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % m;
        }
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}


int main(){

    int T;
    cin >> T;
    while(T--){
        ll x, y, z;

        cin >> x >> y >> z;

        ll dif = y - x;

        vector < ll > divisors;

        for(ll i = 1; i*i <= dif+1; i++){
            if(dif % i == 0){
                divisors.push_back(i);
                divisors.push_back(dif / i);
            }
        }


        sort(all(divisors));

        ll ans = -1;



        for(ll i = divisors.size()-1; i >= 0; i--){
            ll d = divisors[i];
            // debug(d);

            if((bigmod(x, z, d) + bigmod(y, z, d)) % d == 0){
                ans = d;
                break;
            } 
        }

        cout << ans << "\n";

        



    }


    return 0;
}