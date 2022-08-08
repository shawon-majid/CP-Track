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
vector < string > makeStrings(string str){
    vector <string> ans;
    if(str.size() == 1){
        ans.push_back("0");
        ans.push_back("1");
        return ans;
    }

    vector < string > ans1 = makeStrings(str.substr(1));
    for(int i = 0; i < ans1.size(); i++){
        ans.push_back("0"+ans1[i]);
    }
    for(int i = 0; i < ans1.size(); i++){
        ans.push_back("1"+ans1[i]);
    }
    return ans;
}

int main(){

    int n;
    cin >> n;
    string str = "";
    for(int i = 0; i < n; i++){
        str += "0";
    }

    vector < string > s = makeStrings(str);

    for(auto x: s){
        cout << x << endl;
    }

    

    return 0;
}
