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

const int mx = 1e6;

int mark[mx];


void sieve(ll limit){
    mark[0] = mark[1] = 1; // zero stands for not prime
    for(int i = 2; i*i <= limit; i++){
        if(mark[i] == 0){ // prime
            for(int j = i*i; j <= limit; j+=i){
                mark[j] = 1;
            }
        }
    }
}

int main(){

    sieve(mx-1000);

    int n, m;
    cin >> n >> m;

    int mat[n][m];
    int inc[n][m];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            inc[i][j] = 0;
            while(mark[mat[i][j]] != 0){
                mat[i][j]++;
                inc[i][j]++;
            }
        }
    }

    int ans = INT_MAX;

    // check all the rows
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = 0; j < m; j++){
            sum += inc[i][j];
        }
        ans = min(ans, sum);
    }

    // check all the columns

    for(int j = 0; j < m; j++){
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += inc[i][j];
        }
        ans = min(ans, sum);
    }

    cout << ans << endl;

    return 0;
}