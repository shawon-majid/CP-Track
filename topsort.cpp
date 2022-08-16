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

	int T;
	cin>>T;

	while(T--){
		int n, k;
		cin >> n >> k;
		vector <int> ara(n+1);


		for(int i = 1; i <= n; i++){
			cin >> ara[i];
		}

		int cnt = 0;

		for(int i = 1; i <= k; i++){
			if(ara[i] > k) cnt++;
		}

		cout << cnt << endl;
	}

    return 0;
}