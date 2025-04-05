#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#define MP(a, b) make_pair(a, b)
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
    int a, b, id;
} dat[N];
bool cmp(NODE a, NODE b) {return a.a > b.a;}
int n, m;
int main() {
    n = read();
    for (int i = 1; i <= n; i++) dat[i].a = read(), dat[i].id = i;
    for (int i = 1; i <= n; i++) dat[i].b = read();
    sort(dat + 1, dat + n + 1, cmp);
    printf("%d\n%d ", n / 2 + 1, dat[1].id);
    for (int i = 2; i <= n; i += 2) {
        printf("%d ", max(MP(dat[i].b, dat[i].id), MP(dat[i + 1].b, dat[i + 1].id)).second);
    }
    return 0;
}
