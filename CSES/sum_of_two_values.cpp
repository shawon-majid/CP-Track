//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;
 
int main(){
 
    ll n, x;
    cin >> n >> x;
    
    vector < pair<ll, ll> > ara(n);
 
    for(ll i = 0; i < n; i++){
        cin >> ara[i].first;
        ara[i].second = i;
    }
 
    sort(all(ara));
    bool ok = 0;
    ll indI, indJ;
    int i = 0, j = n-1;    
    while(i < j){
        if((ara[i].first + ara[j].first) > x){
            j--;
        }
        else if((ara[i].first + ara[j].first) < x){
            i++;
        }
        else if((ara[i].first + ara[j].first) == x){
            indI = ara[i].second, indJ = ara[j].second;
            ok = 1;
            break;
        }
    }
    if(ok){
        ll temp = indJ+indI;
        indI = min(indI, indJ);
        indJ = temp - indI;
        cout << indI+1 << " " << indJ+1 << endl;
    }
    else{
        cout << "IMPOSSIBLE" << endl;
    }
 
    return 0;
}