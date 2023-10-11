//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef unsigned long long ull;
typedef long long ll;


int main(){

    int T, cs = 1;
    cin >> T;
    while(T--){
        int p;
        cin >> p;


        int sum = 0;

        vector < int > ans;

        for(int i = 2; i*i <= p; i++){
            if(p % i == 0){
                while(p % i == 0){
                    sum += i;
                    ans.push_back(i);
                    p /= i;
                }
            }
        }

        if(p > 1){
            sum += p;
            ans.push_back(p);
        }


        cout << "Case #"<<cs++<<": ";

        if(sum > 41){
            cout << -1 << "\n";
        }
        else{
            int need1 = 41 - sum;
            cout << ans.size() + need1 << " ";

            // sort(all(ans));

            for(int i = 0; i < need1; i++){
                cout << 1 << " ";
            }

            for(auto x: ans){
                cout << x << " ";
            }
            

            cout << "\n";
        }

    }

    return 0;
}