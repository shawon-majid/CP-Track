//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;

int n, m;


int freeFall(int r, int c, int gravity, vector < string > str){
    while(str[r][c] == 'C' || str[r][c] == '.' || str[r][c] == 'D'){
        if(str[r][c] == 'D') return r;
        if(str[r+gravity][c] == '#') return r;
        r += gravity;
    }
    return -1;
}

void searchLeftRight(int r, int c, int gravity, int flipCount, vector < vector < int > > &flipCountGrid, vector < string > str, queue < array < int, 4 > > &q){
    
    // base cases

    if(str[r][c] == '-' || r <= 0 || flipCountGrid[r][c] >= 0) return;

    flipCountGrid[r][c] = flipCount;

    q.push({r, c, gravity, flipCount});

    r = freeFall(r, c+1, gravity, str);
    searchLeftRight(r, c+1, gravity, flipCount, flipCountGrid, str, q);

    r = freeFall(r, c-1, gravity, str);
    searchLeftRight(r, c-1, gravity, flipCount, flipCountGrid, str, q);


}

int main(){


    freopen("gravity.in", "r", stdin);
    freopen("gravity.out", "w", stdout);

    
    cin >> n >> m;

    // debug(n);

    vector < string > str(n+2);

    // adding borders
    str[0] = "", str[n] = "";
    for(int i = 0; i < m+2; i++){
        str[0] += '-';
        str[n+1] += '-';
    }

    for(int i = 1; i <= n; i++){
        cin >> str[i];
        str[i] = "-" + str[i] + "-";
    }

    pair < int, int > source, dest;

    for(int i = 0; i < n+2; i++){
        for(int j = 0; j < m+2; j++){
            if(str[i][j] == 'C'){
                source = {i, j};
            }
            else if(str[i][j] == 'D'){
                dest = {i, j};
            }
        }
    }

    int r = source.first;
    int c = source.second;

    int gravity = 1;
    int flipCount = 0;

    queue < array < int, 4 > > q; 

    vector < vector < int > > flipCountGrid(n+2, vector < int > (m+2, -1));

    r = freeFall(r, c, gravity, str);

    searchLeftRight(r, c, gravity, flipCount, flipCountGrid, str, q);

    while(!q.empty()){

        array node = q.front();

        int r = node[0];
        int c = node[1];
        int gravity = node[2];
        int flipCount = node[3];

        q.pop();

        // if(str[r][c] == 'D') break;

        r = freeFall(r, c, -gravity, str);
        searchLeftRight(r, c, -gravity, flipCount+1, flipCountGrid, str, q);
    }  

    r = dest.first;
    c = dest.second;



    cout << flipCountGrid[r][c] << "\n";


    return 0;
}