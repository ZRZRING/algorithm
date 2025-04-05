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
const int N = 500010;
const double eps = 1e-10;
inline int read() {
    int sym = 0, res = 0;char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}
struct node{
    double x, y;
    node (double xx = 0, double yy = 0) {x = xx, y = yy;}
} pos[N];
node operator + (const node &a, const node &b) {return (node){a.x + b.x, a.y + b.y};}
node operator - (const node &a, const node &b) {return (node){a.x - b.x, a.y - b.y};}
node operator * (const node &a, const double &b) {return (node){a.x * b, a.y * b};}
node operator / (const node &a, const double &b) {return (node){a.x / b, a.y / b};}
double dot(node a, node b) {return a.x * b.x + a.y * b.y;}
double cross(node a, node b) {return a.x * b.y - a.y * b.x;}
double dist(node a, node b) {return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));}
int n, m, top, s[N];
double ans;
int comp(double a, double b) {
    double c = a - b;
    if (fabs(c) < eps) return 0;
    if (c > 0) return 1;
    else return -1;
}
bool cmp(node a, node b) {
    return comp(a.x, b.x) == 0 ? a.y < b.y : a.x < b.x;
}
int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        scanf("%lf%lf", &pos[i].x, &pos[i].y);
    }
    sort(pos + 1, pos + n + 1, cmp);
    top = 0; s[++top] = 1;
    for (int i = 2; i <= n; i++) {
        while (top >= 2 && comp(cross(pos[s[top]] - pos[s[top - 1]], pos[i] - pos[s[top - 1]]), 0) >= 0) top--;
        s[++top] = i;
    }
    for (int i = 1; i < top; i++) ans += dist(pos[s[i]], pos[s[i + 1]]);
    top = 0; s[++top] = n;
    for (int i = n - 1; i >= 1; i--) {
        while (top >= 2 && comp(cross(pos[s[top]] - pos[s[top - 1]], pos[i] - pos[s[top - 1]]), 0) >= 0) top--;
        s[++top] = i;
    }
    for (int i = 1; i < top; i++) ans += dist(pos[s[i]], pos[s[i + 1]]);
    printf("%.2lf", ans);
    return 0;
}