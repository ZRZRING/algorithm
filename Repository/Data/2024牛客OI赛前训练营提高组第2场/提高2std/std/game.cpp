#include <bits/stdc++.h>
using namespace std;

namespace IO {
    const int SIZE = 1 << 20;
    char ibuf[SIZE]; int iS, iT;
    char obuf[SIZE]; int oT;
    inline char gc() {
        if (iS == iT) iS = 0, iT = fread(ibuf, 1, SIZE, stdin);
        return iS == iT ? EOF : ibuf[iS++];
    }
    inline void pc(char c) {
        obuf[oT++] = c;
        if (oT == SIZE) fwrite(obuf, 1, SIZE, stdout), oT = 0;
    }
    inline int read() {
        int x = 0, f = 0;
        char c = gc();
        while (!isdigit(c)) f |= c == '-', c = gc();
        while (isdigit(c)) x = 10 * x + c - '0', c = gc();
        return f ? -x : x;
    }
    inline void print(int64_t x) {
        static char buf[64];
        int len = 0;
        if (x < 0) pc('-'), x = -x;
        do { buf[++len] = x % 10 + '0', x /= 10; } while (x);
        while (len) pc(buf[len--]);
    }
    inline void print(int64_t x, char ch) {
        print(x), pc(ch);
    }
    struct Flusher {
        ~Flusher() {
            if (oT) fwrite(obuf, 1, oT, stdout);
        }
    } flusher;
}

const int N = 2000005;
const int mod = 1e9 + 7;

vector<int> adj[N], G[N];
int ord[N], a[N], pw[N], n, q;

int f[N];
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

int sg[N];
void dfs(int u) {
    for (auto v: G[u]) {
        sg[v] = sg[u] + 1;
        dfs(v);
    }
}

int base[20], bcnt;
void ins(int x) {
    for (int i = 19; i >= 0; i--) {
        if (x >> i & 1) {
            if (!base[i]) { base[i] = x, bcnt++; break; }
            x ^= base[i];
        }
    }
}

int main() {
    n = IO::read(), q = IO::read();
    assert(1 <= n && n <= 1000000);
    assert(1 <= q && q <= 2000000);
    pw[0] = 1;
    for (int i = 1; i < N; i++) {
        pw[i] = 2 * pw[i - 1] % mod;
    }
    for (int i = 1; i <= n; i++) {
        a[i] = IO::read(), ord[a[i]] = i;
        f[i] = i;
    }
    for (int i = 1; i < n; i++) {
        int u = IO::read(), v = IO::read();
        adj[u].push_back(v), adj[v].push_back(u);
    }

    for (int x = 1; x <= n; x++) {
        int u = ord[x];
        for (auto v: adj[u]) {
            if (a[v] < x) {
                int t = find(v);
                assert(t != u);
                G[u].push_back(t);
                f[t] = u;
            }
        }
    }
    dfs(ord[n]);
    
    // for (int i = 1; i <= n; i++) {
    //     printf("sg[%d] = %d\n", i, sg[i]);
    // }

    int _ = 0;
    while (q--) {
        int num = IO::read(); _ += num;
        memset(base, 0, sizeof(base)), bcnt = 0;
        int zero = 0;
        for (int i = 1; i <= num; i++) {
            int ind = IO::read();
            if (sg[ind] == 0) {
                zero++;
                i--, num--;
                continue;
            }
            ins(sg[ind]);
        }
        IO::print(1ll * (pw[num] - pw[num - bcnt] + mod) * pw[zero] % mod, '\n');
    }
    assert(1 <= _ && _ <= 2000000);
    return 0;
}