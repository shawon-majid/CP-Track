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

    setIO("lemonade");
    
  	int n;
    cin >> n;
    vector <int> ara(n);

    for(auto &x: ara) cin >> x;

    sort(all(ara), greater <int>());

    int cnt = 0;

    vector <int> pre(n);

    pre[0] = 1;

    for(int i = 1; i < n; i++){
        if(ara[i] >= pre[i-1]){
            pre[i] = pre[i-1]+1;
        }
        else{
            pre[i] = pre[i-1];
        }
    }

    cout << pre[n-1] << endl;

    return 0;
}