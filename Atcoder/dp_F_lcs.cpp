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
dp[i][j] = length of longest common substring taking s_0 to s_i and t_0 to t_j


now base case is comparing empty string with other string where the length will always be zero

now the transition part:
if our i & j th letter doesn't match then we have two options:
1. Either we take i th letter or 
2. we take j th letter

we will take the one which gives us maximum length

if our i & j th letter matches then we have 1 option:
we take the i and j th letter and move on


now from transition table (dp table) we find which diagonal contributed
to the length, and add them together to make the longest common 
subsequence


*/



int dp[3005][3005];
string s, t;

int n;
int m;


string makeString(int n, int m, string str){
    if(dp[n][m] == 0){
        return str;
    }

    if(dp[n-1][m] == dp[n][m]){
        return makeString(n-1, m, str);
    }
    
    if(dp[n][m-1] == dp[n][m]){
        return makeString(n, m-1, str);
    }

    return makeString(n-1, m-1, str+s[n-1]);

}

int main(){

    
    cin >> s >> t;

    n = s.size();
    m = t.size();
    

    for(int i = 0; i <= n; i++){
        dp[i][0] = 0;
    }

    for(int i = 0; i <= m; i++){
        dp[0][i] = 0;
    }



    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    // for(int i = 0; i <= n; i++){
    //     for(int j = 0; j <= m; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }


    string ans = makeString(n, m, "");

    reverse(all(ans));

    cout << ans << "\n";



    return 0;
}