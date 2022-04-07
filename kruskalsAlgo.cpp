//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;


vector <int> parent, siz;


void makeSet(int v){
	parent[v] = v;
	siz[v] = 1;
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

		if(siz[a] < siz[b]){
			swap(a, b);
		}
		parent[b] = a;

		siz[a] += siz[b];
	}
}

struct Edge
{
	int u, v, w;	

	Edge(int uu, int vv, int ww): u(uu), v(vv), w(ww){}

	// same as
	// Edge(int uu, int vv, int ww){
	// 	uu = u;
	// 	vv = v;
	// 	ww = w;
	// }


	bool operator < (const Edge& other) const{
		return w < other.w;
	}


};


vector <Edge> graph;

int mst(int numberOfNode){
	sort(graph.begin(), graph.end());

	for(int i = 1; i <= numberOfNode; i++){
		makeSet(i);
	}

	int cost = 0;

	for(int i = 0; i < graph.size(); i++){
		int t = 0;
		int u = findSet(graph[i].u);
		int v = findSet(graph[i].v);
		if(v != u){
			unionSet(u, v);
			cost += graph[i].w;
			t++;
		}

		if(t == numberOfNode-1){
			return cost;
		}
	}

	return cost;
}


int main(){


    return 0;
}