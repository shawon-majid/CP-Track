//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;


// DSU

vector <int> parent;

void makeSet(int v){
	parent[v] = v;
}

int findSet(int v){
	if(parent[v] == v){
		return v;
	}
	return findSet(parent[v]);
}

void unionSet(int a, int b){
	a = findSet(a);
	b = findSet(b);

	if(a!=b){
		parent[b] = a;
	}
}



int main(){



    return 0;
}