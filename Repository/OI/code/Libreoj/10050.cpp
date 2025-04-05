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
const int N = 3e7 + 10;
inline int read() {
    int sym = 0, res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}
int n, m, bs[N], a[N], son[N][2], ans, tot;
void ins(int t) {
    for (int i = 0; i <= 30; i++) {
        bs[i] = t & 1; t >>= 1;
    }
    int x = 0;
    for (int i = 30; i >= 0; i--) {
        if (!son[x][bs[i]]) son[x][bs[i]] = ++tot; x = son[x][bs[i]];
    }
}
int query(int t) {
    int x = 0, res = 0;
    for (int i = 0; i <= 30; i++) {
        bs[i] = t & 1; t >>= 1;
    }
    for (int i = 30; i >= 0; i--) {
        if (son[x][!bs[i]]) res += 1 << i, x = son[x][!bs[i]];
        else x = son[x][bs[i]];
    }
    return res;
}
int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        a[i] = read(); ins(a[i]);
    }
    for (int i = 1; i <= n; i++) {
        ans = max(ans, query(a[i]));
    }
    printf("%d", ans);
    return 0;
}