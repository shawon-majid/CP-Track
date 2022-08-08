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


/* derangement number 
    
In how many ways can we put 5 different letters 
into 5 different envelopes so that all the letters 
go into the wrong envelopes?

Ans: Lets say we picked the first letter, we can put it in the
wrong envelopes in 5-1 ways. Lets say we put it on letter X's envelope.
Now we have 2 choice for the letter X.
1. Either we put the letter in the first letter's envelope.
2. Or we put the letter some other envelope

for the first case if we put the letter in first envelope, then we just 
need to solve for the remaining 5-2 = 3 laters. 

for the second case if we don't put the letter in the first envelope, 
then we need to solve for the remaining 5-1 = 4 letters

so the recurrence relation is:

    f(n) = (n-1)*f(n-2) + (n-1)*f(n-1)


*/

int derangement(int n){
    // prepare the base cases
    if(n == 0) return 1;
    if(n == 1) return 0;
    return (n-1)*derangement(n-2) + (n-1)*derangement(n-1); 
}

int main(){

    int n = 5;

    cout << derangement(n) << endl;


    return 0;
}
