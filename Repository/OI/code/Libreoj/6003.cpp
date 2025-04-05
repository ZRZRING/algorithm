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
int n, m, a[60][N];
bool pd(int x) {
    for (int i = 1; i <= 3e4; i++) {
        if (i * i == x) return 1;
        if (i * i > x) return 0;
    }
}
void write() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < a[i][0]; j++) {
            printf("%d ", a[i][j]);
        }
        printf("%d\n", a[i][a[i][0]]);
    }
}
int main() {
    n = read(); int top = 0;
    for (int j = 1; ;j++) {
        int flag = 1;
        for (int i = 1; i <= top; i++) {
            if (pd(a[i][a[i][0]] + j)) {
                a[i][0]++; a[i][a[i][0]] = j;
                flag = 0; 
            }
        }
        if (flag) {
            a[++top][0] = 1; a[top][1] = j;
            if (top > n) {
                printf("%d\n", j - 1); write(); return 0;
            }
        }
    }
    return 0;
}