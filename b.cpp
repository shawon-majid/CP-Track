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

const int inf = 1e7+2;

set < int > s;

int main(){

    for(int i = 3; i <= inf; i+=3){
        int x = i/3;
        s.insert(x);
        s.insert(2*x);
    }

    int T;
    cin >> T;
    while(T--){
        int n, m;

        cin >> n >> m;

        if(n == m){
            cout << "YES\n";
            continue;
        }

        if(s.find(m) == s.end()){
            cout << "NO\n";
        }
        else{
            if(n % 3 != 0){
                cout << "NO\n";
            }
            else{
                int x = n/3;
                if(m > 2*x){
                    cout << "NO\n";
                }    
                else cout << "YES\n";
            }
            
        }
        

    }

    return 0;
}