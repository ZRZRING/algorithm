#include <bits/stdc++.h>
using namespace std;

const int N = 10005;
const int mod = 998244353;

int f[N], ways[N][8191], n, maxx = 1;

inline void addx(int &x, int y) {
    if ((x += y) >= mod) x -= mod;
}

int main() {
    cin >> n;
    f[1] = 0, f[2] = 1;
    for (int i = 3; i <= n; i++) {
        f[i] = (f[i - 1] + 1) ^ (f[i - 2] + 1);
        maxx = max(maxx, f[i]);
    }
    ways[2][0] = 1;
    for (int i = 3; i <= n; i++) {
        for (int j = 0; j <= maxx; j++) {
            // 往左子树走
            if (j != f[i - 2] + 1)
                addx(ways[i][j], ways[i - 1][(j ^ (f[i - 2] + 1)) - 1]);
            else
                addx(ways[i][j], 1);
            // 往右子树走
            if (j != f[i - 1] + 1)
                addx(ways[i][j], ways[i - 2][(j ^ (f[i - 1] + 1)) - 1]);
            else
                addx(ways[i][j], 1);
        }
    }
    cout << ways[n][0] << '\n';
    return 0;
}