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
 
 
int main(){
 
    int n;
    cin >> n;
    vector < pair < int, int > > p;
                //point, start/end
                // 0 - start, 1 - end
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        p.push_back({a, 0});
        p.push_back({b, 1});
    }
 
    sort(all(p));
 
    int mx = 0;
    int cnt = 0;
 
    for(int i = 0; i < p.size(); i++){
        if(p[i].second == 0){ // this is a start
            cnt++;
        }
        else{
            cnt--;
        }
        mx = max(mx, cnt);
    }  
 
 
    cout << mx << endl;
 
 
    return 0;
}