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


void drawBoard(char board[3][3]){

    string row[] = {
        " ----------- ",
        "| " + string(1, board[0][0]) + " | " + string(1, board[0][1]) +
        " | " + string(1, board[0][2]) + " |",
        " ----------- ",
        "| " + string(1, board[1][0]) + " | " + string(1, board[1][1]) +
        " | " + string(1, board[1][2]) + " |",
        " ----------- ",
        "| " + string(1, board[2][0]) + " | " + string(1, board[2][1]) +
        " | " + string(1, board[2][2]) + " |",
        " ----------- "
    };

    for(auto x: row){
        cout << x << "\n";
    }

    board[0][0] = 'x';
}


pair <int, int > getPlayerMove(){
    cout << "                    1 2 3\n";
    cout << "                    4 5 6\n";
    cout << "Choose your square: 7 8 9\n";

}

int main(){

    char board[3][3] = {
        ' ', ' ', ' ', 
        ' ', ' ', ' ',
        ' ', ' ', ' '
    };




    drawBoard(board);

    getPlayerMove();
    


    return 0;
}