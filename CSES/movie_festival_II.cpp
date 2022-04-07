//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;

bool cmp(pair <int, int> a, pair <int, int> b){
    return a.second < b.second;
}

int main(){

    int n, k;
    cin >> n >> k;

    vector <pair <int, int> > p(n);

    for(auto &x: p){
        cin >> x.first >> x.second;
    }

    sort(all(p), cmp);

    multiset <int> endTimes;
    int ans = 0;

    for(int i = 0; i < k; i++){
        endTimes.insert(0);
    }

    for(int i = 0; i < n; i++){
        int curStart = p[i].first, curEnd = p[i].second;
        
        auto it = endTimes.lower_bound(curStart);
        it--;
        if(it != endTimes.end()){
            if(curStart >= *it){
                ans++;
                endTimes.erase(it);
                endTimes.insert(curEnd);
            }
        }

    }

    cout << ans <<endl;

    return 0;
}