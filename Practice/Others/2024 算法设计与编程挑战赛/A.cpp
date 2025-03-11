#include <bits/stdc++.h>

#define int64 long long
#define endl '\n'

int main() {
	std::string s;
	std::cin >> s;
	int n;
	std::cin >> n;
	std::set<std::string> t;
	for (int l = 0; l < s.length(); l++) {
		for (int r = l; r < std::min(l + 5, (int)s.length()); r++) {
			t.insert(s.substr(l, r - l + 1));
		}
	}
	int cnt = 0;
	for (auto c : t) {
		cnt++;
		if (cnt == n) {
			std::cout << c << endl;
			return 0;
		}
	}
	return 0;
}