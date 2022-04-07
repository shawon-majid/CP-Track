//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;


int n;

vector <pair <double, double> > p;

bool ok(double x){

    vector <double> points(n);

    double mn = 1e11;
    for(int i = 0; i < n; i++){
        double left = p[i].first - x*p[i].second;
        double right = p[i].first + x*p[i].second;
        mn = min(mn, right);
        points[i] = left;
    }

    for(int i = 0; i < n; i++){
        //debug(points[i]);
        if(mn < points[i]) return false;
    }

    return true; 
}


int main(){
  
    cin >> n;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        p.push_back({(double)x, (double)0});    
    }

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        p[i].second = (double)x;
    }

    double high = 1e11;
    double low = 0;

    int iteration = 0;
    
    while(iteration <= 100){
        double mid = (low+high)/2;
        if(ok(mid)){
            high = mid;
        }
        else{
            low = mid;
        }
        iteration++;
    } 

    cout << fixed << setprecision(12);
    cout << high << endl;

    return 0;
}