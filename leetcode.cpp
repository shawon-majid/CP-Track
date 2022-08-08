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

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector < long long > dp(amount+10, 0);
        dp[0] = 1;

        for(int j = 0; j < coins.size(); j++){
            for(int i = 1; i <= amount; i++){
                if(i - coins[j] >= 0){
                    dp[i] += dp[i - coins[j]];
                }
            }
        }

        return dp[amount];

    }
};


int main(){
    Solution s;

    vector < int > coins{1, 2, 5};

    cout << s.change(5, coins) << endl;

}