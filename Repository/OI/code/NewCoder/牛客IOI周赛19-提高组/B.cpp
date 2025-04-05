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

const int N = 1e6 + 10, M = 2e6 + 10;

const long long inf = 1e18;

inline long long read() {
    bool sym = 0; long long res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}

int n, m;

long long a[N], sum, ans1 = -inf, ans2 = -inf, pre[N], suf[N], flag;

long long calc() {
    long long ans = -inf; pre[0] = suf[n + 1] = -inf;
    for (int i = 1; i <= n; i++) pre[i] = max(pre[i - 1] + a[i], a[i]);
    for (int i = 1; i <= n; i++) pre[i] = max(pre[i], pre[i - 1]);
    for (int i = n; i >= 1; i--) suf[i] = max(suf[i + 1] + a[i], a[i]);
    for (int i = n; i >= 1; i--) suf[i] = max(suf[i], suf[i + 1]);
    for (int i = 1; i < n; i++) ans = max(ans, pre[i] + suf[i + 1]);
    return ans;
}

int main() {
    n = read();
    for (int i = 1; i <= n; i++) a[i] = read(), sum += a[i], flag |= (a[i] > 0);
    if (!flag) {
        for (int i = 1; i <= n; i++) ans1 = max(ans1, a[i]); printf("%lld\n", ans1); return 0;
    }
    ans1 = calc(); for (int i = 1; i <= n; i++) a[i] = -a[i]; ans2 = calc();
    if (!ans2) ans2 = -inf; printf("%lld", max(ans1, sum + ans2));
    return 0;
}