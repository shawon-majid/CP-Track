//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;
                        /*
                        This code uses the idea described by Mahbubul Alam Shanto in his book.
                        If we stop in a arbitrary point R of prefix sum, we can find any subarray
                        sum left that point by sum = pre[R] - pre[L-1].
                        We can maximize sum by finding lowest pre[L-1]. Which we can do along the way
                        by taking min(pre[R]).
                        Then, we will maximize sum in each step.
                        */
                        

int main(){

  	int n;
  	cin >> n;
  	vector <ll> ara(n), pre(n);

  	ll ans = LONG_MIN, sum = 0;
  	for(int i = 0; i < n; i++){
  		cin >> ara[i];
  		ans = max(ara[i], ans);
  		sum += ara[i];
  	}
  	ans = max(ans, sum);
  	pre[0] = ara[0];
  	for(int i = 1; i < n; i++){
  		pre[i] = pre[i-1] + ara[i];
  	}
  	ll mn = LONG_MAX;
  	for(int i = 0; i < n; i++){
  		mn = min(mn, pre[i]); // 
  		if(pre[i] != mn){
        ll temp = pre[i] - mn;
  		  ans = max(ans, max(temp, pre[i]));
      }
      else ans = max(ans, pre[i]);
  	}

  	cout << ans << endl;

    return 0;
}