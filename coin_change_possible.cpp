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

int possible[10000];

int main(){

    vector < int > coins{4, 7, 10};

    int n;
    cin >> n;

    possible[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < coins.size(); j++){
            if(i >= coins[j]){
                possible[i] |= possible[i - coins[j]];
            }
        }
    }

    if(possible[n]){
        cout << "Possible" << endl;
    }
    else cout << "Impossible" << endl;

    return 0;
}