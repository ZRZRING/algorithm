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

void solve() {
	int n = read();
	std::string s[n + 1];
	std::vector<int> v(n + 1), k(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> s[i];
		v[i] = read();
		if (s[i][1] == 'd') continue;
		k[i] = read();
	}
	int i = 1, x = 0;
	std::vector<std::vector<bool> > vis(n + 1, std::vector<bool>(256));
	while (i != n + 1) {
		if (vis[i][x]) {printf("No\n"); return;} vis[i][x] = 1;
		if (s[i][1] == 'd') x = (x + v[i]) % 256, i++;
		else if (s[i][1] == 'e') if (x == v[i]) i = k[i]; else i++;
		else if (s[i][1] == 'n') if (x != v[i]) i = k[i]; else i++;
		else if (s[i][1] == 'l') if (x < v[i]) i = k[i]; else i++;
		else if (s[i][1] == 'g') if (x > v[i]) i = k[i]; else i++;
	}
	printf("Yes\n");
}

int main() {
	int T = read();
	while (T--) solve();
	return 0;
}