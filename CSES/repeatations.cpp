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

    string str;
    cin >> str;

    int n = str.size();

    int mx = 0;
    for(int i = 0; i < n; i++){
        char curChar = str[i];
        int j = i;
        while(str[j+1] == curChar and j+1 < n){
            j++;
        }

        mx = max(mx, j - i + 1);
        i = j;
    }

    cout << mx << endl;

    return 0;
}