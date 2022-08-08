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
 
 
bool cmp(pair < int, int > a, pair <int, int> b){
    return a.second < b.second;
}
 
int main(){
 
    int n;
    cin >> n;
 
    vector < pair <int, int > > p(n);
    for(int i = 0; i < n; i++){
        cin >> p[i].first;
        cin >> p[i].second;
    }
 
    sort(all(p), cmp);
 
    int curEnding = -1;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(p[i].first >= curEnding ){
            curEnding = p[i].second;
            cnt++;
        }
    }
 
    cout << cnt << endl;
 
    return 0;
}