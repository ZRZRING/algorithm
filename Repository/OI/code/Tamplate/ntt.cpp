#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define lrz 998244353
using namespace std;
void file() {
    freopen("read.in", "r", stdin);
    freopen("write.out", "w", stdout);
}
const int N = 4e6 + 10;
inline int read() {
    int sym = 0, res = 0;char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}
int n, m, a[N], b[N], maxn = 1, len, rev[N];
int power(int a, int x) {
    int res = 1;
    while (x) {
        if (x & 1) res = 1ll * res * a % lrz;
        a = 1ll * a * a % lrz; x >>= 1;
    }
    return res;
}
void ntt(int *a, int opt) {
    for (int i = 0; i < maxn; i++) {
        if (i < rev[i]) swap(a[i], a[rev[i]]);
    }
    for (int i = 1; i < maxn; i <<= 1) {
        int G;
        if (opt == 1) G = power(3, (lrz - 1) / (i << 1));
        if (opt == -1) G = power(power(3, lrz - 2), (lrz - 1) / (i << 1));
        for (int j = 0; j < maxn; j += i << 1) {
            int g = 1;
            for (int k = j; k < i + j; k++) {
                int x = a[k], t = 1ll * g * a[i + k] % lrz;
                a[k] = (x + t) % lrz;
                a[i + k] = ((x - t) % lrz + lrz) % lrz;
                g = 1ll * g * G % lrz;
            }
        }
    }
}
int main() {
    n = read(); m = read();
    for (int i = 0; i <= n; i++) a[i] = read();
    for (int i = 0; i <= m; i++) b[i] = read();
    while (maxn <= n + m) maxn <<= 1, len++;
    for (int i = 0; i <= maxn; i++) {
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << len - 1);
    }
    ntt(a, 1); ntt(b, 1);
    for (int i = 0; i < maxn; i++) a[i] = 1ll * a[i] * b[i] % lrz;
    ntt(a, -1); int inv = power(maxn, lrz - 2);
    for (int i = 0; i <= n + m; i++) printf("%d ", 1ll * a[i] * inv % lrz);
    return 0;
}