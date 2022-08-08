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
    DP variant 2
We have to find the number of ways to choose coins to change n
if coins are {2, 3}
then we can make 5 in 2 ways: {2+3}, {3+2};
note: here we can use coins any number of times and order DOES matter

*/

vector <int> coins;
vector <int> ways(10000);

void calculateWays(int n){

    ways[0] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < coins.size(); j++){
            if(i >= coins[j]){
                ways[i] += ways[i - coins[j]];
            }            
        }
    }
}


int main(){

    int m;
    cin >> m;
    for(int i = 0; i < m; ++i){
        int x;
        cin >> x;
        coins.push_back(x);
    }

    int n;
    cin >> n;

    calculateWays(n);

    cout << ways[n] << endl;



    return 0;
}