#include <bits/stdc++.h>
using namespace std;

const int N = 4005;
const int inf = 1e9;

int a[N][N], b[N][N], n, m;

inline int calc(int a[N][N], int n, int m) {
    static int L[N][N], R[N][N], p[N];
    for (int i = 1; i <= n; i++) {
        L[i][0] = 0, R[i][m + 1] = 0;
        for (int j = 1; j <= m; j++) {
            if (a[i][j]) L[i][j] = j;
            else L[i][j] = L[i][j - 1];
        }
        for (int j = m; j >= 1; j--) {
            if (a[i][j]) R[i][j] = j;
            else R[i][j] = R[i][j + 1];
        }
    }
    int result = 0;
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            p[i] = inf;
            if (L[i][j]) p[i] = min(p[i], j - L[i][j]);
            if (R[i][j]) p[i] = min(p[i], R[i][j] - j);
        }
        static int q[N], l, r;
        l = 1, r = 0;
        #define f(k) (k * k + p[k] * p[k])
        for (int i = 1; i <= n; i++) {
            if (p[i] != inf) {
                while (l < r && (f(q[r]) - f(q[r - 1])) * (i - q[r - 1]) >= (f(i) - f(q[r - 1])) * (q[r] - q[r - 1])) r--;
                q[++r] = i;
            }
            while (l < r && (f(q[l + 1]) - f(q[l])) <= 2 * i * (q[l + 1] - q[l])) l++;
            if (l > r) result ^= inf;
            else result ^= i * i + f(q[l]) - q[l] * 2 * i;
        }
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    int res1 = calc(a, n, m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            b[n + 1 - i][j] = a[i][j];
    int res2 = calc(b, n, m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            b[j][i] = a[i][j];
    int res3 = calc(b, m, n);
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            a[m + 1 - i][j] = b[i][j];
    int res4 = calc(a, m, n);
    printf("%d %d %d %d\n", res1, res2, res3, res4);
    return 0;
}