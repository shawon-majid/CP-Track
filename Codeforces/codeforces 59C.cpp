//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;

int correspondingIndex(int i, int n){
    int firstIndex = 0, lastIndex = n-1;
    if(n % 2 == 0){
        if(i < n/2){ // in the first half
            return (lastIndex - (i - firstIndex));
        }
        else{ // in the second half
            return (firstIndex + (lastIndex - i));
        }
    }   
    else{
        if(i == n/2){ // middle
            return i;
        }
        else if(i < n/2){ // first half
            return (lastIndex - (i - firstIndex));
        }
        else{ // second half
            return (firstIndex + (lastIndex - i));
        }
    }
}

bool isPossible(string str){
    int i = 0, j = str.size()-1;

    while(i <= j){
        if(str[i] != '?' and str[j] != '?' and str[i] != str[j]){
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}
int used[27];

int main(){

    int n;
    cin >> n;
    

    string str;
    cin >> str;

    if(!isPossible(str)){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        // find ? then look for corresponding index and change it accordingly, if corresponding index is also ? then replace with a unused letter
        // but you also have to use all the letters
        // and also make it lexicographically smaller
        deque <int> unused;
        int q = 0;
        for(int i = 0; i < str.size(); i++){
            if(str[i] != '?')used[str[i] - 96] = 1;
            else q++;
        }
        for(int i = 1; i <= n; i++){
            if(!used[i]){
                unused.push_back(i);
            }
        }
        int corInd;

        for(int i = 0; i < str.size(); i++){
            if(str[i] == '?'){
                corInd = correspondingIndex(i, str.size());
                char c = str[corInd]; 
                if(c != '?'){
                    str[i] = c;
                    q--;
                }
            }
        }
        //debug(q);
        int numberOfUnused = unused.size();
        for(int i = 0; i < str.size(); i++){
            if(str[i] == '?'){
                if(q <= numberOfUnused*2){
                    if(unused.size()){
                        int ind = unused.front();
                        char x = ind + 96;
                        str[i] = x;
                        corInd = correspondingIndex(i, str.size());
                        str[corInd] = x;
                        unused.pop_front();
                        used[ind] = 1;
                    }
                }
                else{
                    str[i] = 'a';
                    corInd = correspondingIndex(i, str.size());
                    str[corInd] = 'a';
                }
                q-=2;
            }
        }

        bool ok = 1;
        for(int i = 1; i <= n; i++){
            if(!used[i]){
                ok = 0;
                break;
            }
        }
        
        if(isPossible(str) and ok){
            cout << str << endl;
        }
        else cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}