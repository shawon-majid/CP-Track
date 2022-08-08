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
#define MaxNode 500

int arr[MaxNode];
int tree[MaxNode*3];

void init(int node, int b, int e){
	if(b == e){
		tree[node] = ara[b];
		return;
  	}
  	int leftIndex = 2*node;
  	int rightIndex = leftIndex+1;
  	int mid = (b+e)/2;
  	init(leftIndex, b, mid);
  	init(rightIndex, mid+1, e);
  	tree[node] = tree[leftIndex]+tree[rightIndex];

}

int query(int node, int b, int e, int i, int j){
	if(i > e || j < b){
		return 0;
	}
	if(b >= i and e <= j){
		return tree[node];
	}

	int leftIndex = 2*node;
  	int rightIndex = leftIndex+1;
  	int mid = (b+e)/2;

  	int leftSubTreeSum = query(leftIndex, b, mid, i, j);
  	int rightSubTreeSum = query(rightIndex, mid+1, e, i, j);

  	return leftSubTreeSum+rightSubTreeSum;

}

void update(int node, int b, int e, int i, int newValue){
	if(i > e || i < b){
		return;
	}
	if(b >= i and e <= i){
		tree[node] = newValue;
		return;
	}

	int leftIndex = 2*node;
  	int rightIndex = leftIndex+1;
  	int mid = (b+e)/2;

  	update(leftIndex, b, mid, i, newValue);
  	update(rightIndex, mid+1, e, i, newValue);

  	tree[node] = tree[leftIndex]+tree[rightIndex];

  	return;
}

int main(){



    return 0;
}