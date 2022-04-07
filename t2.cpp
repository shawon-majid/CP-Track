//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;



unordered_map < string, vector <pair < string, int > > > adj;


bool cmp(pair <string, int> a , pair < string, int> b){
    return a.second < b.second;
}

int main(){

    int n, m;

    int cs = 1;

    while(cin >> n){

        vector < pair < string, int > > drinks(n);
        map < string, int > indegree;
        map < string, int > order;

        for(int i = 0; i < n; i++){
            cin >> drinks[i].first;
            drinks[i].second = i;
            order[drinks[i].first] = i;
        }

        int m;
        cin >> m;

        for(int i = 0; i < m; i++){
            string u, v;
            cin >> u >> v;
            adj[u].push_back({v, order[v]});
            indegree[v]++;
        }

        // sort the adjacency list by the order of input
        for(int i = 0; i < n; i++){
            string currentDrink = drinks[i].first;
            if(adj[currentDrink].size()){
                sort(all(adj[currentDrink]), cmp);
            }
        }


        vector <string> answerSequence;

        for(int i = 0; i < n; i++){
            if(indegree[drinks[i].first] == 0){
                answerSequence.push_back(drinks[i].first);
            }
        }

        for(int i = 0; i < answerSequence.size(); i++){
            // decrease all the adjacent node

            for(auto v: adj[answerSequence[i]]){
                indegree[v.first]--;
                if(indegree[v.first] == 0){
                    answerSequence.push_back(v.first);
                }
            }
        }

        cout << "Case #"<<cs<<": ";
        for(auto v: answerSequence){
            cout << v << " ";
        }
        cout << endl;

        cs++;

        adj.clear();


    }

    return 0;
}