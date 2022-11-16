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

ll bigMod(ll a, ll b, ll m)
{
    if(b == 0) return 1 % m;

    ll x = bigMod(a, b/2, m);

    if(b % 2 == 0){
        return (x * x) % m;
    }
    else{
        return (((x * x)%m) * a) % m;
    }

}
int main(){

    cout << bigMod(347, 5, (1e9+7));


    return 0;
}