#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

const int N = 1e6 + 10, M = 2e6 + 10, inf = 0x3f3f3f3f, mod = 998244353;

const long long Linf = 0x3f3f3f3f3f3f3f3f;

inline int read() {
    bool sym = 0;
    int res = 0;
    char ch = getchar();
    while (!isdigit(ch))
        sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch))
        res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}

struct NODE {
    int cnt[2];
    long long dis[2], ans;
} ans[N];

int n, m, cnt, inv[N];

char ch[N];

NODE operator+(const NODE& x, const NODE& y) {
    NODE t;
    t.cnt[0] = x.cnt[0] + y.cnt[0];
    t.dis[0] = x.dis[0] + y.dis[0];
    t.cnt[1] = x.cnt[1] + y.cnt[1];
    t.dis[1] = x.dis[1] + y.dis[1];
    t.ans = (x.ans + y.ans + x.cnt[0] * y.dis[1] - x.dis[0] * y.cnt[1] + x.cnt[1] * y.dis[0] - x.dis[1] * y.cnt[0]) % mod;
    return t;
}

NODE operator-(const NODE& x, const NODE& y) {
    NODE t;
    t.cnt[0] = x.cnt[0] - y.cnt[0];
    t.dis[0] = x.dis[0] - y.dis[0];
    t.cnt[1] = x.cnt[1] - y.cnt[1];
    t.dis[1] = x.dis[1] - y.dis[1];
    t.ans = (x.ans - y.ans + t.cnt[0] * x.dis[1] - t.dis[0] * x.cnt[1] + t.cnt[1] * x.dis[0] - t.dis[1] * x.cnt[0]) % mod;
    return t;
}

NODE make(int x, int c) {
    NODE t;
    t.cnt[c] = 1;
    t.dis[c] = x;
    t.cnt[c ^ 1] = 0;
    t.dis[c ^ 1] = 0;
    t.ans = 0;
    return t;
}

int main() {
    n = read();
    m = read();
    scanf("%s", ch + 1);
    for (int i = 1; i <= n; i++)
        ans[i] = ans[i - 1] + make(i, ch[i] - '0');
    for (int i = 1; i <= m; i++) {
        int l = read(), r = read();
        printf("%d\n", ((ans[r] - ans[l - 1]).ans % mod + mod) % mod);
    }
    return 0;
}