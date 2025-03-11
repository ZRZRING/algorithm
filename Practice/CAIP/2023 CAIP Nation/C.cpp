#include <bits/stdc++.h>

#define int64 long long
#define endl '\n'
#define PII std::pair<int, int>

int64 read() {
	int64 res = 0; bool sym = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

struct NODE {
	int time, pot, order;
	friend bool operator < (NODE a, NODE b) {
		return a.time == b.time ? a.pot > b.pot : a.time > b.time;
	} 
};

int main() {
	int k = read(), m = read(), n = read();
	std::vector<int> time(k + 1), a(n + 1);
	for (int i = 1; i <= k; i++) {
		time[i] = read();
	}
	for (int i = 1; i <= n; i++) {
		a[i] = read();
	}
	std::priority_queue<NODE> q;
	int now = 1;
	for (int i = 1; i <= m; i++) q.push({0, i, 0});
	std::vector<PII> ans;
	std::vector<int> cnt(m + 1);
	for (int i = 1; i <= n; i++) {
		int t = q.top().time, x = q.top().pot, c = q.top().order;
		q.pop();
		q.push({(t + time[a[i]]), x, i});
		if (!c) continue;
		cnt[x]++; ans.push_back({c, t});
	}
	while (!q.empty()) {
		int t = q.top().time, x = q.top().pot, c = q.top().order;
		q.pop(); if (!c) continue;
		cnt[x]++; ans.push_back({c, t});
	}
	std::sort(ans.begin(), ans.end(), [](PII a, PII b) {
		return a.second == b.second ? a.first < b.first : a.second < b.second;
	});
	for (int i = 0; i < n; i++) {
		printf("%d:%d", ans[i].first, ans[i].second); if (i != n - 1) printf(" ");
	}
	puts("");
	for (int i = 1; i <= m; i++) {
		printf("%d", cnt[i]); if (i != m) printf(" ");
	}
	return 0;
}