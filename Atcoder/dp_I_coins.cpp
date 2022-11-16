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


/*
The idea is to take an element or not, and add the probabilty by
taking and not taking.

we will also maintain so far number of head to check condition at
the base case

f(pos, soFarHead)

*/

int n;

vector < double > ara;

double dp[3001][3001];

double f(int pos, int soFarHead){

    if(dp[pos][soFarHead] != -1){
        return dp[pos][soFarHead];
    }


    if(pos == n-1){

        // 2 cases
        // we can either choose to take head or not

        double op1 = 0;
        double op2 = 0;

        // we can take head if the so far head + 1 is greater than tails

        if(soFarHead+1 > (n- (soFarHead+1))){
            op1 = ara[pos];
        }


        // we can take tails if the so far head is greater than tails
        if(soFarHead > (n - soFarHead)){
            op2 = 1-ara[pos];
        }


        return dp[pos][soFarHead] = op1 + op2;

    }

    double op1 = ara[pos] * f(pos+1, soFarHead+1); // take head

    double op2 = (1-ara[pos]) * f(pos+1, soFarHead); // take tail

    return dp[pos][soFarHead] = op1+op2;


}


int main(){

    cin >> n;
     
    ara.resize(n);

    cout << fixed << setprecision(10);

    for(int i = 0; i <= n+1; i++){
        for(int j = 0; j <= n+1; j++){
            dp[i][j] = -1.0;
        }
    }

    for(int i = 0; i < n; i++){
        cin >> ara[i];
    }

    cout << f(0, 0) << "\n";

    return 0;
}