//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<pair < int, int > , null_type,less<pair < int, int > >, rb_tree_tag,tree_order_statistics_node_update>
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef unsigned long long ull;
typedef long long ll;
 
bool cmp(pair < pair < int, int > , int >  p1, pair < pair < int, int >, int > p2){
    if(p1.first.first == p2.first.first){
        return (p1.first.second - p1.first.first) > (p2.first.second - p2.first.first);
    }
    return p1.first.first < p2.first.first;
}
 
int main(){
 
 
    int n;
    cin >> n;
 
    vector < pair < pair < int, int > , int > > p;
 
    for(int i = 0; i < n; i++){
 
        int x, y;
        cin >> x >> y;
 
        p.push_back({{x, y}, i});
 
        // p1.push_back({x, i});
    }
 
 
    sort(all(p), cmp);
 
    multiset < int > y;
 
 
    vector < int > contained(n, 0);
 
 
    y.insert(p[0].first.second);
 
    for(int i = 1; i < n; i++){
 
 
        int sec = p[i].first.second;
        int ind = p[i].second;
 
        // debug(*(--y.end()));
 
        if(*(--y.end()) >= sec){
 
            auto it = y.lower_bound(sec);
 
            int cnt = distance(it, y.end());
 
            contained[ind] = cnt;
        }
        y.insert(sec);       
    }   
 
 
        
 
 
    // cout << "reversed: \n";
    
 
    reverse(all(p));
 
 
    // for(auto x: p){
    //     cout << x.first.first << " " << x.first.second << " " << x.second << "\n";
    // }
    // cout << "\n\n";
 
    multiset < int > y2;
 
    y2.insert(p[0].first.second);
 
    vector < int > contains(n, 0);
 
 
    for(int i = 1; i < n; i++){
 
        int sec = p[i].first.second;
        int ind = p[i].second;
 
        if(sec >= *(y2.begin())){
 
            auto it = y2.upper_bound(sec);
            int cnt = distance(y2.begin(), it);
            
 
            contains[ind] = cnt;
        }
        y2.insert(sec);
 
    }
 
 
    for(auto x: contains){
        cout << x << ' ';
    }
    cout << "\n";
 
    for(auto x: contained){
        cout << x << " ";
    }
    cout << "\n";
 
 
 
 
 
 
 
 
    return 0;
}