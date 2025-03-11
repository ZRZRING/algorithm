#include <bits/stdc++.h>

#define int64 long long
#define PII std::pair<int, int>

int64 read() {
    int64 res = 0;
    bool sym = 0;
    char ch = getchar();
    while (!isdigit(ch))
        sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch))
        res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}
int main() {
    int t = read();
    while (t--) {
        long double x11 = read(), y11 = read(), x12 = read(), y12 = read();
        long double x21 = read(), y21 = read(), x22 = read(), y22 = read();
        long double c2x = (x22 + x21) / 2.0;
        long double c2y = (y22 + y21) / 2.0;  // c2圆心
        long double r2 = sqrt(fabs(x22 - x21) * fabs(x22 - x21) + fabs(y22 - y21) * fabs(y22 - y21)) / 2.0;
        long double p2 = r2 / sqrt(2);
        long double x1 = c2x + p2, y1 = c2y + p2;
        long double x2 = c2x + p2, y2 = c2y - p2;
        long double x3 = c2x - p2, y3 = c2y - p2;
        long double x4 = c2x - p2, y4 = c2y + p2;
        long double c1x = (x11 + x12) / 2.0;
        long double c1y = (y11 + y12) / 2.0;
        long double ans1 = fabs(x1 - c1x) + fabs(y1 - c1y);
        long double ans2 = fabs(x2 - c1x) + fabs(y2 - c1y);
        long double ans3 = fabs(x3 - c1x) + fabs(y3 - c1y);
        long double ans4 = fabs(x4 - c1x) + fabs(y4 - c1y);
        printf("%.10Lf\n", std::min({ans1, ans2, ans3, ans4}));
    }
    return 0;
}