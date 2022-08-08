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

    ll T;
    cin >> T;
    // debug(T);
    while(T--){
        ll n, c, q;
        cin >> n >> c >> q;
        string str;
        cin >> str;


        // cout << str <<  endl;

        vector < ll > left(c+10), right(c+10), dif(c+10); 


        left[0] = 0;
        right[0] = n; 


        for(ll i = 1; i <= c; i++){
            ll l, r;
            cin >> l >> r;

            l--;
            r--;


            ll tot = r - l + 1;
            
            left[i] = right[i-1];

            right[i] = left[i] + tot;

            dif[i] = left[i]-l;
        }

        while(q--){
            ll k; cin >> k;
            k--;
            for(int i=c; i>=1; --i){
                if(k < left[i]) continue;
                else k -= dif[i];
            }
            cout << str[k] << "\n";

        }
        
    }


    return 0;
}