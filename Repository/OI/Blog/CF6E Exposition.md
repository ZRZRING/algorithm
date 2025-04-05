> 求最大的极差不超过k的子串

当时最初想到的是枚举右端点，用单调队列存一个单增和一个单减，每次取队头做差，不行就弹队头

实际上这个做法会被这个数据hack

```txt
4
1 6 4 7
```

最后一个位置时，单增队列为`4 7`，单减队列只有一个`7`，就找不到`6 4 7`这一个子串

上述方法从性质上就是错误的，不能继续修改

一种正确的做法，枚举左端点，更新右端点，因为其满足单调性，随着左端点的推进右端点肯定是只会往右移的，于是我们可以做到线性复杂度

```cpp
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

const int N = 1e6 + 10, M = 2e6 + 10, inf = 1e9;

inline int read() {
    bool sym = 0; int res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}

int n, m, ans, res[N], a[N], h1, t1, h2, t2, q1[N], q2[N];

void ins(int x) {
    while (h1 <= t1 && a[x] >= a[q1[t1]]) t1--;
    q1[++t1] = x;
    while (h2 <= t2 && a[x] <= a[q2[t2]]) t2--;
    q2[++t2] = x;
}

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    int l = 1, r = 0;
    for (l = 1; l <= n; l++) {
        if (r < l) ins(++r);
        if (h1 <= t1 && q1[h1] < l) h1++;
        if (h2 <= t2 && q2[h2] < l) h2++;
        while (r < n && max(a[r + 1], a[q1[h1]]) - min(a[r + 1], a[q2[h2]]) <= m) ins(++r);
        res[l] = r - l + 1; ans = max(ans, res[l]);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) if (res[i] == ans) cnt++;
    printf("%d %d\n", ans, cnt);
    for (int i = 1; i <= n; i++) if (res[i] == ans) printf("%d %d\n", i, i + res[i] - 1);
    return 0;
}
```