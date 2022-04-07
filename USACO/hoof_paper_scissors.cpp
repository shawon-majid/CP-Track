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

    setIO("hps");
    int n;
    cin >> n;
    vector <char> v(n+1);
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    vector <int> preH(n+1), preP(n+1), preS(n+1);

    preH[0] = preP[0] = preS[0]= 0;

    int p = 0, s = 0, h = 0;
    for(int i = 1; i <= n; i++){
        if(v[i] == 'P'){
            p++;
        }
        else if(v[i] == 'H'){
            h++;
        }
        else if(v[i] == 'S'){
            s++;
        }
        preH[i] = h;
        preP[i] = p;
        preS[i] = s;
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        // we will partition in i.
        // S+P, S+H, P+S, P+H, H+S, H+P
        int SPlusP, SPlusH, PPlusS, PPlusH, HPlusS, HPlusP;

        SPlusP = preS[i] + (preP[n] - preP[i]);
        SPlusH = preS[i] + (preH[n] - preH[i]);
        PPlusS = preP[i] + (preS[n] - preS[i]);
        PPlusH = preP[i] + (preH[n] - preH[i]);
        HPlusS = preH[i] + (preS[n] - preS[i]);
        HPlusP = preH[i] + (preP[n] - preP[i]);

        ans = max(ans, max(SPlusP, max(SPlusH, max(PPlusS, max(PPlusH, max(HPlusS, HPlusP))))));

    }
    cout << ans << endl;
    
    return 0;
}






















