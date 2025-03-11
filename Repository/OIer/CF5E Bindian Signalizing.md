> 给定一个n个点构成的环，每个点有个高度，求点对个数，点对需满足它们相连通的两条路径中没有比它们更高的点

一个单调栈dp调了我一晚上加一中午

首先破环成链，不能单纯加倍，这样有的地方会算两次有的地方会算一次

但是鉴于特殊性质，最高的地方不可逾越，而且环映射到链上时可以循环位移，所以把最高的作为第一个位置，这样中间的位置只能按照序列的顺序去找连通的点，而不用考虑环了

之后就是一个普通的单调栈了，注意细节即可

```cpp
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

int n, m, t[N], h[N], s[N], cnt[N], top;

signed main() {
    n = read(); int mx = 0, pos;
    for (int i = 1; i <= n; i++) {
        t[i] = read(); if (t[i] > mx) {pos = i; mx = t[i];}
    }
    int p = 0, ans = n - 1;
    for (int i = pos + 1; i <= n; i++) h[++p] = t[i];
    for (int i = 1; i < pos; i++) h[++p] = t[i];
    top = 0;
    for (int i = 1; i <= p; i++) {
        while (s[top] < h[i] && top) ans += cnt[top--];
        if (s[top] != h[i]) s[++top] = h[i], cnt[top] = 0; ans += cnt[top]++;
    }
    while (top > 1) ans += cnt[top--]; cout << ans;
    return 0;
}
```

