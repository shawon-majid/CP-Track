//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;

string str;

int rec(int start, int end, char c){
    if(start == end){ // base case
        if(str[start] == c){
            return 0;
        }
        else return 1;
    }
    
    int mid = (start+end)/2;
    
    int nC1 = 0, nC2 = 0;
    // check first half
    for(int i = start; i <= mid; i++){
        if(str[i] != c){
            nC1++;
        }
    }

    // check second half 
    for(int i = mid+1; i <= end; i++){
        if(str[i] != c){
            nC2++;
        }
    }
    int m1 = nC1 + rec(mid+1, end, c+1);
    int m2 = nC2 + rec(start, mid, c+1);
    return min(m1, m2);
}

int main(){

    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;        
        cin >> str;
        cout << rec(0, n-1, 'a') << endl; 
    }

    return 0;
}   