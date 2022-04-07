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

    int n, k;
    cin >> n >> k;

    vector <int> ara(n+2);
    vector <int> indicator (n+2);
    for(int i = 1; i <= n+1; i++){
        ara[i] = 0;
    }

    while(k--){
        int l, r;
        cin >> l >> r;
        indicator[l] += 1;
        indicator[r+1] += -1;
    }

    for(int i = 1; i <= n+1; i++){
        ara[i] = ara[i-1] + indicator[i];
    }

    sort(ara.begin()+1, ara.end()-1);

    cout << ara[(n+1) / 2] << endl;


    return 0;
}