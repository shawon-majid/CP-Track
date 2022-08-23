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

q = composite number
p = smaller prime factor of q
i = any integer

q = ip

here, i >= p because, i must be greater than smallest prime factor


no prime less then p can divide i. Because if i can be divided 
by any prime less then p, than that prime would be the smallest
prime p.




*/

const int mx = 1e6;


bool isComposite[mx];

vector < int > primes;

void linear_sieve(int limit){

	for(int i = 2; i <= limit; i++){
		
		// jokhon i niye kaj kortesi tokhon, already i er che
		// choto prime gula primes vector e ase.

		cout << "current number : " << i << endl;

		if(isComposite[i] == 0){
			primes.push_back(i);
		}
		for(int j = 0; j < primes.size() && i*primes[j] <= limit; j++){

			cout << "current prime -> " << primes[j] << " current composite : " << i*primes[j] << endl;


			isComposite[i*primes[j]] = true;
			if(i % primes[j] == 0){
				break;
			}
			
		}

		cout << "finished for current number." << endl;
	}

}


int main(){

	linear_sieve(100);

	cout << primes.size() << endl;

	for(auto x: primes){
		cout << x << endl;
	}


    return 0;
}