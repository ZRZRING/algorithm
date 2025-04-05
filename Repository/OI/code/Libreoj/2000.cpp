#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define inf 1e9
using namespace std;
void file() {
    freopen("read.in", "r", stdin);
    freopen("write.out", "w", stdout);
}
const int N = 1e6 + 10, dsq = 1e9 + 7;
inline int read() {
    int sym = 0, res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}
int n, m, T, cnt, mu[N], flag[N], prime[N], invg[N], g[N], invf[N], f[N];
long long qpow(long long a, long long x) {
    long long res = 1;
    while (x) {if (x & 1) res = res * a % dsq; a = a * a % dsq; x >>= 1;}
    return res;
}
void init() {
    mu[1] = 1;
    for (int i = 2; i <= N - 10; i++) {
        if (!flag[i]) {
            prime[++cnt] = i; mu[i] = -1;
        }
        for (int j = 1; j <= cnt && i * prime[j] <= N - 10; j++) {
            flag[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                mu[i * prime[j]] = 0; break;
            }
            mu[i * prime[j]] = -mu[i];
        }
    }
    f[1] = invf[1] = 1;
    for (int i = 2; i <= N - 10; i++) f[i] = (f[i - 1] + f[i - 2]) % dsq, invf[i] = qpow(f[i], dsq - 2);
    for (int i = 0; i <= N - 10; i++) g[i] = 1, invg[i] = 1;
    for (int i = 2; i <= N - 10; i++) {
        for (int j = i, k = 1; j <= N - 10; j += i, k++) {
            if (mu[k] == 1) {
                g[j] = 1ll * g[j] * f[i] % dsq;
                invg[j] = 1ll * invg[j] * invf[i] % dsq;
            }
            if (mu[k] == -1) {
                g[j] = 1ll * g[j] * invf[i] % dsq;
                invg[j] = 1ll * invg[j] * f[i] % dsq;
            }
        }
    }
    for (int i = 2; i <= N - 10; i++) {
        g[i] = 1ll * g[i] * g[i - 1] % dsq;
        invg[i] = 1ll * invg[i] * invg[i - 1] % dsq;
    }
}
long long solve(int n, int m) {
    long long ans = 1;
    for (int l = 1, r; l <= n; l = r + 1) {
        r = min(n / (n / l), m / (m / l));
        ans = ans * qpow(1ll * g[r] * invg[l - 1] % dsq, 1ll * (n / l) * (m / l) % (dsq - 1)) % dsq;
    }
    return ans;
}
int main() {
    T = read(); init();
    while (T--) {
        n = read(); m = read(); if (n > m) swap(n, m); printf("%lld\n", solve(n, m));
    }
    return 0;
}