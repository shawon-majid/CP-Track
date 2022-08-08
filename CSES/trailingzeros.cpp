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

ll power(ll a, ll n){
    if(n == 0) return 1;

    ll x = power(a, n/2);
    if((n & 1) == 0){ // even   
        return (x*x);
    }
    else{
        return (x*x*a);
    }
}

int main(){

    int n;
    cin >> n;

    int ans = 0;
    for(int i = 1; i <= 15; i++){
        ans += n / power(5, i);
    }

    cout << ans << endl;

    return 0;
}