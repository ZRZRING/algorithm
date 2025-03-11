#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<map>

using namespace std;

const int N = 2e6 + 10;

int read() {
	int res = 0; bool sym = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

int n, m, k, vis[2010][2010];

char opt[N];

void solve() {
	n = read(); m = read(); k = read();
	scanf("%s", opt + 1); int len = strlen(opt + 1);
	int lx = 1, ly = 1, rx = n, ry = m;
	int LX = 1, LY = 1, RX = n, RY = m;
	int s = 1005, x = s, y = s;
	for (int i = s - n - 1; i <= s + n + 1; i++) {
		for (int j = s - m - 1; j <= s + m + 1; j++) {
			vis[i][j] = 0;
		}
	}
	vis[s][s] = 1;
	for (int i = 1; i <= len; i++) {
		if (opt[i] == 'U') LX++, RX++, lx = max(lx, LX), x++, vis[x][y] = 1;
		if (opt[i] == 'D') LX--, RX--, rx = min(rx, RX), x--, vis[x][y] = 1;
		if (opt[i] == 'L') LY++, RY++, ly = max(ly, LY), y++, vis[x][y] = 1;
		if (opt[i] == 'R') LY--, RY--, ry = min(ry, RY), y--, vis[x][y] = 1;
	}
	if (lx > rx || ly > ry) {
		printf("%d\n", k == 0 ? n * m : 0); return;
	}
	int res = (rx - lx + 1) * (ry - ly + 1) - k;
	if (res < 0) {
		printf("0\n"); return;
	}
	for (int i = s - n; i <= s + n; i++) {
		for (int j = s - m; j <= s + m; j++) {
			vis[i][j] += vis[i - 1][j] + vis[i][j - 1] - vis[i - 1][j - 1];
		}
	}
	int ans = 0;
	for (int i = s; i <= s + n - 1; i++) {
		for (int j = s; j <= s + m - 1; j++) {
			int x1 = i - n + lx, y1 = j - m + ly, x2 = i - n + rx, y2 = j - m + ry;
			int t = vis[x2][y2] - vis[x1 - 1][y2] - vis[x2][y1 - 1] + vis[x1 - 1][y1 - 1];
			// printf("%d %d %d %d %d\n", x1, y1, x2, y2, t);
			ans += (t == res);
		}
	}
	printf("%d\n", ans);
}

int main() {
	int T = read();
	while (T--) {solve();}
	return 0;
}