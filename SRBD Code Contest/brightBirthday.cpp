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

vector < string > c{"blue", "green", "yellow", "red", "purple", "orange", "pink", "grey", "cyan", "brown", "ash", "silver", "gold", "white", "black"};

int main(){

    // cout << c.size() << "\n";


    int T;
    cin >> T;
    while(T--){
        string str;
        cin >> str;

        int n = str.size();

        map < char, int > gs;

        for(int i = 0; i < n; i++){
            gs[str[i]]++;
        }

        int ans = 0;

        for(int i = 0; i <= (1 << 15); i++){
            int cnt = 0;

            bool ok = 1;

            map < char, int > tempgs = gs;

            for(int j = 0; j < 15; j++){
                if(i & (1 << j)){
                    cnt++;
                    for(auto ch: c[j]){
                        if(tempgs[ch] == 0){
                            ok = 0;
                            break;
                        }
                        tempgs[ch]--;
                    }
                }

                if(!ok) break;
            }


            if(ok){
                ans = max(ans, cnt);
            }
        }


        cout << ans << "\n";

            
    }

    return 0;
}