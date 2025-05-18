#include <bits/stdc++.h>

int main() {
	std::string s;
	std::cin >> s;
	int n = s.length();
	std::stack<char> S;
	for (int i = 0; i < n; i++) {
		if (s[i] == ')') {
			std::string ans;
			while (!S.empty() && S.top() != '(') {
				ans.push_back(S.top());
				S.pop();
			}
			S.pop();
			std::reverse(ans.begin(), ans.end());
			std::cout << ans << '\n';
		} else {
			S.push(s[i]);
		}
	}
}
