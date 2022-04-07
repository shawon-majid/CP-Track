//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;

int n, m;

int vis[1005][1005];

bool check(int x, int y, string str[]){
    return (x < n and x >= 0 and y < m and y >= 0 and !vis[x][y] and str[x][y] == '.');
}

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};


void dfs(pair <int, int> source, string str[]){
    vis[source.first][source.second] = 1;

    for(int i = 0; i < 4; i++){
        int ni, nj;
        ni = source.first + dx[i];
        nj = source.second + dy[i];
        if(check(ni, nj, str)){
            vis[ni][nj] = 1;
            dfs({ni, nj}, str);
        }
    }   
}

int numberOfrooms(string str[]){

    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!vis[i][j] and str[i][j] == '.'){
                dfs({i, j}, str);
                cnt++;
            }
        }
    }

    return cnt;

}


int main(){

    
    cin >> n >> m;

    string str[n];

    for(int i = 0; i < n; i++){
        cin >> str[i]; 
    }

    cout << numberOfrooms(str) << endl;



    return 0;
}