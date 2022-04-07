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

    int n;
    cin >> n;
    vector <int> ara(n);

    for(auto &x: ara){
        cin >> x;
    }

    vector <int> ans;

    ans.push_back(INT_MAX);

    for(int i = 0; i < n; i++){
        int ub = upper_bound(all(ans), ara[i]) - ans.begin();
        if(ub == ans.size()){
            ans.push_back(ara[i]);
        }
        else{
            ans[ub] = ara[i];
        }
    }    

    cout << ans.size() << endl;


    return 0;
}