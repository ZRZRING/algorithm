#include <bits/stdc++.h>

#define int64 long long
#define endl '\n'

int64 read() {
	int64 res = 0; bool sym = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

int main() {
	int n = read();
	int64 sum = 0, a[n + 1], b[n + 1];

	std::pair<int64, int64> data[n + 1];
	for (int i = 1; i <= n; i++) {
		data[i] = {read(), read()}; sum += data[i].first;
	}

	std::sort(data + 1, data + n + 1);
	for (int i = 1; i <= n; i++) a[i] = data[i].first, b[i] = data[i].second;
	// for (int i = 1; i <= n; i++) printf("%d %d\n", data[i].first, data[i].second);

	std::priority_queue<std::pair<int64, int> > q;
	for (int i = 1; i <= n; i++) q.push({b[i], i});
	
	int64 max = q.top().first;
	int pos = q.top().second, tail = n;
	q.pop();

	std::vector<int64> ans(n + 1, 0);
	ans[n] = sum + max;

	bool vis[n + 1] = {0};
	for (int i = n - 1; i >= 1; i--) {
		while (tail && vis[tail]) tail--;
		while (!q.empty() && vis[pos]) {
			max = q.top().first; pos = q.top().second; q.pop();
		}

		// printf("%lld %d %d ", max, pos, tail);
		int64 x = max + a[pos], y = a[tail];
		while (!q.empty() && vis[q.top().second]) q.pop();
		if (!q.empty()) x -= q.top().first;
		// printf("%lld %lld\n", x, y);

		if (tail == pos || x > y) {
			ans[i] = ans[i + 1] - x; vis[pos] = 1;
		} else {
			ans[i] = ans[i + 1] - y; vis[tail] = 1;
		}
	}

	for (int i = 1; i <= n; i++) printf("%lld\n", ans[i]);

	return 0;
}