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

    while(true){
        cout << n << " ";
        if(n == 1) break;
        if(n % 2 == 0){
            n /= 2;
        }    
        else{
            n = 3*n + 1;
        }
    }
    cout << endl;
    

    return 0;
}