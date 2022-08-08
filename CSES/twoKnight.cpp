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


// the approach is simple. If two knights attack each other then 
// they will be in either 2*3 rectangle or 3*2 rectangle. So the number
// of ways of placing them in a n^2 grid is (n-1)*(n-2) + (n-2)(n-1).
// Also, in a rectangle the number of ways of attacking each other is 2
// so total ways of attacking each other is 2 * {(n-1)*(n-2) + (n-2)(n-1)}
// = 4*(n-1)(n-2). 

// The total number of arrangement is (n^2(n^2 - 1))/2.

// So, the total number of ways of not attacking each other is 

// (n^2(n^2 - 1))/2 - 4*(n-1)(n-2). 

ll nc2(ll n){
    return (n*(n-1))/2;
}

int main(){

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cout << nc2(i*i) - 4*(i-1)*(i-2) << endl;
    }

    return 0;
}