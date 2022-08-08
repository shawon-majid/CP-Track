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
we will generate all the grey codes by trial and error method
we'll take a string and inverse any of its bit and check if 
that string is already taken or not. We'll do this until we
find all the answers
*/

int power(int a, int b){
    if(b == 0) return 1;
    if(b == 1) return a;

    int x = power(a, b/2);
    if(b % 2 == 0){
        return x*x;
    }
    else{
        return x*x*a;
    }
}

int main(){

    int n;
    cin >> n;

    int tot = power(2, n);

    string str = "";

    for(int i=0; i < n; i++){
        str += "0";
    }

    vector < string > ans;

    map < string, int > m;
    m[str] = 1;

    ans.push_back(str);
    string last = str;
    while(ans.size() != tot){
        string cur = last;
        for(int i = 0; i < n; i++){
            if(cur[i] == '0'){
                cur[i] = '1';
            }
            else{
                cur[i] = '0';
            }

            if(m.find(cur) == m.end()){
                m[cur] = 1;
                ans.push_back(cur);
                last = cur;
                break;
            }

            // reverse the change
            if(cur[i] == '0'){
                cur[i] = '1';
            }
            else{
                cur[i] = '0';
            }


        }


    }

    for(auto s: ans){
        cout << s << endl;
    }

    return 0;
}