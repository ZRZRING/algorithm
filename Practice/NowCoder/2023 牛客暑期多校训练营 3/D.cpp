#include <bits/stdc++.h>

#define int64 long long

inline int64 read() {
	bool sym = 0; int64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const int N = 2e5 + 10, mod = 998244353, inf = 0x3f3f3f3f;

int main() {
	int n = read();
	std::string s;
	bool A[n + 1][n + 1], B[n + 1][n + 1];
	for (int i = 1; i <= n; i++) {
		std::cin >> s;
		for (int j = 0; j < n; j++) {
			A[i][j + 1] = s[j] - '0';
			B[i][j + 1] = s[j] - '0';
		}
	}
	int ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0;
	for (int i = 1; i <= n; i++) {
		if (A[i][1] == 0) {
			for (int j = 1; j <= n; j++) A[i][j] ^= 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (A[1][i] == 0) {
			for (int j = 1; j <= n; j++) A[j][i] ^= 1;
		}
	}
	bool flag = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (A[i][j] == 0) flag = 1;
		}
	}
	if (flag) {printf("-1"); return 0;}
	for (int i = 1; i <= n; i++) B[i][1] ? ans1++ : ans2++;
	for (int i = 1; i <= n; i++) B[1][i] ? ans3++ : ans4++;
	printf("%d", std::min(ans1, ans2) + std::min(ans3, ans4));
	return 0;
}