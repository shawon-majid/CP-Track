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

/*
    Using backtracking

*/


int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
          //0, 1, 2, 3
    // up, down, left, right

int grid[9][9];
bool vis[9][9];

int path[50];

int goPath(int row, int col, int pathIndex){
    // optimization

    if(vis[row][col-1] == 1 and vis[row][col+1] == 1 and vis[row+1][col] == 0 and vis[row-1][col] == 0){
        return 0;
    }
    if(vis[row-1][col] == 1 and vis[row+1][col] == 1 and vis[row][col+1] == 0 and vis[row][col-1] == 0){
        return 0;
    }


    // base cases

    if(vis[row][col]){
        return 0;
    }


    if(row == 7 and col == 1){
        if(pathIndex == 48){
            return 1;
        }
        return 0;
    }

    if(pathIndex == 48){
        return 0;
    }

    vis[row][col] = 1;

    int ans = 0;

    if(path[pathIndex] < 4){ // already told where to go
        int nextR = row + dy[path[pathIndex]];
        int nextC = col + dx[path[pathIndex]];
        if(!vis[nextR][nextC]){
            ans += goPath(nextR, nextC, pathIndex+1);
        }
    }

    else if(path[pathIndex] == 4){ // ?
        // can go to any direction
        for(int i = 0; i < 4; i++){
            int nextR, nextC;
            nextC = col + dx[i];
            nextR = row + dy[i];
            if(!vis[nextR][nextC]){
                ans += goPath(nextR, nextC, pathIndex+1);
            }
        }
    }
    vis[row][col] = 0;
    return ans;
}



int main(){

    string str;
    cin >> str;


    for(int i = 0;i < str.size(); i++){
        if(str[i] == 'U'){
            path[i] = 0;
        }
        else if(str[i] == 'D'){
            path[i] = 1;
        }
        else if(str[i] == 'L'){
            path[i] = 2;
        }
        else if(str[i] == 'R'){
            path[i] = 3;
        }
        else{ // ?
            path[i] = 4;
        }   
    }

    for(int i = 0; i < 9; i++){
        vis[0][i] = 1;
        vis[i][0] = 1;
        vis[8][i] = 1;
        vis[i][8] = 1;
    }

    for(int i = 1; i <= 7; ++i){
        for(int j = 1; j <= 7; j++){
            vis[i][j] = 0;
        }
    }

    int ans = goPath(1, 1, 0);

    cout << ans << endl;



    return 0;
}