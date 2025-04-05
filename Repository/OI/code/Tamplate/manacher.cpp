#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
void file() {
    freopen("read.in", "r", stdin);
    freopen("write.out", "w", stdout);
}
const int N = 1e8;
int n = 1, p[N], ans;
char a[N];
inline void read() {
    char ch = getchar();
    a[0] = '$', a[n] = '#';
    while (ch < 'a' || ch > 'z') ch = getchar();
    while (ch >= 'a' && ch <= 'z') a[++n] = ch, a[++n] = '#', ch = getchar();
}
int main() {
    read();
    for (int i = 1, r = 0, mid; i <= n; i++) {
        if (i <= r) p[i] = min(p[(mid << 1) - i], r - i + 1);
        while (a[i - p[i]] == a[i + p[i]]) ++p[i];
        if (p[i] + i > r) r = p[i] + i - 1, mid = i;
        ans = max(ans, p[i]);
    }
    printf("%d", ans - 1);
    return 0;
}