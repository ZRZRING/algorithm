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
const int N = 6e6 + 10;
inline int read() {
    int sym = 0, res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}
int n, m, ls[N], rs[N], val[N], cnt;
long long ans1, ans2, ans;
int add(int l, int r, int goal) {
    int mid = l + r >> 1, node = ++cnt;
    val[node] = 1; if (l == r) return node;
    if (mid >= goal) ls[node] = add(l, mid, goal);
    else rs[node] = add(mid + 1, r, goal);
    return node;
}
int merge(int l, int r, int x, int y) {
    if (!x || !y) return x + y;
    if (l == r) {val[x] += val[y]; return x;}
    int mid = l + r >> 1;
    ans1 += 1ll * val[ls[x]] * val[rs[y]];
    ans2 += 1ll * val[rs[x]] * val[ls[y]];
    ls[x] = merge(l, mid, ls[x], ls[y]);
    rs[x] = merge(mid + 1, r, rs[x], rs[y]);
    val[x] = val[ls[x]] + val[rs[x]];
    return x;
}
int dfs() {
    int x = read(); if (x) return add(1, n, x);
    int node = merge(1, n, dfs(), dfs());
    ans += min(ans1, ans2); ans1 = 0; ans2 = 0; return node;
}
int main() {
    n = read(); dfs(); printf("%lld", ans);
    return 0;
}