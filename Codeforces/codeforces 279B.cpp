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

    int n, t;
    cin >> n >> t;

    vector <int> times(n+1), pre(n+1);
    
    for(int i = 1; i <= n; i++){
        cin >> times[i];
    }

    pre[0] = 0;
    for(int i = 1; i <= n; i++) pre[i] = pre[i-1] + times[i];

    int j = 1;
    int ans = -1;
    for(int i = 1; i <= n; i++){
        while(j <= n){
            int sum = pre[j] - pre[i-1];
            if(sum > t){
                break;
            }
            j++;
        }
        ans = max(ans, (j-1)-i+1);
    }
    cout << ans << endl;


    return 0;
}