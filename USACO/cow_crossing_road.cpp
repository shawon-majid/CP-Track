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


int main() {

    setIO("maxcross");
    int n, k, b;
    cin >> n >> k >> b;

    vector <int> ara(n+1, 0);
    for(int i = 0; i < b; i++){
        int x;
        cin >> x;
        ara[x] = 1;
    }
    vector <int> pre(n+1);
    pre[0] = 0;

    for(int i =1;i <= n; i++){
        pre[i] = pre[i-1] + ara[i];
    }
    int mn = n+10;

    for(int i = 1; i+k-1 <= n; i++){
        int l = i-1;
        int r = i+k-1;
        int ans = pre[r] - pre[l];
        mn = min(ans, mn);
    }

    cout << mn << endl;

    
    return 0;
}
