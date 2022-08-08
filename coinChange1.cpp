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

const int inf = 1e9;

const int MAX_N = 20;
const int MAX_W = 10000;

int dp[MAX_N][MAX_W];
int coins[MAX_N];
int n;

int minCoin(int i, int target){

	if(target < 0) return inf;

	if(i == n){
		if(target == 0){
			return 0;
		}
		return inf;
	}

	if(dp[i][target] != -1){
		return dp[i][target];
	}



	int res1 = 1 + minCoin(i+1, target - coins[i]);
	int res2 = minCoin(i+1, target);
	int res3 = 1 + minCoin(i, target - coins[i]);


	return dp[i][target] = min(res3, min(res1, res2));

}

int helper(int i , int w, int n){
	if(w < 0) return inf;
	if(i == n){
		if(w == 0) return 0;
		return inf;
	}
	return dp[i][w];
}

int minCoinIterative(int n, int target){
	for(int i = n-1; i >=0; i--){
		for(int w = 0; w <= target; w++){
			int res1 = 1 + helper(i+1, w - coins[i], n);
			int res2 = helper(i+1, w, n);
			dp[i][w] = min(res1, res2);
		}
	}
	return dp[0][target];
}

int main(){

	memset(dp, -1, sizeof dp);

	int target;
	cin >> n >> target;
	for(int i = 0; i < n; i++){
		cin >> coins[i];
	}

	cout << minCoin(0, target) << endl;
	cout << minCoinIterative(n, target) << endl;
 
    return 0;
}