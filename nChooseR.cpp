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

// nChooseR by pascal's recursive formula
// check Mahbubul Alam Shanto book

const int lim = 100;
const int mod = 1e6+7;

ll ncr[lim][lim];

void sieveNCR(){
    ncr[0][0] = 1;
    for(int i = 1; i <= lim; i++){
        for(int j = 0; j <= lim; j++){
            if(j > i){
                ncr[i][j] = 0;
            }
            else if(i == 1 or j == 0){ // 1c1 1c0 or anythingC0
                ncr[i][j] = 1;
            }
            else{
                ncr[i][j] = ((ncr[i-1][j-1] % mod) + (ncr[i-1][j] % mod)) % mod ;
            }
        }
    }
}

int main(){

    sieveNCR();

    cout << ncr[10][4] << endl;

    return 0;
}