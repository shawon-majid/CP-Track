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

    int n;
    cin >> n;
    ll sum = 0;
    for(int i = 0; i < n-1; i++){
        ll x;
        cin >> x;
        sum += x;
    }

    ll neededSum = (n * (n+1LL))/2;


    cout << neededSum - sum << endl;

    return 0;
}