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
const int N = 2e7 + 10, inf = 1e9;
long long dsq = 998244353;
inline int read() {
    bool sym = 0; int res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}
int n, m, siz[N], fa[N];
long long inv[N], ans;
int main() {
    n = read(); siz[1] = 1;
    for (int i = 2; i <= n; i++) fa[i] = read(), siz[i] = 1;
    for (int i = n; i >= 2; i--) siz[fa[i]] += siz[i];
    inv[1] = 1ll;
    for (int i = 2; i <= n; i++) {
        inv[i] = (dsq - dsq / i) * inv[dsq % i] % dsq;
    }
    for (int i = 1; i <= n; i++) ans = ans + inv[siz[i]] > dsq ? ans + inv[siz[i]] - dsq : ans + inv[siz[i]];
    printf("%lld", ans);
    return 0;
}
