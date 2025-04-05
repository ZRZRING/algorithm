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

const int N = 1e6 + 10, M = 2e6 + 10, inf = 1e9;

inline int read() {
    bool sym = 0; int res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}

int n, m, mat[N][2][2];

int main() {
    int T = read();
    while (T--) {
        n = read(); m = read();
        int p1 = 0, p2 = 0;
        for (int i = 1; i <= n; i++) {
            mat[i][0][0] = read();
            mat[i][0][1] = read();
            mat[i][1][0] = read();
            mat[i][1][1] = read();
            if (mat[i][1][0] == mat[i][0][1]) p1 = 1;
            for (int j = 1; j <= i; j++) {
                if (mat[i][0][0] == mat[j][0][0] && mat[i][0][1] == mat[j][1][0] && mat[i][1][0] == mat[j][0][1] && mat[i][1][1] == mat[j][1][1]) p2 = 1;
            }
        }
        if (m % 2) {printf("NO\n"); continue;}
        if (p1 && p2) printf("YES\n"); else printf("NO\n");
    }
    return 0;
}