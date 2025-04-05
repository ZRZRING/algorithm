#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
void file() {
    freopen("std.in", "r", stdin);
    freopen("wa.out", "w", stdout);
}
const int N = 1e6 + 10, inf = 1e9, dsq = 998244353;
inline int read() {
    bool sym = 0; int res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}
int n, m, a[210][2010];
long long ans = 1, sum[N], f[2010][210];
int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            a[i][j] = read(); sum[i] = (sum[i] + a[i][j]) % dsq;
        }
        ans = ans * (sum[i] + 1ll) % dsq;
    }
    ans = (ans - 1ll + dsq) % dsq; long long delta = 0;
    for (int k = 1; k <= m; k++) {
        memset(f, 0, sizeof(f)); f[0][n] = 1ll;
        for (int i = 1; i <= n; i++) {
            for (int j = -i + n; j <= i + n; j++) {
                f[i][j] = 1ll * (f[i - 1][j] + (sum[i] - a[i][k]) * f[i - 1][j + 1] + a[i][k] * f[i - 1][j - 1]) % dsq;
            }
        }
        for (int i = n + 1; i <= n << 1; i++) delta = 1ll * (delta + f[n][i]) % dsq;
    }
    printf("%lld", 1ll * (ans - delta + dsq) % dsq);
    return 0;
}