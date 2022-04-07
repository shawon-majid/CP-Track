//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;


// floyd warshal algo

const int inf = 1e8;

int main(){

    int s;
    cin >> s;
    while(s--){
        int n;
        cin >> n;

        int mat[n+10][n+10];
    
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                
                if(i != j) mat[i][j] = inf;
                else mat[i][j] = 0;
            }
        }

        map <string, int> indexOf;

        for(int i = 1; i <= n; i++){
            string name; // name of the city
            cin >> name;
            indexOf[name] = i;

            int p; // number of neighbours
            cin >> p;
            while(p--){
                int x, cost;
                cin >> x >> cost;
                mat[i][x] = cost;
            }
        }

        for(int k = 1; k <= n; k++){
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }

        int r;
        cin >> r;
        while(r--){
            string source, destination;
            cin >> source >> destination;

            cout << mat[indexOf[source]][indexOf[destination]] << endl;

        }
    }

    return 0;
}