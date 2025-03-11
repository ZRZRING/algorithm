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

int n, m, C[N], c[N], k[N], who[N], to[N], ans, mul[N];

bool vis[N];

int calc(int x) {if (x == 0) x = n; if (x == n + 1) x = 1; return x;}

void MOD(int &x) {while (x >= mod) x -= mod; while (x < 0) x += mod;}

int power(int a, int x) {
	int res = 1;
	while (x) {if (x & 1) res = 1ll * res * a % mod; a = 1ll * a * a % mod; x >>= 1;}
	return res;
}

void calc() {
    int tmp = ans;
    for (int i = 1; i <= n; i++) c[i] = C[i];
    for (int i = 1; i <= n; i++) {
        MOD(ans += c[who[i]]); int t = calc(who[i] + to[i]); MOD(c[t] += 1ll * k[t] * c[who[i]] % mod);
    }
}

void dfs(int x) {
    if (x == n + 1) {calc(); return;}
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue; vis[i] = 1;
        who[x] = i; to[x] = -1; dfs(x + 1); to[x] = 1; dfs(x + 1); vis[i] = 0;
    }
}

int main() {
    n = read();
    for (int i = 1; i <= n; i++) C[i] = read();
    for (int i = 1; i <= n; i++) k[i] = read();
	mul[0] = 1;
	for (int i = 1; i <= n; i++) mul[i] = 1ll * mul[i - 1] * i % mod;
    dfs(1);
	printf("%d", ans);
    return 0;
}