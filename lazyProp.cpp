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

#define N 500

struct info{
	int sum, prop;
}tree[N*3];

void update(int node, int b, int e, int i, int j, int x){
	if(i > e || j < b){
		return;
	}
	if(b >= i && e <= j){
		tree[node].sum += ((e-b+1)*x);
		tree[node].prop += x;
		return;
	}

	int left = 2*node;
	int right = left+1;
	int mid = (b+e)/2;
	update(left, b, mid, i, j, x);
	update(right, mid+1, e, i, j, x);

	tree[node].sum = tree[left].sum + tree[right].sum + (e-b+1)*tree[node].prop;

}

int query(int node, int b, int e, int i, int j, int carry = 0){
	if(i > e || j < b){
		return 0;
	}
	if(i <= b && e <= j){
		return tree[node].sum + carry*(e-b+1);
	}

	int left = 2*node;
	int right = left+1;
	int mid = (b+e)/2;
	int p1 = query(left, b, mid, i, j, carry + tree[node].prop);
	int p2 = query(right, mid+1, e, i, j, carry + tree[node].prop);

	return p1+p2;
}

int main(){

	int n;
	cin >> n;

	vector <int> ara(n+1);
	for(int i = 1; i <= n; i++){
		cin >> ara[i];
		update(1, 1, n, i, i, ara[i]);
		cout << "ok GOOGLE" << endl;
	}

	int choice;
	while(cin >> choice){
		if(choice == 1){
			int l, r, x;
			cin >> l >> r >> x;
		}
		else{
			int l, r;
			cin >> l >> r;
			cout << query(1, 1, n, l, r) << endl;
		}
	}




    return 0;
}