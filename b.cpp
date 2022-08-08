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


    // cout << 102%100 << endl;


    int n = 1;

    int k = 0;
    while(k <= 20){
        cout << n << endl;
        n = n + (n%10);
        k++;
    }

    return 0;
}