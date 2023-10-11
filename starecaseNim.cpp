//Bismillahir Rahman-ir Rahim
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef unsigned long long ull;
typedef long long ll;


int main(){

    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;

        vector < int > ara(n);

        

        for(int i = 0; i < n; i++){
            cin >> ara[i];
        }

        int xorsum = 0;

        int prev = 0;


        sort(all(ara));

        for(int i = n-1; i >= 0; i-=2){

            prev = (i <= 0) ? 0 : ara[i-1];
            xorsum ^= (ara[i] - prev - 1);
            
        }   

        // debug(xorsum);

        if(xorsum){
            cout << "Georgia will win\n";
        }
        else cout << "Bob will win\n";
    }

    return 0;
}