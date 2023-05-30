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
}


void getPlayerMove(char board[3][3]){
    cout << "                    1 2 3\n";
    cout << "                    4 5 6\n";
    cout << "Choose your square: 7 8 9\n";

    int n;
    cin >> n;

    int x = (n-1)/3;
    int y = (n-1)%3;

    board[x][y] = 'x';

    return;

}


bool checkForWin(char board[3][3], char c){
    // check for row

    for(int i = 0; i < 3; i++){
        bool win = 1;
        for(int j = 0; j < 3; j++){
            if(board[i][j] != c) win = 0;
        }
        if(win) return true;
    }

    // check for column

    for(int j = 0; j < 3; j++){
        bool win = 1;
        for(int i = 0; i < 3; i++){
            if(board[i][j] != c) win = 0;
        }
        if(win) return true;
    }

    // check for diagonal l -> r

    bool win = 1;

    for(int i = 0; i < 3; i++){
        if(board[i][i] != c) win = 0;
    }

    if(win) return true;

    // check for diagonal r -> l

    win = 1;
    // {0, 2}, {1, 1}, {2, 0}
    for(int i = 0, j = 2; i < 3; i++, j--){
        if(board[i][j] != c) win = 0;
    }

    if(win) return true;


    return false;
}

bool checkForDraw(char board[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] == ' ') return false;
        }
    }

    return true;
}

bool isFree(char board[3][3], int x){
    if(board[(x-1)/3][(x-1)%3] == ' ') return true;
    return false;
}

pair < int, pair < int, int > > minimax(char board[3][3], char c){
    // o is minimizing, x is maximizing 

    // base cases 

    if(checkForWin(board, 'o')){
        return {-1, {-1, -1}};
    }
    else if(checkForWin(board, 'x')){
        return {1, {-1, -1}};
    }
    else if(checkForDraw(board)) return {0, {-1, -1}};


    if(c == 'x'){
        int mx = -1;
        int row, col;
        for(int i = 1; i < 10; i++){
            if(isFree(board, i)){
                int x = (i-1)/3;
                int y = (i-1)%3;
                board[x][y] = c;
                pair < int, pair < int, int > >res = minimax(board, 'o');
                if(res.first > mx){
                    mx = res.first;
                    row = x;
                    col = y;
                }
                board[x][y] = ' ';
            }
        } 

        return {mx, {row, col}};   
    }
    else{
        int mn = 1;
        int row, col;
        for(int i = 1; i < 10; i++){
            if(isFree(board, i)){
                int x = (i-1)/3;
                int y = (i-1)%3;
                board[x][y] = c;
                pair < int, pair < int, int > > res = minimax(board, 'x');
                if(res.first < mn){
                    mn = res.first;
                    row = x;
                    col = y;
                }
                board[x][y] = ' ';
            }
        }    

        return {mn, {row, col}};
    }

}   

void getOpponentMove(char board[3][3]){ // 0 min, 1 max

    // opponent is minimizing player

    pair < int, pair < int, int > > p = minimax(board, 'o');

    int x = p.second.first;
    int y = p.second.second;

    board[x][y] = 'o'; 
    return;
}

int main(){

    char board[3][3] = {
        ' ', ' ', ' ', 
        ' ', ' ', ' ',
        ' ', ' ', ' '
    };

    cout << "Welcome to Tic-Tac-Toe!\n";
    drawBoard(board);

    int res;

    while(1){
        
        getPlayerMove(board);
        drawBoard(board);

        if(checkForWin(board, 'x')){
            res = 1;
            break;
        }

        if(checkForDraw(board)){
            res = 0;
            break;
        }

        getOpponentMove(board);
        drawBoard(board);

        if(checkForWin(board, 'o')){
            res = -1;
            break;
        }

        if(checkForDraw(board)){
            res = 0;
            break;
        }

    }

    if(res == 1){
        cout << "Yaaay! you've won\n";
    }
    else if(res == -1){
        cout << "Oh Nooo! You've lost\n";
    }
    else{
        cout << "It's a draw!";
    }

    return 0;
}