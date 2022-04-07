//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;

struct myComp {
    bool operator()(pair < string, int > const& p1, pair < string, int >  const& p2)
    {
        // return "true" if "p1" is ordered
        // before "p2", for example:
        return p1.second > p2.second;
    }
};

unordered_map < string, vector < pair < string, int> > > adj; 


void printPriorityQueue(priority_queue < pair <string, int >, vector < pair < string, int> >, myComp> pq){
    cout << "current standings:" << endl;
    while(!pq.empty()){
        cout << pq.top().first << endl;   
        pq.pop();
    }

}


int main() {
    // your code goes here
    int n, m, cs = 1;

    while(cin >> n){
        vector < string > drinks(n);
        map < string, int > order;
        map < string, int > indegree;
        
        for(int i = 0; i < n; i++){
            cin >> drinks[i];
            order[drinks[i]] = i;
        }

        


        cin >> m;
        for(int i = 0; i < m; i++){
            string from, to;
            cin >> from >> to;
            adj[from].push_back({to, order[to]});
            indegree[to]++;
        }
        
        

        priority_queue < pair <string, int >, vector < pair < string, int> >, myComp> pq;

    
        for(string s: drinks){
            if(indegree[s] == 0){
                pq.push({s, order[s]});
            }
        }

        vector <string> answerSequence;



        while(!pq.empty()){
            //printPriorityQueue(pq);
            string currentDrink = pq.top().first;
            answerSequence.push_back(currentDrink);
            pq.pop();
            for(auto v : adj[currentDrink]){
                indegree[v.first]--;
                if(indegree[v.first] == 0){
                    pq.push(v);
                }
            }
        }

        cout << "Case #"<<cs<<": Dilbert should drink beverages in this order: ";
        for(auto ans: answerSequence){
            
            if(ans != answerSequence.back())cout << ans << ' ';
            else cout << ans << "." << endl;
        }
        
        
        cout << endl;


        adj.clear();
        cs++;
    }
    return 0;
}