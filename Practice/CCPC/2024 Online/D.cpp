#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 998244353;

void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
	vector f(n + 1, vector(m + 2, vector<ll>(m + 2)));
    s = " " + s;
    t = " " + t;
    for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s[i] == t[j]) f[i][j][j] = (f[i - 1][j][j] * 2 + 1) % mod;
			else f[i][j][j] = (f[i - 1][j][j] * 2) % mod;
		}
        for (int l = 1; l <= m; l++) {
			for (int r = l + 1; r <= m; r++) {
				if (t[l] == s[i]) f[i][l][r] = (f[i][l][r] + f[i - 1][l + 1][r]) % mod;
				if (t[r] == s[i]) f[i][l][r] = (f[i][l][r] + f[i - 1][l][r - 1]) % mod;
				for (int k = l + 1; k <= r - 1; k++) {
					if (t[k] != s[i]) continue;
					f[i][l][r] = (f[i][l][r] + f[i - 1][l][k - 1] * f[i - 1][k + 1][r]) % mod;
				}
				f[i][l][r] = (f[i][l][r] + 2ll * f[i - 1][l][r]) % mod;
				for (int k = l; k <= r - 1; k++) {
					f[i][l][r] = (f[i][l][r] + f[i - 1][l][k] * f[i - 1][k + 1][r]) % mod;
				}
			}
        }
		// for (int l = 1; l <= m; l++) {
		// 	for (int r = 1; r <= m; r++) {
		// 		std::cout << f[i][l][r] << " \n"[r == m];
		// 	}
		// }
    }
	std::cout << f[n][1][m] << '\n';
}

int main() {
    int T = 1;

    while (T--)
        solve();

    return 0;
}