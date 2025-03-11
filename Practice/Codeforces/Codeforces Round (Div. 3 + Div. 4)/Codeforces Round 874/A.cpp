#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstring>
#include <functional>
#include <map>

#define int64 long long

inline int64 read() {
	bool sym = 0; int64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

int main() {
	int T = read();
	while (T--) {
		bool vis[1000] = {0};
		int n = read();
		std::string s;
		std::cin >> s;
		int ans = 0;
		for (int i = 0; i < n - 1; i++) {
			if (vis[(s[i] - 'a') * 26 + s[i + 1]]) continue;
			vis[(s[i] - 'a') * 26 + s[i + 1]] = 1; ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}