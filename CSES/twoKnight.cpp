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

ll nc2(ll n){
    return (n*(n-1))/2;
}

int main(){

    int n;
    cin >> n;
    ll cnt = 1;
    ll base = 0;
    for(int i = 1; i <= n; i++){
        if(i == 1){
            cout << 0 << endl;
        }
        else if(i == 2){
            cout << 6 << endl;
        }
        else{
            base = base + 16*cnt;
            ll ans = nc2(i*i);
            cnt++;
            cout << ans - base/2 << endl;
        }
    }

    return 0;
}