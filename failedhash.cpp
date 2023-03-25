#include<bits/stdc++.h>
using namespace std;
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

ll pr = 13;
const ll mod = 100000000007;


ll modadd(ll a, ll b){
    return ((a%mod)+(b%mod))%mod;
}

ll modmul(ll a, ll b){
    return ((a%mod)*(b%mod))%mod;
}


int main(){

    vector < ll > p(506);

    p[0] = 1;

    for(ll i = 1; i < 505; i++){
        p[i] = modmul(p[i-1], pr);
    }


    // for(int i = 0; i <= 5; i++){
    //     cout << p[i] << " ";
    // }
    // cout << "\n\n";

    ll T;
    cin >> T;
    while(T--){
        ll n, m;
        cin >> n >> m;

        vector < ll > hsh[n+1], prefix[n+1];

        vector < string > sss(n+1);

        for(ll i = 1; i <= n; i++){
            string str;
            cin >> str;

            //makeHash//

            str = "#"+str;

            vector < ll > h(m+1), pre(m+1);


            h[0] = 0;
            pre[0] = 0;




            for(ll j = 1; j <= m; j++){
                h[j] = modadd(modmul(h[j-1], pr), (str[j]-'a'+1));
                // cout << h[j] << " ";


                if(str[j] == str[1]){
                    pre[j] = pre[j-1] + 1;
                }
                else{
                    pre[j] = pre[j-1];
                }
                // cout << pre[j] << " ";
            }
            // cout << "\n";



            hsh[i] = h;
            sss[i] = str;
            prefix[i] = pre;
        }
        // cout << "\n";

        ll q;
        cin >> q;
        while(q--){

            ll x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;

            bool ok = true;


            vector <ll> refHash = hsh[x1];

            vector < ll > pre = prefix[x1];

            if(x1 == x2){
                // debug(y2-y1+1);

                // debug(pre[y2]);

                if((y2 - y1 + 1) == pre[y2] - pre[y1-1]){
                    cout << "YES\n";
                }   
                else{
                    cout << "NO\n";
                }
                continue;
            }



            ll refval = (refHash[y2] - (refHash[y1-1]*p[y2-y1+1])) % mod;
            // debug(refval);
            for(ll i = x1; i <= x2; i++){
                vector <ll> curHash = hsh[i];

                // for(int j = y1; j <= y2; j++){
                //     cout << sss[i][j];
                // }
                // cout << "\n";

                ll val = (curHash[y2] - (curHash[y1-1]*p[y2-y1+1])) % mod;
                if(val < 0){
                    val += mod;
                }


                // debug(val);
                if(val != refval){
                    ok = false;
                    break;
                }

            }

            if(ok){
                cout << "YES\n";
            }
            else cout << "NO\n";

        }




    }




    return 0;
}
