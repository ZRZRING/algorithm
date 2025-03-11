#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>

#define ls (x << 1)
#define rs (x << 1 | 1)
#define len (r - l + 1)

using namespace std;

const int N = 2e6 + 10;

int read() {
	int res = 0; bool sym = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

struct TREE {
	int l, r, ans, zero, one;
} tr[N];

int n, m, dat[N];

string st;

TREE merge(TREE a, TREE b, int l, int r) {
	TREE c;
	if (a.zero && b.zero) c = (TREE){len, len, 0, 1, 0};
	else if (a.zero) c = (TREE){a.r + a.l, b.r, 0, 0, 0};
	if (b.zero) c = (TREE){a.l, a.r + b.l, 0, 0, 0};
	c.l = a.l; c.r = b.r;
	c.ans = (a.r + b.l) / 3 + a.ans + b.ans;
	return c;
}

void build(int x, int l, int r) {
	if (l == r) {
		if (dat[l]) tr[x].l = -2, tr[x].r = -2, tr[x].one = 1;
		else tr[x].l = 2, tr[x].r = 2, tr[x].zero = 1;
		return;
	}
	int mid = l + r >> 1;
	build (ls, l, mid); build(rs, mid + 1, r);
	tr[x] = merge(tr[ls], tr[rs], l, r);
}

TREE query(int x, int l ,int r, int L, int R) {
	if (L <= l && r <= R) return tr[x];
	int mid = l + r >> 1;
	if (mid >= R) return query(ls, l, mid, L, R);
	if (mid + 1 <= L) return query(rs, mid + 1, r, L, R);
	return merge(query(ls, l, mid, L, R), query(rs, mid + 1, r, L, R), l, r);
}

int main() {
	n = read(); m = read(); cin >> st;
	for (int i = 0; i < n; i++) dat[i + 1] = st[i] - '0';
	build(1, 1, n);
	for (int i = 1; i <= n; i++) {
		int l = read(), r = read(); TREE ans = query(1, 1, n, l, r);
		printf("%d\n", ans.ans + max(0, (ans.l + ans.r + 2) / 3));
	}
}