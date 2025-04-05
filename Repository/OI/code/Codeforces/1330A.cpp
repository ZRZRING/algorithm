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
const int N = 1e3 + 10;
inline int read() {
    int sym = 0, res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}
int n, m, vis[N];
int main() {
    int T = read();
    while (T--) {
        n = read(); m = read(); memset(vis, 0, sizeof(vis));
        int ans = 0;
        for (int i = 1; i <= n; i++) {int x = read(); vis[x] = 1;}
        for (ans = 1; ans <= N; ans++) {
            if (!vis[ans]) {
                m--; if (m < 0) {ans--; break;}
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}