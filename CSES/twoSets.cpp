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

    ll n;
    cin >> n;

    ll tot = (n*(n+1))/2;

    if(tot % 2 != 0){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
        ll needed = tot/2;
        ll sum = 0;
        ll right = n;

        int sz = 0;
        while(sum < needed){
            sum += right;
            right--;
            sz++;
        }
        sz--;
        right++;
        sum -= right;

        int need = needed - sum;
        sz++;

        
        cout << sz << endl;
        cout << need << ' ';
        for(int i = right+1; i <= n; i++){
            cout << i << ' ';
        }

        cout << endl;

        cout << n - sz << endl;
        for(int i = 1; i <= right; i++){
            if(i != need)cout << i << ' ';
        }
    
        cout << endl;

    }

    return 0;
}