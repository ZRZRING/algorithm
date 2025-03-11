#include <bits/stdc++.h>
 
#define int64 long long
#define endl '\n'
#define PII std::pair<int, int>
#define init_0(x) memset(x, 0, sizeof(x))
#define init_inf(x) memset(x, 0x3f, sizeof(x))
 
inline int64 read() {
	bool sym = 0; int64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const int N = 2e5, mod = 998244353, inf = 0x3f3f3f3f;
 
int main() {
	int T = read();
	while (T--) {
		int n = read(), m = read();
		std::string s[n], ans[n];
		for (int i = 0; i < n; i++) {
			std::cin >> s[i]; ans[i].resize(m);
			for (int j = 0; j < m; j++) ans[i][j] = '.';
		}
		int cnt[n + m] = {0};
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (s[i][j] == 'U') {
					if (cnt[i]) {
						ans[i][j] = 'W'; ans[i + 1][j] = 'B';
					} else {
						ans[i][j] = 'B'; ans[i + 1][j] = 'W';
					}
					cnt[i] ^= 1;
				}
				if (s[i][j] == 'L') {
					if (cnt[n + j]) {
						ans[i][j] = 'W'; ans[i][j + 1] = 'B';
					} else {
						ans[i][j] = 'B'; ans[i][j + 1] = 'W';
					}
					cnt[n + j] ^= 1;
				}
			}
		}
		bool flag = 0;
		for (int i = 0; i < n + m; i++) if (cnt[i]) flag = 1;
		if (flag) {printf("-1\n"); continue;}
		for (int i = 0; i < n; i++) {
			std::cout << ans[i] << endl;
		}
	}
	return 0;
}