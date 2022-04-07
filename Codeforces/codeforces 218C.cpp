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

    int k1;
    cin >> k1;

    deque <int> p1;

    for(int i = 0; i < k1; i++){
        int x;
        cin >> x;
        p1.push_front(x);
    }

    int k2;
    cin >> k2;

    deque <int> p2;

    for(int i = 0; i < k2; i++){
        int x;
        cin >> x;
        p2.push_front(x);
    }
    int cnt = 0;
    bool p1Win = 0, noSol = 0;
    while(1){
        if(p1.empty()){
            break;
        }
        if(p2.empty()) {
            p1Win = 1;
            break;
        }

        p11 = p1.front();
        p22 = p2.front();

        p1.pop_front();
        p2.pop_front();

        if(p11 > p22){
            p1.push_back(p22);
            p1.push_back(p11);
        }
        else{
            p2.push_back(p11);
            p2.push_back(p22);
        }
        cnt++;
        if(cnt == 1e6){
            noSol = 1;
            break;
        }
    }

    if(noSol){
        cout << -1 << endl;
        return 0;
    }

    if(p1Win){
        cout << cnt << " " << 1 << endl;
    }
    else cout << cnt << " " << 2 << endl;


    return 0;
}