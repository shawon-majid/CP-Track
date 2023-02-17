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


vector < int > createlps(string pattern){

    int n = pattern.size();

    vector < int > lps(n);

    lps[0] = 0;
    int j = 0;
    for(int i = 1; i < n; i++){
        if(pattern[i] == pattern[j]){
            j++;
            lps[i] = lps[i-1] + 1;
        }
        else{
            lps[i] = 0;
            j = 0;

            if(pattern[i] == pattern[j]){
                j++;
                lps[i] = 1;
            }
        }
    }

    return lps;

}

int kmp(string text, string pattern, vector < int > lps){
    
    int n = text.size();
    int m = pattern.size();

    int j = 0;

    for(int i = 0; i < n; i++){
        if(text[i] == pattern[j]){
            j++;
            if(j == m){
                return i - m + 1;
            }
        }
        else{
            if(j != 0){
                j = lps[j-1];
                i--;
            }
        }   
    }

    return -1;

}


int main(){

    string text, pattern;

    cin >> text >> pattern;

    vector < int > lps = createlps(pattern);

    int ind = kmp(text, pattern, lps);

    cout << ind << "\n";


    return 0;
}