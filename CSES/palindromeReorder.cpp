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
 
    map <char, int> cnt;
    for(auto c: str){
        cnt[c]++;
    }
    int even = 0, odd = 0;
    deque <char> dq;
    for(auto x: cnt){
        if((x.second & 1) != 0){
            odd++;
            for(int i=0; i < x.second; i++){
                dq.push_back(x.first);
            }
        }
    }
 
    if(odd == 0 or odd == 1){
        for(auto x:cnt){
            if((x.second & 1) == 0){
                for(int i = 0; i < x.second; i++){
                    if((i & 1) == 0){
                        dq.push_front(x.first);
                    }
                    else{
                        dq.push_back(x.first);
                    }
                }
            }
        }
 
        for(auto x:dq) cout <<x;
        cout << endl;
    }
    else cout << "NO SOLUTION" << endl;
 
    return 0;
}
