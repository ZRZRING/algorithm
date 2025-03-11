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
	std::string s;
	std::cin >> s;
	std::vector<int64> m2(10, 1), m10(10, 1);
	for (int i = 1; i < 10; i++) m2[i] = m2[i - 1] * 2ll;
	for (int i = 1; i < 10; i++) m10[i] = m10[i - 1] * 10ll;
	int64 ans = 0;
	for (int i = 0; i < s.length(); i++) {
		for (int j = 0; j < s.length() - i; j++) {
			ans += m2[s.length() - j - 1 - (i + j != s.length() - 1)] * m10[j] * (s[i] - '0');
		}
	}
	printf("%lld\n", ans);
	return 0;
}