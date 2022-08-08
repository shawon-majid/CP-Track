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

    ll n, x;
    cin >> n >> x;

    vector < ll > weights(n);

    for(auto &x: weights){
        cin >> x;
    }

    sort(all(weights));

    ll l = 0, r = n-1;
    ll cnt = 0;

    while(l <= r){
        if(weights[l] + weights[r] > x){
            r--;
        }
        else{
            l++;
            r--;
        }   
        cnt++;
    }

    cout << cnt << endl;

    return 0;
}