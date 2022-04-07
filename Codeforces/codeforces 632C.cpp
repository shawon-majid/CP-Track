//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;


bool cmp(string a, string b){
    return a+b < b+a;
}

int main(){

    int n;
    cin >> n;
    vector <string> v;
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        v.push_back(str);
    }

    sort(all(v), cmp);

    string ans = "";

    for(int i = 0; i < n; i++){
        ans += v[i];
    }

    cout << ans << endl;

    return 0;
}