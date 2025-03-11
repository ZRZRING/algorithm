#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>

#define ls x << 1
#define rs x << 1 | 1

using namespace std;

const int N = 4e6 + 10, M = 2e6 + 10, inf = 0x3f3f3f3f, mod = 998244353;

const long long Linf = 0x3f3f3f3f3f3f3f3f;

inline int read() {
	bool sym = 0; int res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

struct TREE {
	long long b, w, len, _b, _w, b_, w_, ans;
} tr[N];

int n, m, cnt, dat[N];

char ch[N];

int qpow(int a, int x) {
	int res = 1;
	while (x) {if (x & 1) res = 1ll * res * a % mod; a = 1ll * a * a % mod; x >>= 1;}
	return res;
}

int inv(int x) {if (x) return qpow(x, mod - 2); return 1;}

TREE merge(TREE x, TREE y) {
	return (TREE) {
		x.b + y.b, x.w + y.w, x.len + y.len + 1,
		(x._b + y._b + (x.len + 1) * y.b) % mod,
		(x._w + y._w + (x.len + 1) * y.w) % mod,
		(x.b_ + y.b_ + (y.len + 1) * x.b) % mod,
		(x.w_ + y.w_ + (y.len + 1) * x.w) % mod,
		(x.ans + y.ans + x.b * y._w+ x.w * y._b + x.b_ * y.w + x.w_ * y.b + x.w * y.b + x.b * y.w) % mod
	};
}

void build(int x, int l, int r) {
	if (l == r) {
		tr[x] = (TREE){!dat[l], dat[l], 0, 0, 0, 0, 0, 0}; return;
	}
	int mid = l + r >> 1; build(ls, l, mid); build(rs, mid + 1, r);
	tr[x] = merge(tr[ls], tr[rs]);
}

TREE query(int x, int l, int r, int L, int R) {
	if (L <= l && r <= R) {return tr[x];} int mid = l + r >> 1;
	if (mid >= R) return query(ls, l, mid, L, R);
	if (mid + 1 <= L) return query(rs, mid + 1, r, L, R);
	return merge(query(ls, l, mid, L, R), query(rs, mid + 1, r, L, R));
}

int main() {
	n = read(); m = read(); scanf("%s", ch + 1);
	for (int i = 1; i <= n; i++) dat[i] = ch[i] - '0'; build(1, 1, n);
	for (int i = 1; i <= m; i++) {
		int l = read(), r = read();
		printf("%lld\n", query(1, 1, n, l, r).ans);
	}
	return 0;
}