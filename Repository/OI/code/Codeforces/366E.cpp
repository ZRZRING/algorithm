#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
void file() {
    freopen("read.in", "r", stdin);
    freopen("write.out", "w", stdout);
}
const int N = 1e6 + 10, inf = 1e9;
inline int read() {
    int sym = 0, res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}
set<int>S[N][4];
int n, m, rg, s[N], vis[1005][1005], len;
int main() {
    n = read(); m = read(); rg = read(); len = read();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x = read();
            S[x][0].insert(i + j);
            S[x][1].insert(i - j);
            S[x][2].insert(-i + j);
            S[x][3].insert(-i - j);
        }
    }
    int ta = read(), tb;
    for (int i = 2; i <= len; i++) {
        tb = read(); vis[ta][tb] = vis[tb][ta] = 1; ta = tb;
    }
    set<int>::iterator it; int ans = 0;
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            if (!vis[i][j]) continue;
            for (int k = 0; k <= 3; k++) {
                for (it = S[i][k].begin(); it != S[i][k].end(); it++) {
                    ans = max(ans, abs(*S[j][k].begin() - *it));
                    ans = max(ans, abs(*S[j][k].rbegin() - *it));
                }
            }
        }
    }
    printf("%d", ans);
    return 0;
}