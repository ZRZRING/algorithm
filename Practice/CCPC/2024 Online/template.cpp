#include <bits/stdc++.h>

using int64 = long long;

const int64 mod = 998244353;

template<class T>
T MOD(T &x) {
	return (x = (x % mod + mod) % mod);
}

template<class T>
T MOD(T &&x) {
	return (x = (x % mod + mod) % mod);
}

int64 qpow(int64 a, int64 x) {
	a %= mod;
	x %= mod - 1;
	int64 res = 1;
	while (x) {
		if (x & 1) {
			res = res * a % mod;
		}
		a = a * a % mod;
		x >>= 1;
	}
	return res;
}

struct SEG {
	#define ls x << 1
	#define rs x << 1 | 1

	int n;
	std::vector<int64> a, sum, tag;

	void build(int x, int l, int r) {
		if (l == r) {
			sum[x] = a[l];
			return;
		}
		int mid = l + r >> 1;
		build(ls, l, mid);
		build(rs, mid + 1, r);
		sum[x] = sum[ls] + sum[rs];
	}
	
	SEG(std::vector<int64> a) : a(a), n(a.size() - 1) {
		sum.resize(n + 1);
		build(1, 1, n);
	}

	void pushdown(int x, int l, int r, int mid) {
		sum[x] += tag[x];
	}

	void modify(int x, int l, int r, int L, int R, int t) {
		if (L <= l && r <= R) {
			tag[x] += t;
			sum[x] += t * (r - l + 1);
			return;
		}
		int mid = l + r >> 1;
		pushdown(x, l, r, mid);
		if (mid >= L) modify(ls, l, mid, L, R, t);
		if (mid + 1 <= R) modify(rs, mid + 1, r, L, R, t);
		sum[x] = sum[ls] + sum[rs];
	}

	int64 query(int x, int l, int r, int L, int R, int t) {
		if (L <= l && r <= R) {
			return sum[x];
		}
		int mid = l + r >> 1;
		pushdown(x, l, r, mid);
		if (L <= mid && mid + 1 <= R) {
			return query(ls, l, mid, L, R, t) + query(rs, mid + 1, r, L, R, t);
		} else if (mid >= L) {
			return query(ls, l, mid, L, R, t);
		} else if (mid + 1 <= R) {
			return query(rs, mid + 1, r, L, R, t);
		}
	}
};

int main() {

}