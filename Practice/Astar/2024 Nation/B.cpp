#include <bits/stdc++.h>

using int64 = long long;

int main() {
	std::string s;
	std::cin >> s;
	std::reverse(s.begin(), s.end());
	std::string s16 = "0000" + s;
	std::string s4 = "00" + s + "00";
	s = s + "0000";
	int p = 0, n = s16.length();
	// std::cout << s16 << '\n' << s4 << '\n' << s << '\n';
	std::string ans;
	ans.resize(n);
	for (int i = 0; i < n; i++) {
		ans[i] = s[i] + s4[i] + s16[i] + (p & 1) - '0' * 2;
		p >>= 1;
		while (ans[i] > '1') ans[i] -= 2, p++;
	}
	if (p) ans.push_back('1');
	std::reverse(ans.begin(), ans.end());
	std::cout << ans << '\n';
}