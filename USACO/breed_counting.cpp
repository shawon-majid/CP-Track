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

    setIO("bcount");
    
    int n, q;
    cin >> n >> q;

    vector <int> ids(n+1);
    for(int i = 1; i  <= n; i++){
        cin >> ids[i];
    }
    
    vector <int> numberOfOnes(n+1);
    vector <int> numberOfTwos(n+1);
    vector <int> numberOfThrees(n+1);

    numberOfOnes[0] = 0;
    numberOfTwos[0] = 0;
    numberOfThrees[0] = 0;
    int ones = 0, twos = 0, threes = 0;

    for(int i = 1; i <= n; i++){
        if(ids[i] == 1){
            ones++;
        }
        else if(ids[i] == 2){
            twos++;
        }
        else{
            threes++;
        }
        // cout << "ones: " << ones << endl;
        numberOfOnes[i] = ones;
        numberOfTwos[i] = twos;
        numberOfThrees[i] = threes;

    }

    while(q--){
        int l, r;
        cin >> l >> r;
        cout << numberOfOnes[r] - numberOfOnes[l-1] << " " << numberOfTwos[r] - numberOfTwos[l-1] << " " << numberOfThrees[r] - numberOfThrees[l-1] << endl;
    }

    return 0;
}
