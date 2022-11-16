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

vector < int > lp(mx, 0); // lowest prime
vector < int > primes;

void linear_sieve2(int limit){

    for(int i = 2; i <= limit; ++i){
        if(lp[i] == 0){ // this is prime
            lp[i] = i;
            primes.push_back(i);
        }
        
        for(int j = 0; j < primes.size() && i*primes[j] <= limit ; j++){
            if(primes[j] > lp[i]){
                break;
            }

            lp[i*primes[j]] = primes[j];

            
        }
    }
}


vector <int> getPrimeFactors(int x){
    vector <int> ans;

    while(x != 1){
        ans.push_back(lp[x]);
        x = x / lp[x];
    }    
    return ans;
}

int main(){


    linear_sieve2(20000);

    // cout << primes.size() << endl;
    // for(auto x: primes){
    //     cout << x << endl;
    // }

    for(auto x: getPrimeFactors(36)){
        cout << x << " ";
    }
    cout << endl;


    return 0;
}