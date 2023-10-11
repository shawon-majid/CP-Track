//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef unsigned long long ull;
typedef long long ll;


// sum of xor's of all possible subsets of an array

// Input :  arr[] = {1, 5, 6}
// Output : 28
// Total Subsets = 23
// 1 = 1
// 5 = 5
// 6 = 6
// 1 ^ 5 = 4
// 1 ^ 6 = 7
// 5 ^ 6 = 3
// 1 ^ 5 ^ 6 = 2
// 0(empty subset)
// Now SUM of all these XORs = 1 + 5 + 6 + 4 +
//                             7 + 3 + 2 + 0
//                           = 28


int main(){

    int n;
    cin >> n;
    vector < int > ara(n);
    int orr = 0;
    for(int i = 0; i < n; i++){
        cin >> ara[i];
        orr |= ara[i];
    }
    int ans = 0;
    for(int i = 0; i <= 30;  i++){
        if(orr & (1 << i)){
            ans += pow(2, n-1+i); // 2^(n-1) * 2^i 
        }
    }
    cout << ans << "\n";
    return 0;
}