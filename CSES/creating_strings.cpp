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

    string str;
    cin >> str;

    set < string > s;
    sort(all(str));

    do{
        s.insert(str);    
    }
    while(next_permutation(all(str)));

    cout << s.size() << endl;
    for(auto ss: s){
        cout << ss << endl;
    }

    return 0;
}