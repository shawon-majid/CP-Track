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



ll egcd(ll a, ll b, ll &x, ll &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = egcd(b, a%b, x1, y1);
    x = y1;
    y = x1 - y1*(a/b);
    return d;

}



/** Works for non-coprime moduli.
 Returns {-1,-1} if solution does not exist or input is invalid.
 Otherwise, returns {x,L}, where x is the solution unique to mod L
*/
pair<ll, ll> chinese_remainder_theorem( vector<ll> A, vector<ll> M ) {
    if(A.size() != M.size()) return {-1,-1}; /** Invalid input*/
 
    ll n = A.size();
 
    ll a1 = A[0];
    ll m1 = M[0];
    /** Initially x = a_0 (mod m_0)*/
 
    /** Merge the solution with remaining equations */
    for ( ll i = 1; i < n; i++ ) {
        ll a2 = A[i];
        ll m2 = M[i];
 
        ll g = gcd(m1, m2);
        if ( a1 % g != a2 % g ) return {-1,-1}; /** No solution exists*/
 
        /** Merge the two equations*/
        ll p, q;
        egcd(m1/g, m2/g, p, q);
 
        ll lcm = m1 / g * m2; /** LCM of m1 and m2*/
 
        /** We need to be careful about overflow, but I did not bother about overflow here to keep the code simple.*/
        ll x = (a1*(m2/g)*q + a2*(m1/g)*p) % lcm;
 
        /** Merged equation*/
        a1 = x;
        if (a1 < 0) a1 += lcm; /** Result is not suppose to be negative*/
        m1 = lcm;
    }
    return {a1, m1};
}



int main(){


    ll n;
    cin >> n;

    vector < ll > m(n);
    vector < ll > a(n);

    for(ll i = 0; i < n; i++){
        cin >> a[i] >> m[i];
    }

    cout << chinese_remainder_theorem(a, m).first << endl;

    return 0;



    return 0;
}



