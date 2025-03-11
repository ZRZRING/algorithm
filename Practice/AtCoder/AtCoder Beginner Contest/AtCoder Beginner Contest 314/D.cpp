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
	int n = read();
	std::string s;
	std::cin >> s;
	std::vector<int> time(n, 0);
	int time_upper = 0, time_lower = 0;
	int m = read();
	for (int i = 1; i <= m; i++) {
		int opt = read(), x = read() - 1;
		std::string c; std::cin >> c;
		if (opt == 1) {
			time[x] = i; s[x] = c[0];
		}
		if (opt == 2) {
			time_lower = i;
		}
		if (opt == 3) {
			time_upper = i;
		}
	}
	for (int i = 0; i < n; i++) {
		if (time_upper > time_lower && time_upper > time[i] && s[i] > 'Z') s[i] = s[i] - 'a' + 'A';
		if (time_lower > time_upper && time_lower > time[i] && s[i] < 'a') s[i] = s[i] - 'A' + 'a';
	}
	std::cout << s << endl;
	return 0;
}