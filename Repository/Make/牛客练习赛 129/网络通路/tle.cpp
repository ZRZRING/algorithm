#include <algorithm>
#include <bitset>
#include <iostream>

using namespace std;

using lli = long long;
using pii = pair<lli, lli>;
const int INF = 1e9;
const lli inf = 1e18;
const int maxn = 2e5 + 5;
int n, m, N;
int u[205], v[205], d[205];
int f[1 << 17][17];

void solve() {
    int n, m, N;
    cin >> n >> m;
    N = 1 << n;
    for (int i = 1; i <= m; i++) {
        cin >> u[i] >> v[i] >> d[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != (1 << j - 1)) {
                f[i][j] = INF;
			}
        }
    }
    for (int i = 3; i < N; i++) {
        for (int j = i; j; j = j - 1 & i) {
            int tot = 0;
            for (int k = 0; k < n; k++) {
                if ((1 << k) & (i ^ j)) {
                    tot++;
				}
            }
            tot = tot * (n - tot);
            for (int k = 1; k <= m; k++) {
                f[i][u[k]] = min(f[i][u[k]], f[j][u[k]] + f[i ^ j][v[k]] + d[k] * tot);
                f[i][v[k]] = min(f[i][v[k]], f[j][v[k]] + f[i ^ j][u[k]] + d[k] * tot);
            }
        }
    }
    cout << (f[N - 1][1] == INF ? -1 : f[N - 1][1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--) {
		solve();
	}
    return 0;
}
