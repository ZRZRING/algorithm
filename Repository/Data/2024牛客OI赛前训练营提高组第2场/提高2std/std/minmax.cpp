#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-6;

double a, b, c;

int main() {
    scanf("%lf%lf%lf", &a, &b, &c);
    if (fabs(a) < eps) {
        if (fabs(b) < eps) {
            printf("Max: %.5f\n", c);
            printf("Min: %.5f\n", c);
        } else {
            printf("Max: +inf\n");
            printf("Min: -inf\n");
        }
    } else if (a > 0) {
        double Min = c - b * b / 4 / a;
        printf("Max: +inf\n");
        printf("Min: %.5f\n", Min);
    } else {
        double Max = c - b * b / 4 / a;
        printf("Max: %.5f\n", Max);
        printf("Min: -inf\n");
    }
    return 0;
}