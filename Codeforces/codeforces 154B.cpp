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


bool isComposite[mx];

vector < int > primes;

void linear_sieve(int limit){

    isComposite[1] = 1;

    for(int i = 2; i <= limit; i++){
        
        // jokhon i niye kaj kortesi tokhon, already i er che
        // choto prime gula primes vector e ase.

        if(isComposite[i] == 0){ // this number is prime
            primes.push_back(i);
        }
        for(int j = 0; j < primes.size() && i*primes[j] <= limit; j++){
            
            isComposite[i*primes[j]] = true;
            if(i % primes[j] == 0){
                break;
            }
            
        }
    }

}

vector < int > ase(mx, 0); // int ase[mx];
vector < int > pfase(mx, 0);
vector < int > karjonno(mx);

int main(){

    

    int n, m;
    cin >> n >> m;

    linear_sieve(n+5);

    while(m--){
        char type;
        int x;
        cin >> type >> x;


        if(type == '+'){

            int temp = x;
            if(ase[x] == 1){
                cout << "Already on" << endl;
            }
            else{
                if(isComposite[x] == false){
                    // debug(x);
                    if(pfase[x]){
                        cout << "Conflict with " << karjonno[x] << endl;
                    }
                    else{
                        cout << "Success" << endl;
                        ase[x] = 1;
                        pfase[x] = 1;
                        karjonno[x] = x;
                    }
                    
                }
                else{
                    // let us get prime factors of x
                    bool addkorteParbo = 1;
                    vector < int > newPrimeFactors;

                    for(int i = 2; i*i <= x; i++){
                        if(x % i == 0){

                            if(pfase[i]){
                                cout << "Conflict with " << karjonno[i] << endl;
                                addkorteParbo = 0;

                                // delete all the new prime factors
                                for(auto y: newPrimeFactors){
                                    pfase[y] = 0;
                                    karjonno[y] = 0;
                                }

                                break;
                            }

                            while(x % i == 0){
                                x /= i;
                            }

                            pfase[i] = 1;
                            karjonno[i] = temp;
                            newPrimeFactors.push_back(i);

                        }
                    }

                    if(addkorteParbo){
                        if(x > 1){ // if x is still not 1, then x is prime it self
                            if(pfase[x]){
                                cout << "Conflict with " << karjonno[x] << endl;
                                addkorteParbo = 0;
                                for(auto y: newPrimeFactors){
                                    pfase[y] = 0;
                                    karjonno[y] = 0;
                                }
                            }
                            else{
                                pfase[x] = 1;
                                karjonno[x] = temp;
                            }
                        }    
                    }

                    if(addkorteParbo){
                        cout << "Success" << endl;
                        ase[temp] = 1;
                    }

                }
            }   
        }
        else{
            // - ashce, remove korte hobe
            if(ase[x] == 0){
                cout << "Already off" << endl;
            }
            else{
                cout << "Success" << endl;
                ase[x] = 0;

                for(int i = 2; i*i <= x; i++){
                    if(x % i == 0){
                        while(x % i == 0){
                            x /= i;
                        }

                        pfase[i] = 0;
                    }
                }

                if(x > 1){
                    pfase[x] = 0;
                }

            }

        }
    }



    return 0;
}