#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>

#define file(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout);
#define dbg(x) cerr<<"In Line"<<__LINE__<<" the "<<#x<<" = "<<x<<'\n';

using namespace std;

const int N = 2e6 + 10, mod = 998244353;

inline int read() {
	bool sym = 0; int res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

int n, m, a[N], pre[N], prex[N];

map<int,int> vis;

long long ans = 0;

void work() {
	int cnt = 0; ans = 0;
	for (int i = 1; i <= n; i++) {
		a[i] = read();
		if (a[i] == 0) {
			ans += 1ll * cnt * (cnt + 1) >> 1; cnt = 0;
		} else cnt++;
	}
	if (cnt) ans += 1ll * cnt * (cnt + 1) >> 1;
	printf("%lld", (1ll * n * (n + 1) >> 1) - ans);
}

int main() {
	// file("std");
	n = read(); int x = read(); pre[0] = 1;
	if (x == 0) {work(); return 0;}
	for (int i = 1; i <= n; i++) {
		a[i] = read();
		if (a[i] == 0) {pre[i] = 1; continue;}
		pre[i] = 1ll * pre[i - 1] * a[i] % mod;
		prex[i] = 1ll * pre[i] * x % mod;
	}
	vis[x] = 1;
	// for (int i = 1; i <= n; i++) printf("%d ", pre[i]); printf("\n");
	// for (int i = 1; i <= n; i++) printf("%d ", prex[i]); printf("\n");
	for (int i = 1; i <= n; i++) {
		if (a[i] == 0) {vis.clear(); vis[x] = 1; continue;}
		vis[prex[i - 1]]++; ans += vis[pre[i]];
	}
	printf("%lld", ans);
	return 0;
}