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
// optimzed by path compression and union by size

vector <int> parent, size;


void makeSet(int v){
	parent[v] = v;
	size[v] = 1;
}

int findSet(int v){
	if(parent[v] == v){
		return v;
	}
	return parent[v] = findSet(parent[v]);
}

void unionSet(int a, int b){
	a = findSet(a);
	b = findSet(b);

	if(a!=b){

		if(size[a] < size[b]){
			swap(a, b);
		}
		parent[b] = a;

		size[a] += size[b];
	}
}



int main(){



    return 0;
}