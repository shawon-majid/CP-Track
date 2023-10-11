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

int mark[mx]; // 0 means prime

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

}


int main(){

    bitwiseSieve(10000007);


    int T;
    cin >> T;
    while(T--){
        int n, q;
        cin >> n >> q;

        vector < int > ara(n);
        set < int > p;
        for(int i = 0; i < n; i++){
            cin >> ara[i];

            if(check(mark[ara[i]/32], ara[i] % 32) == 0){
                p.insert(i);
            }
        }


        while(q--){
            int type;
            cin >> type;

            if(type == 1){
                int x;
                cin >> x;

                x--;

                int firstPIndexAfterX;

                auto it1 = p.upper_bound(x);


                if(it1 == p.end()){
                    firstPIndexAfterX = n;
                }
                else{
                    firstPIndexAfterX = *(it1);
                }

                auto it = p.lower_bound(x);

                int lastPindexBeforeX;

                if(it != p.begin()){
                    it--;
                    lastPindexBeforeX = *(it);
                }
                else{
                    lastPindexBeforeX = -1;
                }

                cout <<(firstPIndexAfterX-x-1) + (x-lastPindexBeforeX-1) << "\n";


            }
            else{
                int x, y;
                cin >> x >> y;
                x--;


                p.erase(x);

                if(check(mark[y/32], y % 32) == 0){
                    
                    p.insert(x);
                    
                }
            }

        }

    }

    return 0;
}