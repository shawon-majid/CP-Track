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

    int n1, n2;
    cin >> n1 >> n2;

    vector < string > gollum(n1);

    for(int i = 0; i < n1; i++){
        cin >> gollum[i];
    }

    int m1, m2;
    cin >> m1 >> m2;

    vector < string > aragon(m1);

    for(int i = 0; i < m1; i++){
        cin >>aragon[i];
    }

    // int k = 0, l = 0;

    // bool f = 0;

    vector < pair < int, int > > ans;

    for(int i = 0; i < m1; i++){
        for(int j = 0; j < m2; j++){

            if(aragon[i][j] == gollum[0][0]){

                int m = i, n = j;

                bool f = 1;

                for(int k = 0; k < n1; k++){
                    for(int l = 0; l < n2; l++){
                        if(m+k >= m1 || n+l >= m2 || gollum[k][l] != aragon[m+k][n+l]){
                            f = 0;
                            break;   
                        }
                    }
                }

                if(f){
                    ans.push_back({i, j});
                }
            }

        }
        
    }

    if(ans.size()){
        for(auto x: ans){
            cout << "("<<x.first+1 << "," << x.second+1 << ")\n";
        }
    }
    else{
        cout << "NO MATCH FOUND...\n";
    }


    return 0;
}