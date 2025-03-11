#include <bits/stdc++.h>

#define endl '\n'
#define int64 long long

const int mod = 998244353;

void MOD(int &x) {
	while (x < 0) x += mod;
	while (x >= mod) x -= mod;
}

int f[5001][5001][3];

int main() {
	int n, m;
	std::cin >> n >> m;
	std::string S;
	std::cin >> S;
	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		a[i] = S[i - 1] - '0';
	}
	f[0][0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= std::min(i, m); j++) {
			if (j - a[i] >= 0) {
				f[i][j][0] += (f[i - 1][j - a[i]][0] + f[i - 1][j - a[i]][1]) % mod;
			}
			if (j - !a[i] >= 0) {
				f[i][j][1] += f[i - 1][j - !a[i]][0];
				f[i][j][2] += (f[i - 1][j - !a[i]][1] + f[i - 1][j - !a[i]][2]) % mod;
			}
			MOD(f[i][j][0]);
			MOD(f[i][j][1]);
			MOD(f[i][j][2]);
		}
	}
	int ans = 0;
	for (int j = 0; j <= m; j++) {
		for (int k = 0; k <= 2; k++) {
			ans += f[n][j][k];
			MOD(ans);
		}
	}
	std::cout << ans << endl;
	return 0;
}