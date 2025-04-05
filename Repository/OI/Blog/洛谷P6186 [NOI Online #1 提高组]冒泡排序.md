先考虑手玩一下冒泡排序，然后考虑逆序对在上面有什么特殊性质，如果说逆序对通过计算每个位置的贡献的话(每个位置前面有多少数大于它)，会发现一次冒泡排序部分数字往前移了一格，并且那些大的数字往后走了很多个格

每个往前移动的数字，前面一定少了一个且仅一个比它大的，每个往后移动很多格的数字，一定是因为它前面没有比它更大的数字才会去往后走的，记一个数字$i$前面有$b_i$个数大于它，那么可以有一个结论

> 一次冒泡排序，会使得所有$b_i$变为$max(0, b_i - 1)$

因为是排列，所以$b_i$表示每个位置$i$还是每个数字$i$来计算总贡献是等价的，这样操作1就成了修改$b_x$和$b_{x + 1}$的值了，问题转变成

> 单点修改，询问全局所有元素减$k$再对$0$取$max$的和

开个值域树状数组，维护一下每个元素出现次数即可

```cpp
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define lowbit(x) (x & -x)
using namespace std;
void file() {
    freopen("std.in", "r", stdin);
    freopen("wa.out", "w", stdout);
}
const int N = 1e6 + 10, inf = 1e9;
inline int read() {
    bool sym = 0; int res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}
int n, m, a[N], below[N];
struct BIT {
    long long tr[N];
    void clear() {for (int i = 1; i <= n; i++) tr[i] = 0;}
    long long query(int x) {
        if (!x) return 0; long long res = 0; for (; x; x -= lowbit(x)) res += tr[x]; return res;
    }
    void add(int x, int t) {
        if (!x) return; for (; x <= n; x += lowbit(x)) tr[x] += 1ll * t;
    }
} cnt, sum;
int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; i++) {
        a[i] = read(); cnt.add(a[i], 1); below[i] = i - cnt.query(a[i]);
    }
    cnt.clear();
    for (int i = 1; i <= n; i++) cnt.add(below[i], 1), sum.add(below[i], below[i]);
    for (int i = 1; i <= m; i++) {
        int opt = read();
        if (opt == 1) {
            int x = read();
            cnt.add(below[x], -1); sum.add(below[x], -below[x]);
            cnt.add(below[x + 1], -1); sum.add(below[x + 1], -below[x + 1]);
            swap(below[x], below[x + 1]); a[x] > a[x + 1] ? below[x]-- : below[x + 1]++;
            cnt.add(below[x], 1); sum.add(below[x], below[x]);
            cnt.add(below[x + 1], 1); sum.add(below[x + 1], below[x + 1]);
            swap(a[x], a[x + 1]);
        }
        if (opt == 2) {
            int k = read(); if (k >= n) {printf("0\n"); continue;}
            printf("%lld\n", sum.query(n) - sum.query(k) - (cnt.query(n) - cnt.query(k)) * k);
        }
    }
    return 0;
}
```