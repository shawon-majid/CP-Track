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

vector <pair < int, int > > moves;

int hanoi(int n, int from, int to){
    //base case
    if(n == 1){
        moves.push_back({from, to});
        return 1 ;
    }
    int ans = 0;

    // rem stack
    int remStack = 6 - (from+to);

    ans += hanoi(n-1, from, remStack);
    ans += hanoi(1, from, to);
    ans += hanoi(n-1, remStack, to);
    return ans;
}


int main(){

    int n;
    cin >> n;


    cout << hanoi(n, 1, 3) << endl;
    
    for(auto p: moves){
        cout << p.first << ' ' << p.second << endl;
    }

    return 0;
}