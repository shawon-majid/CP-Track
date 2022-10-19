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


/*
Input: a = 10123465234878998, 
       b = 65746311545646431
       m = 10005412336548794 
Output: 4652135769797794
*/

ll modularMult(ll a, ll b, ll m){

    if(b == 1){
        return a % m;
    }

    ll ret = modularMult(a, b/2, m);

    if(b % 2 == 0){
        
        
        return ((ret % m) + (ret % m))%m;
    }

    else{
        return (((ret % m) + (ret % m))%m + (a % m)) % m;  
    }

}


int main(){

    ll a, b, m;
    cin >> a >> b >> m;

    cout << modularMult(a, b, m) << endl;



    return 0;
}