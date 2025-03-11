#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 2e6 + 10, mod = 998244353;

int read() {
	int res = 0; bool sym = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

int n, q, l[N], r[N];

char ch[N];

struct DAT {
	int i, c, p, ic, cp, pc, icp, cpc, icpc;
} dat[N];

DAT operator +(const DAT &a, const DAT &b) {
	DAT c;
	c.i = a.i + b.i; c.c = a.c + b.c; c.p = a.p + b.p;
	c.ic = (a.ic + b.ic + 1ll * a.i * b.c) % mod;
	c.cp = (a.cp + b.cp + 1ll * a.c * b.p) % mod;
	c.pc = (a.pc + b.pc + 1ll * a.p * b.c) % mod;
	c.icp = (a.icp + b.icp + 1ll * a.i * b.cp + 1ll * a.ic * b.p) % mod;
	c.cpc = (a.cpc + b.cpc + 1ll * a.c * b.pc + 1ll * a.cp * b.c) % mod;
	c.icpc = (a.icpc + b.icpc + 1ll * a.i * b.cpc + 1ll * a.ic * b.pc + 1ll * a.icp * b.c) % mod;
	return c;
}

DAT operator -(const DAT &a, const DAT &b) {
	DAT c;
	c.i = a.i - b.i; c.c = a.c - b.c; c.p = a.p - b.p;
	c.ic = ((a.ic - b.ic - 1ll * b.i * c.c % mod) + mod) % mod;
	c.cp = ((a.cp - b.cp - 1ll * b.c * c.p % mod) + mod) % mod;
	c.pc = ((a.pc - b.pc - 1ll * b.p * c.c % mod) + mod) % mod;
	c.icp = ((a.icp - b.icp - 1ll * b.i * c.cp - 1ll * b.ic * c.p) % mod + mod) % mod;
	c.cpc = ((a.cpc - b.cpc - 1ll * b.c * c.pc - 1ll * b.cp * c.c) % mod + mod) % mod;
	c.icpc = ((a.icpc - b.icpc - 1ll * b.i * c.cpc - 1ll * b.ic * c.pc - 1ll * b.icp * c.c) % mod + mod) % mod;
	return c;
}

int main() {
    n = read(); q = read(); scanf("%s", ch + 1);
	int x = read(), a = read(), b = read(), p = read();
	for (int i = 1; i <= q; i++) x = (1ll * a * x + b) % p, l[i] = x % n + 1;
	for (int i = 1; i <= q; i++) x = (1ll * a * x + b) % p, r[i] = x % n + 1;
	// for (int i = 1; i <= q; i++) printf("%d %d\n", l[i], r[i]);
	for (int i = 1; i <= n; i++) dat[i] = (DAT){ch[i] == 'I', ch[i] == 'C', ch[i] == 'P', 0, 0, 0, 0, 0, 0};
	for (int i = 2; i <= n; i++) dat[i] = dat[i - 1] + dat[i];
	// for (int i = 1; i <= n; i++) printf("%d %d %d %d %d %d %d %d %d\n", dat[i]);
	int res = 0;
	for (int i = 1; i <= q; i++) {
		if (l[i] > r[i]) swap(l[i], r[i]);
		// printf("%d %d\n", l[i], r[i]);
		DAT ans = dat[r[i]] - dat[l[i] - 1];
		// printf("%d\n", ans.icpc);
		res = (res + ans.icpc) % mod;
	}
	printf("%d", res);
	return 0;
}