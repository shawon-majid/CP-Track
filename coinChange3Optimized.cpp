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
    DP variant 3
Check if it is possible to make sum of coins equal to n
Now, you cannot use any coin more than once
 
*/
 
vector <int> coins;
int possible[10000];

 
int main(){
 
    int m;
    cin >> m;
    coins.resize(m+1);
    for(int i = 1; i <= m; ++i){
        
        cin >> coins[i];
        
    }
 
    int n;
    cin >> n;
 
    //initialize
    // we can make 0 with any coins or no coins
    possible[0] = 1;

    for(int j = 1; j <= m; j++){
        for(int i = n; i >= 1; i--){
            if(i - coins[j] >= 0 and possible[i - coins[j]]){
                possible[i] = true;
            }
        }
    }
 
    if(possible[n]){
        cout << "possible" << endl;
    }
    else cout << "not possible" << endl;
 
 
 
    return 0;
}