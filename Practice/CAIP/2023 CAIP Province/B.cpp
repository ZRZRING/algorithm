#include <bits/stdc++.h>

#define int64 long long

int64 read() {
	int64 res = 0; bool sym = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

int main() {
	int n = read(), m = read(), trie[5000][200], cnt = 0;
	std::string s, ss, name[5000];
	bool vis[5000] = {0};
	for (int i = 1; i <= n; i++) {
		std::cin >> s;
		int L = s.length(), x = 0;
		for (int i = 0; i < L; i++) {
			if (!trie[x][s[i] - 'A']) trie[x][s[i] - 'A'] = ++cnt;
			x = trie[x][s[i] - 'A'];
		}
		std::cin >> ss;
		name[x] = ss; vis[x] = 1;
	}
	for (int i = 1; i <= m; i++) {
		std::cin >> s;
		ss.clear();
		int L = s.length(), x = 0;
		bool flag = 0;
		for (int i = 0; i < L; i++) {
			if (!trie[x][s[i] - 'A']) {flag = 1; break;}
			x = trie[x][s[i] - 'A'];
			if (vis[x]) ss += name[x], x = 0;
		}
		if (flag) {printf("D\n"); continue;}
		std::cout << ss << '\n';
	}
}