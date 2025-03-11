#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>

#define file(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout);
#define dbg(x) cerr<<"In Line"<<__LINE__<<" the "<<#x<<" = "<<x<<'\n';
#define abs(x) ((x) < 0 ? -(x) : (x))

using namespace std;

const int N = 6e6 + 10;

inline int read() {
	bool sym = 0; int res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

int n, m, k, T, x[N], y[N], vis[N];

map<char, int> gox, goy;

string str[N];

int main() {
	n = read(); m = read(); n = read(); T = read();
	gox['L'] = 0; gox['R'] = 0; gox['U'] = -1; gox['D'] = 1;
	goy['L'] = -1; goy['R'] = 1; goy['U'] = 0; goy['D'] = 0;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		x[i] = read(); y[i] = read(); int t = x[i] * m + y[i];
		ans += vis[t]; vis[t]++;
	}
	printf("%d\n", ans);
	for (int i = 1; i <= n; i++) cin >> str[i];
	for (int j = 0; j < T; j++) {
		for (int i = 1; i <= n; i++) {
			int t = x[i] * m + y[i];
			vis[t]--; ans -= vis[t];
			x[i] += gox[str[i][j]]; y[i] += goy[str[i][j]];
			t = x[i] * m + y[i];
			ans += vis[t]; vis[t]++;
		}
		printf("%d\n", ans);
	}
	return 0;
}