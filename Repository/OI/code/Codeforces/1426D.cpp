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

const int N = 1e6 + 10, M = 2e6 + 10, inf = 1e9;

inline int read() {
    bool sym = 0; int res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}

int n, m, sum[N], a[N], mp[N];

signed main() {
    n = read() + 1;
    for (int i = 2; i <= n; i++) a[i] = read();
    for (int i = 2; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    for (int i = 1; i <= n; i++) a[i] = sum[i];
    sort(sum + 1, sum + n + 1);
    int siz = unique(sum + 1, sum + n + 1) - sum;
    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(sum + 1, sum + n + 1, a[i]) - sum;
    }
    int mx = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!mx) {if (mp[a[i]]) ans++, mx = i;} else {if (mp[a[i]] >= mx - 1) ans++, mx = i;} mp[a[i]] = i;
    }
    cout << ans;
    return 0;
}