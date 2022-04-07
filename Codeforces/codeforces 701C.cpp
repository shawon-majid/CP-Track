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
    string str;

    cin >> str;

    map <char, int> m;  // used or not
    set <char> s; // for unique characters
    int total = 0;
    for(int i = 0; i < n; i++){
        s.insert(str[i]);
    }

    total = s.size(); // number of unique characters

    int i = 0;
    int j = 0;
    total--;
    m[str[i]]++;   // used the first character
    int ans = INT_MAX;

    while(i < n and j < n-1){
        if(total == 0){ // if every character is used get an answer
            ans = min(ans, j-i+1);
            m[str[i]]--;
            i++; // moving forward
            total++;
        }
        if(m[str[i]] > 1){ // making sure first character is not occuring multiple times
            while(m[str[i]] > 1){
                m[str[i]]--;
                i++;
            }
        }
        while(j < n-1 and total){
            if(m[str[i]] > 1){ // again making sure in the inner loop
                while(m[str[i]] > 1){
                    m[str[i]]--;
                    i++;
                }
            }
            if(str[j+1] == str[i]){  // if new char is same as first char we delete first one and take new one
                i++;
                j++;
            }
            else if(m[str[j+1]] == 0){ /* new char */
                m[str[j+1]]++;
                j++;
                total--;
            }
            else{
                j++;
                m[str[j]]++;
            }
        
        }
   
    }
    if(total == 0) ans = min(ans, j-i+1);
    cout << ans << endl;

    return 0;
}