> 给定A，B，C三个排列，从每个排列中选一个数$x,y,z$，最小化$(x - y)^2 + (y - z)^2 + (x - z)^2$

将A，B，C分别排序，枚举第一个数，第二个数肯定是最接近第一个数的数，第三个数为了贡献最小，要最接近前两个数的平均值，于是从A中枚举第一个数，大力分类讨论即可

```cpp
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1e6 + 10, M = 2e6 + 10, inf = 0x3f3f3f3f;

const long long Linf = 0x3f3f3f3f3f3f3f3f;

inline int read() {
    bool sym = 0; int res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}

int n, m, cnt, ta, tb, tc, pa, pb, pc, a[N], b[N], c[N], na, nb, nc;

long long t, ans;

long long calc(int a, int b, int c) {
    return 1ll * (a - b) * (a - b) + 1ll * (b - c) * (b - c) + 1ll * (c - a) * (c - a);
}

int find(int t, int a[], int n) {
    int tmp = lower_bound(a + 1, a + 1 + n, t) - a; return tmp > n ? n : tmp;
}

int main() {
    int T = read();
    while (T--) {
        int na = read(), nb = read(), nc = read(); ans = Linf;
        for (int i = 1; i <= na; i++) a[i] = read();
        for (int i = 1; i <= nb; i++) b[i] = read();
        for (int i = 1; i <= nc; i++) c[i] = read();
        sort(a + 1, a + na + 1); sort(b + 1, b + nb + 1); sort(c + 1, c + nc + 1);
        for (int pa = 1; pa <= na; pa++) {
            ta = a[pa];
            pb = find(ta, b, nb); tb = b[pb]; t = 1ll * ta + 1ll * tb >> 1ll;
            pc = find(t, c, nc); tc = c[pc]; t = calc(ta, tb, tc); ans = min(ans, t);
            if (pc > 1) {
                pc--; tc = c[pc]; t = calc(ta, tb, tc); ans = min(ans, t);
            }
            if (pb > 1) {
                pb--; tb = b[pb]; t = ta + tb >> 1; pc = find(t, c, nc); tc = c[pc];
                t = calc(ta, tb, tc); ans = min(ans, t);
                if (pc > 1) {
                    pc--; tc = c[pc]; t = calc(ta, tb, tc); ans = min(ans, t);
                }
            }
            pc = find(ta, c, nc); tc = c[pc]; t = 1ll * ta + 1ll * tc >> 1ll;
            pb = find(t, b, nb); tb = b[pb]; t = calc(ta, tb, tc); ans = min(ans, t);
            if (pb > 1) {
                pb--; tb = b[pb]; t = calc(ta, tb, tc); ans = min(ans, t);
            }
            if (pc > 1) {
                pc--; tc = c[pc]; t = ta + tc >> 1; pb = find(t, b, nb); tb = b[pb];
                t = calc(ta, tb, tc); ans = min(ans, t);
                if (pb > 1) {
                    pb--; tb = b[pb]; t = calc(ta, tb, tc); ans = min(ans, t);
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
```