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

    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector < int > ara(n);
        for(int i = 0; i < n; i++){
            cin >> ara[i];
        }

        int pos = 0, neg = 0;
        for(int i = 0; i < n; i++){
            if(ara[i] < 0){
                neg++;
            }
            else pos++;
        }

        bool flag = 1;
        int prev = abs(ara[0]);
        for(int i = 1; i < neg; i++){
            int cur = abs(ara[i]);
            if(cur > prev){
                
                flag = false;
            }
            prev = cur;
        }
        prev = abs(ara[neg]);
        for(int i = neg; i < n; i++){
            int cur = abs(ara[i]);
            if(cur < prev){

                flag = false;
            }
            prev = cur;
        }

        if(flag){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
        
    }

    return 0;
}