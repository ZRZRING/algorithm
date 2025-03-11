#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>

#define file(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout);
#define dbg(x) cerr<<"In Line"<<__LINE__<<" the "<<#x<<" = "<<x<<'\n';
#define abs(x) ((x) < 0 ? -(x) : (x))

using namespace std;

const int N = 210, mod = 998244353;

inline int read() {
	bool sym = 0; int res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

int n, m, k, a[N][N], A[N][N], B[N][N];

int qpow(int a, int x) {
	int res = 1;
	while (x) {if (x & 1) res = 1ll * res * a % mod; a = 1ll * a * a % mod; x >>= 1;}
	return res;
}

int gauss() {
	int res = 0, t = 1;
	for (int k = 1; k <= n; k++) {
		int r = 0;
		for (int i = t; i <= n; i++) if (a[i][k] == 1) {r = i; break;}
		if (!r) {res++; continue;}
		for (int i = 1; i <= n; i++) swap(a[r][i], a[t][i]); t++;
		for (int i = t; i <= n; i++) if (a[i][k]) for (int j = k; j <= n; j++) a[i][j] ^= a[t - 1][j];
		// printf("\n"); for (int i = 1; i <= n; i++) {for (int j = 1; j <= n; j++) printf("%d ", a[i][j]); printf("\n");}
	}
	return res;
}

// 高斯消元，异或，自由元

int main() {
	n = read();
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) A[i][j] = read();
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) B[i][j] = read();
	int ans = 0;
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) a[i][j] = A[i][j];
		for (int i = 1; i <= n; i++) a[i][i] ^= B[i][k];
		// printf("%d\n", ans); for (int i = 1; i <= n; i++) {for (int j = 1; j <= n; j++) printf("%d ", a[i][j]); printf("\n");}
        ans += gauss();
	}
	printf("%d", qpow(2, ans));
	return 0;
}