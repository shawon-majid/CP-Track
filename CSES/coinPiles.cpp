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
        ll a, b;
        cin >> a >> b;
        if((2*b - a) < 0 or (2*a - b) < 0){
            cout << "NO" << endl;
            continue;
        }
        if((2*b - a) % 3 == 0 and (2*a - b) % 3 == 0){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }

    return 0;
}