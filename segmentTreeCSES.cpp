#include <iostream>
using ll = long long;
using namespace std;

// an array of n values and efficiently process the following types of queries:
// 1. Increase each value in range [a,b] by x.
// 2. Set each value in range [a,b] to x.
// 3. Calculate the sum of values in range [a,b].

const int maxN = 2e5 + 5;

int N, Q;
int a[maxN];

struct node {
	ll val;
	ll lzAdd;
	ll lzSet;
	node(){};
} tree[maxN << 2];

#define lc p << 1
#define rc (p << 1) + 1

inline void pushup(int p) {
	tree[p].val = tree[lc].val + tree[rc].val;
	return;
}

void pushdown(int p, int l, int mid, int r) {
	// lazy: range set
	if (tree[p].lzSet != 0) {
		tree[lc].lzSet = tree[rc].lzSet = tree[p].lzSet;
		tree[lc].val = (mid - l + 1) * tree[p].lzSet;
		tree[rc].val = (r - mid) * tree[p].lzSet;
		tree[lc].lzAdd = tree[rc].lzAdd = 0;
		tree[p].lzSet = 0;
	} else if (tree[p].lzAdd != 0) {  // lazy: range add
		if (tree[lc].lzSet == 0) tree[lc].lzAdd += tree[p].lzAdd;
		else {
			tree[lc].lzSet += tree[p].lzAdd;
			tree[lc].lzAdd = 0;
		}
		if (tree[rc].lzSet == 0) tree[rc].lzAdd += tree[p].lzAdd;
		else {
			tree[rc].lzSet += tree[p].lzAdd;
			tree[rc].lzAdd = 0;
		}
		tree[lc].val += (mid - l + 1) * tree[p].lzAdd;
		tree[rc].val += (r - mid) * tree[p].lzAdd;
		tree[p].lzAdd = 0;
	}
	return;
}

void build(int p, int l, int r) {
	tree[p].lzAdd = tree[p].lzSet = 0;
	if (l == r) {
		tree[p].val = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(lc, l, mid);
	build(rc, mid + 1, r);
	pushup(p);
	return;
}

void add(int p, int l, int r, int a, int b, ll val) {
	if (a > r || b < l) return;
	if (a <= l && r <= b) {
		tree[p].val += (r - l + 1) * val;
		if (tree[p].lzSet == 0) tree[p].lzAdd += val;
		else tree[p].lzSet += val;
		return;
	}
	int mid = (l + r) >> 1;
	pushdown(p, l, mid, r);
	add(lc, l, mid, a, b, val);
	add(rc, mid + 1, r, a, b, val);
	pushup(p);
	return;
}

void set(int p, int l, int r, int a, int b, ll val) {
	if (a > r || b < l) return;
	if (a <= l && r <= b) {
		tree[p].val = (r - l + 1) * val;
		tree[p].lzAdd = 0;
		tree[p].lzSet = val;
		return;
	}
	int mid = (l + r) >> 1;
	pushdown(p, l, mid, r);
	set(lc, l, mid, a, b, val);
	set(rc, mid + 1, r, a, b, val);
	pushup(p);
	return;
}

ll query(int p, int l, int r, int a, int b) {
	if (a > r || b < l) return 0;
	if (a <= l && r <= b) return tree[p].val;
	int mid = (l + r) >> 1;
	pushdown(p, l, mid, r);
	return query(lc, l, mid, a, b) + query(rc, mid + 1, r, a, b);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> Q;
	for (int i = 1; i <= N; ++i) cin >> a[i];
	build(1, 1, N);
	for (int i = 1; i <= Q; ++i) {
		int k;
		cin >> k;
		int a, b, x;
		if (k == 1) {
			cin >> a >> b >> x;
			add(1, 1, N, a, b, x);
		}
		if (k == 2) {
			cin >> a >> b >> x;
			set(1, 1, N, a, b, x);
		}
		if (k == 3) {
			cin >> a >> b;
			ll res = query(1, 1, N, a, b);
			cout << res << '\n';
		}
	}
	return 0;
}