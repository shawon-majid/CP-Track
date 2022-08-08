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
Extended Euclidean Algorithm for finding the solution to diophantine equation
*/

int egcd(int a, int b, int &x, int &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = egcd(b, a%b, x1, y1);
    x = y1;
    y = x1 - y1*(a/b);
    return d;

}

int main(){

    int a, b, c;
    cin >> a >> b >> c;

    int x, y;

    int gcd = egcd(a, b, x, y);

    if(c % gcd == 0){ //  solution exists
        int scale = c / gcd;

        cout << "x = " << x*scale << endl;
        cout << "y = " << y*scale << endl; 

    }
    else{
        cout << "No Solutions" << endl;
    }



    return 0;
}