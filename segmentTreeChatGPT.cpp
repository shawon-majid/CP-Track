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

template<typename T>
class SegmentTree {
private:
    int n;
    vector<T> tree;
    vector<T> lazy;

    void build(int node, int start, int end, const vector<T>& a) {
        if (start == end) {
            tree[node] = a[start];
            return;
        }

        int mid = (start + end) / 2;
        build(2 * node, start, mid, a);
        build(2 * node + 1, mid + 1, end, a);

        tree[node] = min(tree[2 * node] , tree[2 * node + 1]);
    }

    void update_lazy(int node, int start, int end) {
        if (lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void update(int node, int start, int end, int l, int r, T val) {
        update_lazy(node, start, end);
        if (start > r || end < l) {
            return;
        }
        if (start >= l && end <= r) {
            tree[node] += (end - start + 1) * val;
            if (start != end) {
                lazy[2 * node] += val;
                lazy[2 * node + 1] += val;
            }
            return;
        }

        int mid = (start + end) / 2;
        update(2 * node, start, mid, l, r, val);
        update(2 * node + 1, mid + 1, end, l, r, val);

        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    T query(int node, int start, int end, int l, int r) {
        update_lazy(node, start, end);
        if (start > r || end < l) {
            return INT_MAX;
        }
        if (start >= l && end <= r) {
            return tree[node];
        }

        int mid = (start + end) / 2;
        T left_sum = query(2 * node, start, mid, l, r);
        T right_sum = query(2 * node + 1, mid + 1, end, l, r);

        return min(left_sum , right_sum);
    }

public:
    SegmentTree(int _n) {
        n = _n;
        tree.resize(4 * n);
        lazy.resize(4 * n);
    }

    void build(const vector<T>& a) {
        build(1, 0, n - 1, a);
    }

    void update(int l, int r, T val) {
        update(1, 0, n - 1, l, r, val);
    }

    T query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};


int main(){

    int T, cs = 1;
    cin >> T;
    while(T--){
        int n, q;
        cin >> n >> q;

        vector <int> ara(n); 
        for(int i = 0; i < n; i++){
            cin >> ara[i];
        }

        SegmentTree<int> t(n);

        t.build(ara);


        cout << "Case " <<cs++ << ":\n";

        while(q--){
            int x, y;
            cin >> x >> y;
            x--;
            y--;

            cout << t.query(x, y) << "\n";  

        }




    }

    return 0;
}