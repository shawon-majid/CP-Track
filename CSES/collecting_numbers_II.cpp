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

const ll mx = 2e5;

ll f[mx+10], pos[mx+10];

int main(){

    ll n, m;

    cin >> n >> m;

    vector< ll > ara(n);

    for(auto &x: ara) cin >> x;

    
    
    ll cnt=0;
    for(ll i = 0; i < n; i++){
        pos[ara[i]] = i;
        if(f[ara[i]-1] == 0){
            cnt++;
        }
        f[ara[i]] = 1;
    }

    pos[0] = -1;

    while(m--){
        ll a, b;
        cin >> a >> b;  
        a--;
        b--;

        ll num1 = ara[a];
        ll num2 = ara[b];

        // for(auto x: ara) cout << x << ' ';
        // cout << endl;
        // for(auto x: ara) cout << pos[x] << ' ';
        // cout << endl;

        swap(ara[a], ara[b]); 

        // relative positions with num1-1
        if(pos[num1-1] <= pos[num1]){
            if(pos[num1-1] > b){
                cnt++;
            }
        }
        if(pos[num1-1] > pos[num1]){
            if(pos[num1-1] <= b){
                cnt--;
            }
        }

        // relative positions with num1+1
        if(pos[num1+1] >= pos[num1]){
            if(pos[num1+1] < b){
                cnt++;
            }
        }
        if(pos[num1+1] < pos[num1]){
            if(pos[num1+1] >= b){
                cnt--;
            }
        }

        pos[num1] = b;

        // relative positions with num2-1

        if(pos[num2-1] <= pos[num2]){
            if(pos[num2-1] > a){
                cnt++;
            }
        }
        if(pos[num2-1] > pos[num2]){
            if(pos[num2-1] <= a){
                cnt--;
            }
        }

        // relative positions with num2+1
        if(pos[num2+1] >= pos[num2]){
            if(pos[num2+1] < a){
                cnt++;
            }
        }
        if(pos[num2+1] < pos[num2]){
            if(pos[num2+1] >= a){
                cnt--;
            }
        }

        pos[num2] = a;

        cout << cnt << endl;

        
    }



    return 0;
}