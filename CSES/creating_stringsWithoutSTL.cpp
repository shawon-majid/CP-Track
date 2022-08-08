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

vector < string > generatePerm(int n, string str){
    vector < string > ret;
    if(n == 1){
        string s;
        s.push_back(str[n-1]);
        
        ret.push_back(s);
        return ret;
    }

    string currentLetter;
    currentLetter.push_back(str[n-1]);
    vector < string > prevPerm = generatePerm(n-1, str);
    for(int i = n-1; i >= 0; i--){
        for(int j = 0; j < prevPerm.size(); j++){
            string currentString = prevPerm[j];
            currentString.insert(i, currentLetter);
            ret.push_back(currentString);
        }
    }

    return ret;
}


int main(){

    string str;
    cin >> str;
    int n = str.size();

    vector < string > perm = generatePerm(n, str);
    set < string > st;
    for(auto s: perm){
        st.insert(s);
    }

    cout << st.size() << endl;
    for(auto s: st){
        cout << s << endl;
    }

    return 0;
}