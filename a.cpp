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
    while(T--){
        ll n;
        cin >> n;
        vector < ll > ara(n);

        bool zero = 0;

        for(auto &x: ara){
            cin >> x;
            if(x%10 == 0) zero = 1;
        }


        // handle 5 or 0
        for(ll i = 0; i < n; i++){
            if(ara[i] % 10 == 5){
                ara[i] += 5;
                zero = 1;
            }
        }

        if(zero){

            bool ok = 1;

            for(ll i = 0; i < n-1; i++){
                if(ara[i] != ara[i+1]){
                    ok = 0;
                }
            }

            if(ok){
                cout << "Yes" << endl;
            }
            else{
                cout << "No" << endl;
            }
            continue;
        }


        // handle rest of the cases
        for(ll i = 0; i < n; i++){
            while(ara[i] % 10 != 2){
                ara[i] = ara[i] + (ara[i]%10);
            }
        }

        // for(auto x: ara){
        //     cout << x << ' ';
        // }

        // cout << endl;

        bool notAllEven = 0;
        bool notAllOdd = 0;

        for(ll i = 0; i < n; i++){
            // get preceding number of 2
            ll x = (ara[i] / 10) % 10;
            if(x % 2 == 0){
                notAllOdd = 1;
            }
            else{
                notAllEven = 1;
            }
        }

        if(notAllOdd && notAllEven){
            cout << "No" << endl;
        }
        else{
            cout << "Yes" << endl;
        }

    }

    return 0;
}