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
struct node {
    int l, r, type, id, t;
} s[N], s1[N], s2[N];
int n, m, a[N], cnt;
int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; i++) {
        a[i] = read(); s[++cnt] = (node){a[i], 1, 1, i, 0};
    }
    for (int i = 1; i <= m; i++) {
        int l = read(), r = read(), t = read();
        s[++cnt] = (node){l, r, 2, i, t};
    }
    return 0;
}