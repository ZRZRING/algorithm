#include <bits/stdc++.h>

using int64 = long long;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	std::string S;
	int64 cnt = 0, score = 0, len = 0;
	while (std::cin >> S) {
		std::vector<std::string> ss;
		int j = 0;
		for (int i = 0; i < S.length(); i++) {
			if (S[i] >= 'A' && S[i] <= 'Z') continue;
			if (S[i] >= '0' && S[i] <= '9') continue;
			if (S[i] >= 'a' && S[i] <= 'z') continue;
			ss.push_back(S.substr(j, i - j));
			if (S[i] >= 'A' && S[i] <= 'Z' || S[i] >= '0' && S[i] <= '9' || S[i] >= 'a' && S[i] <= 'z') {
				;
			} else {
				j = i + 1;
			}
		}
		ss.push_back(S.substr(j));
		for (auto s : ss) {
			if (s.empty()) continue;
//			std::cout << s << '\n';
			cnt++;
			len += s.length();
			std::vector<int> t(3);
			for (int i = 0; i < s.length(); i++) {
				if (s[i] >= 'A' && s[i] <= 'Z') t[0] = 1;
				if (s[i] >= '0' && s[i] <= '9') t[1] = 1;
				if (s[i] >= 'a' && s[i] <= 'z') t[2] = 1;
			}
			if (t[0] && t[1] && t[2]) {
				score += 5;
			} else if (t[0] && t[1] || t[1] && t[2]) {
				score += 3;
			} else if (t[0] && t[2]) {
				score += 1;
			}
		}
	}
	std::cout << score << '\n' << len << ' ' << cnt << '\n';
}
