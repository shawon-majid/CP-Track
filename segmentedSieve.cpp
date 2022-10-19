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

vector < int > primes;

int mark[mx]; // 0 means prime

int check(int n, int pos){
    return (n & (1 << pos));
}


int on(int n, int k){
    return n = n | (1 << k); 
}

void bitwiseSieve(int limit){

    mark[1/32] = on(mark[1/32], 1);
    mark[0] = on(mark[0], 0);

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


int arr[mx];
 
void segmentedSieve ( int a, int b ) {
    // you have to run bitwise sieve before running this function

    if ( a == 1 ) a++;
 
    int sqrtn = sqrt ( b );
 
    memset ( arr, 0, sizeof arr ); // Make all index of arr 0.
 
    for ( int i = 0; i < primes.size() && primes[i] <= sqrtn; i++ ) {
        int p = primes[i];
        int j = p * p;
 
        // If j is smaller than a, then shift it inside of segment [a,b]
        if ( j < a ) j = ( ( a + p - 1 ) / p ) * p;
 
        for ( ; j <= b; j += p ) {
            arr[j-a] = 1; // mark them as not prime
        }
    }
 
}

int main(){
    
    bitwiseSieve(1e5);

    segmentedSieve(11, 19);

    for(int i = 11; i <= 19; ++i){
        if(arr[i-11] == 0){
            cout << i << endl;
        }
    }


}