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


int minimax(int currentDepth, int totalHeight, int index, bool isMax, vector < int > &leaves){

    if(currentDepth == totalHeight){
        return leaves[index];
    }

    if(isMax){ // maximizing move
        return max( 
                    minimax(currentDepth+1, totalHeight, 2*index, false, leaves), 
                    minimax(currentDepth+1, totalHeight, 2*index + 1, false, leaves)
                  );
    }
    else{ // minimizing move
        return min(
                    minimax(currentDepth+1, totalHeight, 2*index, true, leaves),
                    minimax(currentDepth+1, totalHeight, 2*index + 1, true, leaves)
                  );
    }

}


int main(){

    int number_of_leaf;
    cout << "Enter the number of leaf(must be power of 2): ";
    cin >> number_of_leaf;

    cout << "Enter the leaves:\n";

    vector < int > leaves(number_of_leaf);

    for(int i = 0; i < number_of_leaf; i++){
        cin >> leaves[i];
    }

    bool isMax;

    cout << "Press - 1 if maximizer plays first move\nPress - 0 if minimizer plays first move\n: ";
    
    cin >> isMax; 


    int totalHeight = log2(number_of_leaf);


    cout << "The answer is: ";
    cout << minimax(0, totalHeight, 0, isMax, leaves) << "\n";





    return 0;
}