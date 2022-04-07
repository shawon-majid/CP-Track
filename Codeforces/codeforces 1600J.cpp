//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;

map <int, string> mp;

void init(){
    mp[0] = "0000";
    mp[1] = "0001";
    mp[2] = "0010";
    mp[3] = "0011";
    mp[4] = "0100";
    mp[5] = "0101";
    mp[6] = "0110";
    mp[7] = "0111";
    mp[8] = "1000";
    mp[9] = "1001";
    mp[10] = "1010";
    mp[11] = "1011";
    mp[12] = "1100";
    mp[13] = "1101";
    mp[14] = "1110";
    mp[15] = "1111";
}

int vis[1005][1005];
int grid[1005][1005];

int n, m;


bool checkBounds(int x, int y){
    return (x >= 0 and x < n and y >= 0 and y < m);
}

int dfs(pair <int, int> source){
    vis[source.first][source.second] = 1;
    int cnt = 1;
    string border = mp[grid[source.first][source.second]];

    for(int i = 0; i < 4; i++){ // i-> 0 means up, 1 right, 2 down, 3 left
        int ni, nj;
        if(border[i] == '0'){
            if(i == 0){
                ni = source.first - 1;
                nj = source.second;
            }
            else if(i == 1){
                ni = source.first;
                nj = source.second+1;
            }
            else if(i == 2){
                ni = source.first+1;
                nj = source.second;
            }
            else if(i == 3){
                ni = source.first;
                nj = source.second-1;
            }    

            if(checkBounds(ni, nj) and !vis[ni][nj]){
                cnt += dfs({ni, nj});
            }
        }
        
    }

    return cnt;

}


int main(){

    init();
    
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }

    vector <int> ans;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!vis[i][j]){
                ans.push_back(dfs({i, j}));
            }
        }
    }

    sort(all(ans), greater <int> ());

    for(auto x: ans){
        cout << x << " ";
    }
    cout << endl;


    return 0;
}