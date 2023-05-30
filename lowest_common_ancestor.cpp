//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef unsigned long long ull;
typedef long long ll;


int main(){

	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		string str;
		cin >> str;

		set < string > s;
		for(int i = 0; i < n-1; i++){
			string temp;
			temp = str[i] + str[i+1];

			s.insert(temp);
		}

		cout << s.size() << "\n";
	}

    return 0;
}