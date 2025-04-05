#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

void file() {
    freopen("loverfinding.in", "r", stdin);
    freopen("loverfinding.out", "w", stdout);
}

const int N = 1e6 + 10, inf = 1e9;

inline int read() {
    bool sym = 0; int res = 0; char ch = getchar();
    while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
    return sym ? -res : res;
}

int n, m, x, y, X, Y, p = 1;
bool vis[5010][5010];

int main() { file();
    n = read(); x = read(); y = read(); X = read(), Y = read();
    vis[x + 2500][y + 2500] = 1; if (x == X && y == Y) {printf("%d", p); return 0;}
    for (int i = 1; i <= n; i++) {
        int dx = read(), dy = read(); x += dx; y += dy;
        if (!vis[x + 2500][y + 2500]) p++; vis[x + 2500][y + 2500] = 1;
        if (x == X && y == Y) {printf("%d", p); return 0;}
    }
    printf("SingleDogMZX");
    return 0;
}