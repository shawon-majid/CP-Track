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

    int n, m, k;
    cin >> n >> m >> k;

    vector <int> desired(n), apartment(m);

    for(auto &x: desired) cin >> x;

    for(auto &x: apartment) cin >> x;


    sort(all(desired));
    sort(all(apartment));

    int i = 0, j = 0;
    int cnt = 0;
    while(i < n and j < m){
        if(apartment[j] >= desired[i]-k and apartment[j] <= desired[i] + k){
            i++;
            j++;
            cnt++;
        }
        else if(apartment[j] < desired[i] - k){
            j++;
        }
        else if(apartment[j] > desired[i] + k){
            i++;
        }
        else{
            assert(false);
        }
    }
    cout << cnt << endl;

    return 0;
}