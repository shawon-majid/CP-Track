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

ll n;
vector < ll > ara;    

ll f(ll pos, ll a, ll b){

    if(pos == n-1){
        return min(abs((a+ara[pos]) - b), abs(a - (b+ara[pos])));
    }

    return min(f(pos+1, a + ara[pos], b), f(pos+1, a, b+ara[pos]));
}

int main(){

    cin >> n;
    ara.resize(n);

    for(ll i = 0; i < n; i++){
        cin >> ara[i];
    }

    cout << f(0, 0, 0) << endl;

    return 0;
}