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
	int64 n = read(), sum = 0;
	for (int i = 1; i <= n; i++) sum += read();
	if (sum < 2 * n) {printf("No"); return 0;}
	if (n == 1) {
		bool flag = 1;
		for (int i = 2; i * i <= sum; i++) {
			if (sum % i == 0) flag = 0;
		}
		if (flag) printf("Yes"); else printf("No");
		return 0;
	}
	if (n == 2 && sum % 2 == 1) {
		bool flag = 1; sum -= 2;
		for (int i = 2; i * i <= sum; i++) {
			if (sum % i == 0) flag = 0;
		}
		if (flag) printf("Yes"); else printf("No");
		return 0;
	}
	printf("Yes");
	return 0;
}