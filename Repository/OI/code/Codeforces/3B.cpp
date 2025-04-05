#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
void file() {
    freopen("std.in", "r", stdin);
    freopen("wa.out", "w", stdout);
}
const int N = 1e6 + 10, inf = 1e9;
inline int read() {
    bool sym = 0; int res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}
struct NODE {
    int val, id;
    bool operator < (const NODE a) const {return val > a.val;}
} one[N], two[N];
int n, m, s1[N], s2[N];
int main() {
    n = read(); int cap = read(), p1 = 0, p2 = 0;
    for (int i = 1; i <= n; i++) {
        int w = read(), v = read();
        if (w == 1) one[++p1].val = v, one[p1].id = i;
        else two[++p2].val = v, two[p2].id = i;
    }
    sort(one + 1, one + p1 + 1); sort(two + 1, two + p2 + 1);
    int res = 0, n1 = p1, n2 = p2; cap = min(cap, n1 + n2 * 2); p1 = p2 = 0;
    for (int i = 1; i <= n1; i++) s1[i] = s1[i - 1] + one[i].val;
    for (int i = n1 + 1; i <= cap; i++) s1[i] = s1[i - 1];
    for (int i = 1; i <= n2; i++) s2[i] = s2[i - 1] + two[i].val;
    for (int i = n2 + 1; i <= cap; i++) s2[i] = s2[i - 1];
    for (int i = 0; i <= min(n2, cap / 2); i++) {
        if (s1[cap - i * 2] + s2[i] > res) res = s1[cap - i * 2] + s2[i], p1 = cap - i * 2, p2 = i;
    }
    printf("%d\n", res);
    for (int i = 1; i <= p1; i++) printf("%d ", one[i].id);
    for (int i = 1; i <= p2; i++) printf("%d ", two[i].id);
    return 0;
}