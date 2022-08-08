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

bool isSafe(int row, int col, vector <string> grid){
    //all the row before current row has been populated with queens

    // check if any row before this occupies the col
    for(int i = 0; i < row; i++){
        if(grid[i][col] == 'Q'){
            return false;
        }
    }

    // check the upper left diagonal before this row
    for(int r = row, c = col; r >= 0 and c >= 0; r--, c--){
        if(grid[r][c] == 'Q'){
            return false;
        }
    }

    // check the upper right diagonal before this row
    for(int r = row, c = col; r >= 0 and c < 8; r--, c++){
        if(grid[r][c] == 'Q'){
            return false;
        }
    }

    return true;

}

bool isReserved(int row, int col, vector <string> grid){
    if(grid[row][col] == '*') return true;
    else return false;
}


int ways(vector <string> grid, int row){
    
    // base case: all the queens placed successfully
    if(row == 8){
        return 1;
    }

    int ans=0;

    // go through each column
    for(int i = 0; i < 8; i++){
        if(isSafe(row, i, grid) and !isReserved(row, i, grid)){
            grid[row][i] = 'Q';
            ans += ways(grid, row+1);
            grid[row][i] = '.';
        }
    }

    return ans;

}

int main(){

    vector < string > grid;
    for(int i = 0; i < 8; i++){
        string str; 
        cin >> str;
        grid.push_back(str);
    }

    cout << ways(grid, 0) << endl;

    return 0;
}