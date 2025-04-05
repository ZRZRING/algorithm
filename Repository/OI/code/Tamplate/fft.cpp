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
const int N = 4e6 + 10;
const double pi = acos(-1.0);
inline int read() {
    int sym = 0, res = 0;char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}
struct node{
    double x, y;
}a[N], b[N];
int n, m, len, rev[N], maxn = 1;
node operator + (const node a, const node b) {return (node){a.x + b.x, a.y + b.y};}
node operator - (const node a, const node b) {return (node){a.x - b.x, a.y - b.y};}
node operator * (const node a, const node b) {return (node){a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x};}
void fft(node *a, int opt) {
    for (int i = 0; i < maxn; i++) {
        if (i < rev[i]) swap(a[i], a[rev[i]]);
    }
    for (int i = 1; i < maxn; i <<= 1) {
        node W = (node){cos(pi / i), sin(pi / i) * opt};
        for (int j = 0; j < maxn; j += i << 1) {
            node w = (node){1, 0};
            for (int k = j; k < i + j; k++) {
                node x = a[k], t = w * a[i + k];
                a[k] = x + t; a[i + k] = x - t; w = w * W;
            }
        }
    }
}
int main() {
    n = read(); m = read();
    for (int i = 0; i <= n; i++) scanf("%lf", &a[i]);
    for (int i = 0; i <= m; i++) scanf("%lf", &b[i]);
    while (maxn <= n + m) maxn <<= 1, len++;
    for (int i = 0; i < maxn; i++) {
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << len - 1);
    }
    fft(a, 1); fft(b, 1);
    for (int i = 0; i < maxn; i++) a[i] = a[i] * b[i];
    fft(a, -1);
    for (int i = 0; i <= m + n; i++) printf("%d ", (int)(a[i].x / maxn + 0.5));
    return 0;
}