//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;


vector < int > adj[500]; // max unique node

int main(){

	int nodeCount, edgeCount;
	cin >> nodeCount >> edgeCount;

	vector <int> indegree(nodeCount, 0);

	for(int i = 0; i < edgeCount; i++){
		int u, v;
		cin >> u >> v;
		indegree[v]++;
		adj[u].push_back(v);
	}

	vector <int> sequenceTask; // answer

	for(int i = 1; i <= nodeCount; i++){
		if(indegree[i] == 0){
			sequenceTask.push_back(i);
		}
	}

	for(int i= 0; i < sequenceTask.size(); i++){
		int node = sequenceTask[i];
		for(int dependentNode : adj[node]){
			indegree[dependentNode]--;
			if(indegree[dependentNode] == 0){
				sequenceTask.push_back(dependentNode);
			}
		}
	}

	for(auto seq: sequenceTask){
		cout << seq << " ";
	} 

    return 0;
}