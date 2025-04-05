#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define inf 1e9
using namespace std;
void file() {
    freopen("read.in", "r", stdin);
    freopen("write.out", "w", stdout);
}
const int N = 1e6 + 10;
inline int read() {
    int sym = 0, res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}
int n, m = 200, cnt[N], rk[N], id[N], sa[N], rk1[N];
char ch[N];
bool cmp(int x, int y, int w) {
    return rk1[x] == rk1[y] && rk1[x + w] == rk1[y + w];
}
void sort() {
    for (int i = 1; i <= m; i++) cnt[i] = 0;
    for (int i = 1; i <= n; i++) cnt[rk[id[i]]]++;
    for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
    for (int i = n; i >= 1; i--) sa[cnt[rk[id[i]]]--] = id[i];
}
int main() {
    n = read(); int l = 1, r = n;
    for (int i = 1; i <= n; i++) while (!isalpha(ch[i] = getchar()));
    for (int i = 1; i <= n; i++) rk[i] = rk[2 * n + 2 - i] = ch[i];
    n = 2 * n + 1; for (int i = 1; i <= n; i++) id[i] = i;
    sort();
    for (int w = 1, p = 0; w < n; w <<= 1, m = p, p = 0) {
        for (int i = n; i >= n - w + 1; i--) id[++p] = i;
        for (int i = 1; i <= n; i++) if (sa[i] > w) id[++p] = sa[i] - w;
        sort();
        for (int i = 1; i <= n; i++) rk1[i] = rk[i];
        rk[sa[1]] = p = 1;
        for (int i = 2; i <= n; i++) {
            rk[sa[i]] = cmp(sa[i], sa[i - 1], w) ? p : ++p;
        }
        if (p == n) break;
    }
    int tot = 0;
    while (l <= r) {
        putchar(rk[l] < rk[n - r + 1] ? ch[l++] : ch[r--]);
        if (++tot % 80 == 0) puts("");
    }
    return 0;
}