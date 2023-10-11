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
        ll B, y;

        cin >> B >> y;

        ll ans = 0;

        for(ll m = 0; m <= 100; m++){
            ll exp = ((m/2)*(m/2) + ((m+1)/2)*((m+1)/2)) + m*y;


            if(exp <= B){
                ans = m;
            }
            else{
                break;
            }

        }

        // debug(ans);


        cout << (ll)pow(2, ans) << "\n";

    }

    return 0;
}