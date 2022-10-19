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


int extendedGCD(int a, int b, int &x, int &y){

    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int g = extendedGCD(b, a%b, x1, y1);
    x = y1;
    y = x1 - (a/b)*y1;

    return g;
}


int main(){

    int x, y;
    cout << extendedGCD(4, 8, x, y) << endl;

    cout << x <<  ' ' << y << endl; 


    return 0;
}