#include <bits/stdc++.h>

#define int64 long long
#define PII std::pair<int, int>
#define endl '\n'

int64 read() {
	int64 res = 0; bool sym = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const int N = 20;

int a[N][N], n, k;

int get(int x1, int y1, int x2, int y2) {
	return a[x2][y2] - a[x1 - 1][y2] - a[x2][y1 - 1] + a[x1 - 1][y1 - 1];
}

bool check(int t) {
	for (int s = 1; s < (1 << n) - 1; s++) {
		// printf("s : %d\n", s);
		bool flag = 0; int cnt = 0;
		for (int i = 1; i <= n - 1; i++) cnt += (s >> i - 1 & 1);
		for (int y1 = 1, y2 = 1; y2 <= n; y2++) {
			for (int x1 = 1, x2 = 1; x2 <= n; x2++) {
				// printf("%d\n", s >> x2 - 1 & 1);
				if (s >> x2 - 1 & 1 || x2 == n) {
					int sum = 0;
					// printf("%d %d %d %d %d\n", get(x1, y1, x2, y2), x1, y1, x2, y2);
					// printf("%d %d %d %d %d\n", get(x1, y2, x2, y2), x1, y2, x2, y2);
					if (get(x1, y2, x2, y2) > t) {flag = 1; break;}
					if (get(x1, y1, x2, y2) > t) {
						cnt++; y1 = y2; y2--; break;
					}
					x1 = x2 + 1;
				}
			}
			if (flag) break;
		}
		if (flag) continue;
		// printf("s : %d, cnt : %d\n", s, cnt);
		if (cnt <= k) return 1;
	}
	for (int s = 1; s < (1 << n) - 1; s++) {
		// printf("s : %d\n", s);
		bool flag = 0; int cnt = 0;
		for (int i = 2; i <= n; i++) cnt += (s >> i - 1 & 1);
		for (int y1 = 1, y2 = 1; y2 <= n; y2++) {
			for (int x1 = n, x2 = n; x1 >= 1; x1--) {
				// printf("%d\n", s >> x2 - 1 & 1);
				if (s >> x1 - 1 & 1 || x1 == 1) {
					int sum = 0;
					// printf("%d %d %d %d %d\n", get(x1, y1, x2, y2), x1, y1, x2, y2);
					// printf("%d %d %d %d %d\n", get(x1, y2, x2, y2), x1, y2, x2, y2);
					if (get(x1, y2, x2, y2) > t) {flag = 1; break;}
					if (get(x1, y1, x2, y2) > t) {
						cnt++; y1 = y2; y2--; break;
					}
					x2 = x1 - 1;
				}
			}
			if (flag) break;
		}
		if (flag) continue;
		// printf("s : %d, cnt : %d\n", s, cnt);
		if (cnt <= k) return 1;
	}
	return 0;
}

int main() {
	n = read(); k = read();
	memset(a, 0, sizeof(a));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			a[i][j] = read();
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
		}
	}
	int l = 0, r = 1e9;
	// check(4);
	while (l < r) {
		int mid = l + r >> 1;
		if (check(mid)) r = mid; else l = mid + 1;
	}
	printf("%d\n", r);
}