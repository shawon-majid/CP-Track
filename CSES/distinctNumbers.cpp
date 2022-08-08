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

	int n;
	cin >> n;
	set <int> s;

	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		s.insert(x);
	}

	cout << s.size() << endl;

    return 0;
}