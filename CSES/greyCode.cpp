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

/*
    Grey Code
We can come up with a recrusive solution to get all the grey
codes. To find out grey codes of n bit, lets assume we already
know the grey codes of n-1 bits. 
Let the list of (n-1)-bit Gray codes be L1. 
1. Create another list L2 which is reverse of L1.
2. Modify the list L1 by prefixing a ‘0’ in all codes of L1.

(Understand that here L1 list is already gray code and by 
adding 0's to first we aren't altering any bits and keeping
it grey)

3. Modify the list L2 by prefixing a ‘1’ in all codes of L2.

(Understand that here L2 list is also already gray code and by 
adding 1's to first we aren't altering any bits and keeping
it grey)

4. Concatenate L1 and L2. The concatenated list is required
list of n-bit Gray codes

*/

vector < string > getGreyCodes(int n){
    vector < string > ret;
    if(n == 1){
        ret.push_back("0");
        ret.push_back("1");
        return ret;
    }
    vector < string > l1 = getGreyCodes(n-1);
    vector < string > l2;
    for(int i = l1.size()-1; i >= 0; i--){
        l2.push_back(l1[i]);
    }

    for(int i = 0; i < l1.size(); i++){
        ret.push_back("0"+l1[i]); 
    }
    for(int i = 0; i < l2.size(); i++){
        ret.push_back("1"+l2[i]); 
    }

    return ret;
}


int main(){

    int n;
    cin >> n;

    vector < string > ans = getGreyCodes(n);

    for(auto s: ans){
        cout << s << endl;
    }

    return 0;
}