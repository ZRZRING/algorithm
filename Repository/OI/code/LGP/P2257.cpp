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
const long long N = 1e7 + 10;
inline int read() {
    int sym = 0, res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}
int n, m, flag[N], prime[N], cnt, g[N], mu[N];
long long ans;
void init() {
    mu[1] = 1;
    for (int i = 2; i <= N; i++) {
        if (!flag[i]) {
            prime[++cnt] = i; mu[i] = -1;
        }
        for (int j = 1; j <= cnt && i * prime[j] <= N; j++) {
            flag[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                mu[i * prime[j]] = 0; break;
            } mu[i * prime[j]] = -mu[i];
        }
    }
    for (int i = 1; i <= cnt; i++) {
        for (int j = 1; j * prime[i] <= N; j++) {
            g[j * prime[i]] += mu[j];
        }
    }
    for (int i = 2; i <= N; i++) g[i] += g[i - 1];
}
int main() {
    int T = read(); init();
    while (T--) {
        n = read(); m = read(); ans = 0;
        for (int l = 1, r; l <= min(n, m); l = r + 1) {
            r = min(n / (n / l), m / (m / l));
            ans += 1ll * (g[r] - g[l - 1]) * (n / l) * (m / l);
        }
        printf("%lld\n", ans);
    }
    return 0;
}