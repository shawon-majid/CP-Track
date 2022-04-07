//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;

int iRand(int min, int max) //range : [min, max]
{
   static bool first = true;
   if (first) 
   {  
      srand( time(NULL) ); //seeding for the first time only!
      first = false;
   }
   return min + rand() % (( max + 1 ) - min);
}

ll f1(int n, int k){

    int somoy = 0, tot = 1;
    while(tot < n){
        somoy++;   
        tot += min(k, somoy);
    }
	return somoy;

}

ll f2(double n, double k){

    double x = sqrt((8*n - 7)) - 1;
    x /= 2;

    ll xx = ceil(x);

    if(xx <= (ll)k){
        return xx;
    }
    else{
        double rem = ((n/k) - ((k+1)/2) - (1/k));

        return (ll)(k+ ceil(rem));
    }
}

int main(){

	srand(time(0));

	cout << iRand(-100, 1) << endl;

    return 0;
}