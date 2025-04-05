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