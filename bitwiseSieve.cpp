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

const int mx = 1e7+35;

vector < int > primes;

int mark[mx/32]; // 0 means prime

int check(int n, int pos){
    return (n & (1 << pos));
}


int on(int n, int k){
    return n = n | (1 << k); 
}

void bitwiseSieve(int limit){

    mark[1/32] = on(mark[1/32], 1 % 32);
    mark[0/32] = on(mark[0/32], 0 % 32);

    for(int i = 2; i*i <= limit; i++){
        if(check(mark[i/32], i % 32) == 0){ // means prime
            for(int j = i*i; j <= limit; j+=i){
                mark[j/32] = on(mark[j/32], j % 32);
            }
        }
    }

    for(int i = 2; i <= limit; i++){
        if(check(mark[i/32], i % 32) == 0){
            primes.push_back(i);
        }
    }

}


int main(){

    bitwiseSieve(10000007);

    cout << primes.size() << endl; 

    for(auto x: primes){
        cout << x << endl;
    }

    return 0;
}