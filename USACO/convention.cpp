#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
#define all(x) begin(x), end(x)
using pi = pair<int,int>;
#define F first
#define S second
#define debug(x) cout << '>' << #x << " : " << x << endl;

void setIO(string name = "") { // name is nonempty for USACO file I/O

    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output

    // alternatively, cin.tie(0)->sync_with_stdio(0);

    if (name.size()) {

        freopen((name+".in").c_str(), "r", stdin); // see Input & Output

        freopen((name+".out").c_str(), "w", stdout);

    }

}

bool ok(int duration, int bus, int capacity, vector <int> ara){
    int n = ara.size();
    int cnt = 0;
        
    int i = 0, j = 0;

    while(i < n and j < n){
        int dif = ara[j] - ara[i];
        if(dif <= duration and (j - i + 1) <= capacity){   
            j++;
        }
        else{
            i = j;
            cnt++;
        }
    }
    cnt++;

    if(cnt > bus){
        return false;
    }
    else{
        return true;
    }

}



int main() {

    setIO("convention");
	

	int n, m, c;
    cin >> n >> m >> c;

    vector <int> ara(n);

    for(auto &x: ara) cin >> x;

    sort(all(ara));
    //minimizing maximum duration
    //durations
    int low = 0, high = ara[n-1] - ara[0];
    int ans = -1;
    while(low <= high){
        int mid = low + ((high - low)/2); // durations
        if(ok(mid, m, c, ara)){
            // decrease duration
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }

    }

    cout << ans << endl;


    return 0;
}