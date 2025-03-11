#include <bits/stdc++.h>

#define int64 long long
#define PII std::pair<int, int>

int64 read() {
	int64 res = 0; bool sym = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const int inf = 2e9 + 7, N = 2e5 + 10;

struct NODE {
	std::string s;
	int p;
	friend bool operator == (const NODE a, const NODE b) {
		return a.s == b.s && a.p == b.p;
	}
};

NODE to[N];

std::map<int, NODE> back;

std::vector<int> edge[N];

void print(int x) {
	std::cout << back[x].s << ' ' << back[x].p;
}

int main() {
	int m = read(), n = 0;
	for (int i = 1; i <= m; i++) {
		NODE U, V; int u = 0, v = 0;
		std::cin >> U.s >> U.p >> V.s >> V.p;
		for (int j = 1; j <= n; j++) {
			if (U == to[j]) {u = j; break;}
		}
		if (!u) u = ++n, to[u] = U;
		for (int j = 1; j <= n; j++) {
			if (V == to[j]) {v = j; break;}
		}
		if (!v) v = ++n, to[v] = V;
		// printf("%d %d\n", u, v);
		back[u] = U; back[v] = V;
		edge[u].push_back(v);
	}
	int pre[N] = {0}, node[N], ans = inf;
	for (int s = 1; s <= n; s++) {
		bool vis[N] = {0};
		int dis[N];
		memset(dis, 0x3f, sizeof(dis));
		std::priority_queue<PII, std::vector<PII>, std::greater<PII> > q;
		q.push({0, s}); dis[s] = 0;
		while (!q.empty()) {
			int u = q.top().second; q.pop(); vis[u] = 1;
			for (auto v : edge[u]) {
				if (vis[v]) continue;
				if (dis[u] + 1 < dis[v]) {
					dis[v] = dis[u] + 1; pre[v] = u; q.push({dis[v], v});
				}
			}
		}
		// for (int i = 1; i <= n; i++) printf("%d\n", dis[i]);
		for (int t = 1; t <= n; t++) {
			if (back[s].s != back[t].s) continue;
			if (back[s].p == back[t].p) continue;
			if (dis[t] >= ans) continue;
			// printf("%d %d\n", s, t);
			int x = t, p = 1; ans = dis[t]; node[1] = x;
			while (pre[x]) {
				x = pre[x]; node[++p] = x;
			}
			std::reverse(node + 1, node + ans + 2);
		}
	}
	// for (int i = 1; i <= ans + 1; i++) printf("%d ", node[i]);
	for (int i = 1; i <= ans; i++) {
		print(node[i]); printf(" "); print(node[i + 1]); printf(" ");
	}
	printf("= "); print(node[1]); printf(" "); print(node[ans + 1]);
}
