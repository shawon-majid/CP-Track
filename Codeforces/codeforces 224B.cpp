//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;

const int mx = 1e6;
int vis[mx];

int main(){

    int n, k;
    cin >> n >> k;

    vector <int> ara(n);

    for(auto &x: ara) cin >> x;

    if(k == 1){
        cout << 1 << ' ' << 1 << endl;
        return 0;
    }

    int cnt = 1;
    bool ok = 0;
    
    int left = 0, right = 0;

    vis[ara[left]] = 1;

    map <int, int> ase;
    ase[ara[left]]++;

    while(right < n-1){

        if(ara[right+1] == ara[left]){
            right++;
            left++;
            while(left < n-1 and ase[ara[left]] > 1 and left < right){
                left++;
                ase[ara[left]]--;
            } 
        }
        else {
            right++;
            if(!vis[ara[right]]){
                vis[ara[right]] = 1;
                cnt++;
            }
            ase[ara[right]]++;
        }

        if(cnt == k){
            ok = 1;
            break;
        }

    }

    if(ok)cout << left+1 << " " << right+1 << endl;
    else cout << -1 << " " << -1 << endl;

    return 0;
}