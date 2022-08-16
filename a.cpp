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


int main(){

    fastIO

    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector < int > ara(n);

        bool zeroExists = 0;
        int zeros = 0;

        for(int i = 0; i < n; i++){
            cin >> ara[i];
            if(ara[i] == 0){
                zeroExists = 1;
                zeros++;
            }
        }

        // atleast one dif
        bool aod = 0;

        for(int i = 0; i < n-1; i++){
            if(ara[i] != ara[i+1] && !zeroExists){
                aod = 1;
            }
        }

        // debug(aod);

        if(aod){
            
            int small = *min_element(all(ara));

            bool vanish = 0;
            int cnt = 0;

            for(int i = 0; i < n; i++){
                if(ara[i]%small != 0){
                    vanish = 1;
                    break;
                }
                if(ara[i] == small) {
                    cnt++;
                }

            }

            if(vanish){
                cout << 1 << endl;
            }
            else{
                cout << (cnt+1)/2 << endl;
            }


            continue;
        }

        // debug(zeroExists);

        if(!zeroExists){
            // cout << "t1" << endl;
            cout << (n+1)/2 << endl;
            continue;
        }

        else{
            cout << zeros + (n+1)/2 << endl;
        }






    }

    return 0;
}