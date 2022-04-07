//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;

int main(){

    int T, cs = 1;
    cin >> T;
    while(T--){
        string a;
        cin >> a;
        long long b;
        cin >> b;
        if(a[0] == '-'){
            a.erase(0, 1);
        }
        b = abs(b);
        
        ll num = 0, rem = 0;
        ll i = 0;
        while(i < a.size()){
            while(num < b and i < a.size()){
                num = num*10 + (a[i] - '0');
                i++;
            }
            rem = num % b;
            num = rem;
        }

        if(rem == 0){
            cout << "Case "<<cs<<": divisible" << endl;
        }
        else cout << "Case "<<cs<<": not divisible" << endl;
        cs++;
    }

    return 0;
}