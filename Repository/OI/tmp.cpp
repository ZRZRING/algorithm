#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>

#define int long long

using namespace std;

void file() {
    freopen("std.in", "r", stdin);
    freopen("wa.out", "w", stdout);
}

const int N = 1e6 + 10, M = 2e6 + 10, inf = 1e14;

inline int read() {
    bool sym = 0; int res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}

int n, m, a[N], sum, ans1, ans2;

struct NODE {
    int pre[N], suf[N];
} mx, mi;

signed main() {
    n = read(); mx.pre[0] = mx.suf[n] = mi.pre[0] = mx.suf[n] = -inf;

    for (int i = 1; i <= n; i++) a[i] = read(), sum += a[i];
    for (int i = 1; i <= n - 1; i++) mx.pre[i] = max(mx.pre[i - 1] + a[i], a[i]);
    for (int i = 1; i <= n - 1; i++) mx.pre[i] = max(mx.pre[i], mx.pre[i - 1]);
    for (int i = n; i >= 2; i--) mx.suf[i] = max(mx.suf[i + 1] + a[i], a[i]);
    for (int i = n; i >= 2; i--) mx.suf[i] = max(mx.suf[i], mx.suf[i + 1]);
    for (int i = 1; i <= n - 1; i++) ans1 = max(ans1, mx.pre[i] + mx.suf[i + 1]);

    for (int i = 1; i <= n; i++) a[i] = -a[i];
    for (int i = 1; i <= n - 1; i++) mi.pre[i] = max(mi.pre[i - 1] + a[i], a[i]);
    for (int i = 1; i <= n - 1; i++) mi.pre[i] = max(mi.pre[i], mi.pre[i - 1]);
    for (int i = n; i >= 2; i--) mi.suf[i] = max(mi.suf[i + 1] + a[i], a[i]);
    for (int i = n; i >= 2; i--) mi.suf[i] = max(mi.suf[i], mi.suf[i + 1]);
    for (int i = 1; i <= n - 1; i++) ans2 = max(ans2, mi.pre[i] + mi.suf[i + 1]);
    
    ans2 = sum + ans2; printf("%lld", max(ans1, ans2));

    return 0;
}