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

    int n;
    cin >> n;
    vector < int > ara(n);

    for(int i = 0; i < n; i++){
        cin >> ara[i];
    }


    int i = 0, j = 0;
    int ans = 1;

    map < int , int > ase; // ase[number] = index;
    map < int , int > indexOf;

    for(int i = 0; i < n; i++){
        ase[ara[i]] = -1;
        if( !indexOf.count(ara[i]) ) indexOf[ara[i]] = i;
    }

    // for(auto x: indexOf){8



    ase[ara[0]] = 0;
    while(1){


        while(j+1 < n && ase[ara[j+1]] == -1){
            j++;
            ase[ara[j]] = j;
            indexOf[ara[j]] = j;
        }

        // debug(i);
        // debug(j);

        ans = max(ans, j-i+1);


        if(j+1 >= n){
            break;
        }
        if(ase[ara[j+1]] != -1){

            for(int k = i; k <= indexOf[ara[j+1]]; k++){
                ase[ara[k]] = -1;
            }

            i = indexOf[ara[j+1]] + 1;

            indexOf[ara[j+1]] = j+1;
            ase[ara[j+1]] = -1;
        }

        // if(i > j){
        //     j = i;
        // }

    }

    cout << ans << endl;
    return 0;
}