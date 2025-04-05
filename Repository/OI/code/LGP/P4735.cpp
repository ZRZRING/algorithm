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
int n, m, bit[N], all;
int tot, ntot, rt[N], siz[N], son[N][2];
void ins(int t) {
    for (int i = 0; i <= 30; i++) {
        bit[i] = t & 1; t >>= 1;
    }
    int x = ++tot, last = rt[ntot]; rt[++ntot] = x;
    for (int i = 30; i >= 0; i--) {
        siz[x] = siz[last] + 1;
        son[x][bit[i]] = ++tot; son[x][!bit[i]] = son[last][!bit[i]];
        x = son[x][bit[i]]; last = son[last][bit[i]];
    }
    siz[x] = siz[last] + 1;
}
int query(int x, int y, int t) {
    int ans = 0;
    for (int i = 0; i <= 30; i++) {
        bit[i] = t & 1; t >>= 1;
    }
    for (int i = 30; i >= 0; i--) {
        if (siz[son[y][!bit[i]]] > siz[son[x][!bit[i]]]) {
            x = son[x][!bit[i]]; y = son[y][!bit[i]]; ans |= 1 << i;
        } else {
            x = son[x][bit[i]]; y = son[y][bit[i]];
        }
    }
    return ans;
}
int main() {
    n = read(); m = read(); ins(0);
    for (int i = 1; i <= n; i++) {
        int x = read(); all ^= x; ins(all);
    }
    for (int i = 1; i <= m; i++) {
        char opt[10]; scanf("%s", opt);
        if (opt[0] == 'A') {
            int x = read(); all ^= x; ins(all);
        }
        if (opt[0] == 'Q') {
            int l = read(), r = read(), x = read();
            printf("%d\n", query(rt[l - 1], rt[r], all ^ x));
        }
    }
    return 0;
}