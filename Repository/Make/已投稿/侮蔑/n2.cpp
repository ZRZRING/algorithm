#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>

#define file(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout);

using namespace std;

const int N = 2e6 + 10, mod = 998244353;

inline int read() {
	bool sym = 0; int res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

int n, m, c[N], k[N], mul[N], inv[N], C[N], ans;

void MOD(int &x) {while (x >= mod) x -= mod; while (x < 0) x += mod;}

int power(int a, int x) {
	int res = 1;
	while (x) {if (x & 1) res = 1ll * res * a % mod; a = 1ll * a * a % mod; x >>= 1;}
	return res;
}

int main() {
	n = read();
	for (int i = 1; i <= n; i++) c[i] = read();
	for (int i = 1; i <= n; i++) k[i] = k[i + n] = k[i + 2 * n] = read();
	mul[0] = 1; C[1] = n; inv[1] = 1;
	for (int i = 1; i <= n; i++) mul[i] = 1ll * mul[i - 1] * i % mod;
	for (int i = 2; i <= n; i++) inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
	for (int i = 2; i <= n; i++) C[i] = 1ll * C[i - 1] * (n - i + 1) % mod * inv[i] % mod;
	for (int i = 1; i <= n; i++) {
		int res = 1ll * mul[n] * (1 << n) % mod, pre = 1, suf = 1;
		for (int j = 1; j <= n - 1; j++) {
			pre = 1ll * pre * k[n + i + j] % mod; suf = 1ll * suf * k[n + i - j] % mod;
			MOD(res += 1ll * C[j + 1] * mul[n - j - 1] % mod * (1 << n - j) % mod * (pre + suf) % mod);
		}
		MOD(ans += 1ll * res * c[i] % mod);
	}
	printf("%d", ans);
	return 0;
}