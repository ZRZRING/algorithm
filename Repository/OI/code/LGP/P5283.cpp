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
const int N = 2e7 + 10;
inline long long read() {
    long long sym = 0, res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}
int n, m, son[N][2], tot, ntot, rt[N], siz[N], bit[N], num[N];
long long ans, sum[N];
struct node {
    int st, l, r, pos;
    bool operator < (const node &a) const {
        return (sum[pos] ^ sum[st - 1]) < (sum[a.pos] ^ sum[a.st - 1]);
    }
};
priority_queue<node>q;
void ins(int id, long long t) {
    for (int i = 0; i <= 32; i++) {
        bit[i] = t & 1; t >>= 1;
    }
    int x = ++tot, last = rt[ntot]; rt[++ntot] = x;
    for (int i = 32; i >= 0; i--) {
        siz[x] = siz[last] + 1;
        son[x][bit[i]] = ++tot; son[x][!bit[i]] = son[last][!bit[i]];
        x = son[x][bit[i]]; last = son[last][bit[i]];
    }
    siz[x] = siz[last] + 1; num[x] = id;
}
int query(int x, int y, long long t) {
    for (int i = 0; i <= 32; i++) {
        bit[i] = t & 1; t >>= 1;
    }
    for (int i = 32; i >= 0; i--) {
        if (siz[son[y][!bit[i]]] > siz[son[x][!bit[i]]]) {
            x = son[x][!bit[i]]; y = son[y][!bit[i]];
        } else {
            x = son[x][bit[i]]; y = son[y][bit[i]];
        }
    }
    return num[y];
} 
node init(int st, int l, int r) {
    return (node){st, l, r, query(rt[l - 1], rt[r], sum[st - 1])};
}
int main() { //file();
    n = read(); m = read();
    for (int i = 1; i <= n; i++) {
        long long x = read(); sum[i] = sum[i - 1] ^ 1ll * x; ins(i, sum[i]);
    }
    for (int i = 1; i <= n; i++) {
        q.push(init(i, i, n));
    }
    for (int i = 1; i <= m; i++) {
        node x = q.top(); q.pop();
        ans += sum[x.pos] ^ sum[x.st - 1];
        if (x.l < x.pos) q.push(init(x.st, x.l, x.pos - 1));
        if (x.pos < x.r) q.push(init(x.st, x.pos + 1, x.r));
    }
    printf("%lld", ans);
    return 0;
}