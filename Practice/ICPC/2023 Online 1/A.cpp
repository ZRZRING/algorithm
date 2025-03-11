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

int main() {
	int n = read(), m = read();
	std::vector<std::string> s, t, ans;
	std::set<std::string> vis;
	for (int i = 0; i < n; i++) {
		std::string str;
		std::cin >> str;
		if (vis.count(str)) continue;
		vis.insert(str); s.push_back(str);
	}
	vis.clear();
	for (int i = 0; i < m; i++) {
		std::string str;
		std::cin >> str;
		if (vis.count(str)) continue;
		vis.insert(str); t.push_back(str);
	}
	vis.clear();
	n = s.size(); m = t.size();
	for (int i = 0; i < std::min(n, m); i++) {
		if (!vis.count(s[i])) {
			vis.insert(s[i]); ans.push_back(s[i]);
		}
		if (!vis.count(t[i])) {
			vis.insert(t[i]); ans.push_back(t[i]);
		}
	}
	if (n < m) {
		for (int i = n; i < m; i++) {
			if (vis.count(t[i])) continue;
			vis.insert(t[i]); ans.push_back(t[i]);
		}
	} else {
		for (int i = m; i < n; i++) {
			if (vis.count(s[i])) continue;
			vis.insert(s[i]); ans.push_back(s[i]);
		}
	}
	for (auto tmp : ans) {
		std::cout << tmp << endl;
	}
	return 0;
}