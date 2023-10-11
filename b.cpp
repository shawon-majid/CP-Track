//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef unsigned long long ull;
typedef long long ll;


int main(){

    int totalWeeks, classPerWeek, goneWeek, participated;

    cin >> totalWeeks >> classPerWeek >> goneWeek >> participated;


    int totalClass = totalWeeks * classPerWeek;


    int requiredClass = ceil((double)totalClass * 0.6);

    int need = requiredClass - participated;

    // debug(need);

    int remainingWeek = totalWeeks - goneWeek;

    // debug(remainingWeek);

    int remainingClass = remainingWeek * classPerWeek;

    
    if(need > remainingClass){
        cout << "No\n";
    }
    else{
        vector < int > ans;
        
        for(int i = 0; i < remainingWeek; i++){

            if(need <= 0){
                ans.push_back(0);
            }

            else if(classPerWeek >= need){
                ans.push_back(need);
                need = 0;
            }
            else{

                ans.push_back(classPerWeek);
                need -= classPerWeek;

            }
        }

        if(need != 0){
            cout << "No\n";
        }
        else{
            cout << "Yes\n";
            for(int i = ans.size()-1; i >= 0; i--){
                cout << ans[i] <<" ";
            }
            cout << "\n";
        }


        

    }   




    return 0;
}