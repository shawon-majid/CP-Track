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

//[u][v] = capacity, [v][u] =  flow

vector < vector < int > > rcGraph, graph;

int n;

void bfs(int s, int d, vector < int > &parent){

    fill(all(parent), -1);

    parent[s] = s;

    queue < pair < int, int >  > q;
    q.push({s, INT_MAX});

    while(!q.empty()){
        int currentNode = q.front().first;
        int flow = q.front().second;
        q.pop();

        for(int nextNode : graph[currentNode]){
            if(parent[nextNode] == -1 && rcGraph[currentNode][nextNode] > 0){
                parent[nextNode] = currentNode;
                int minFlow = min(flow, rcGraph[currentNode][nextNode]);

                if(nextNode == d){
                    return minFlow;
                }

                q.push_back({nextNode, minFlow});

            }
        }

    }


    return 0;


}


int maxFlow(int source, int sink){

    int flow = 0;

    vector < int > parent(n);

    int bottleneckCapacity = 0;

    while(bottleneckCapacity = bfs(source, sink, parent)){
        int currentNode = sink;

        while(currentNode != source){
            int prevNode = parent[currentNode];

            rcGraph[prevNode][currentNode] -= bottleneckCapacity;
            rcGraph[currentNode][prevNode] += bottleneckCapacity;

            currentNode = prevNode;
        }

        flow += bottleneckCapacity;

    }

    return flow;

}

int main(){

    int m;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;

    }

    return 0;
}