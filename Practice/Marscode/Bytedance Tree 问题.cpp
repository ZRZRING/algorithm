#include <iostream>
#include <vector>

using int64 = long long;
using std::vector;
using std::cout;
using std::endl;

const int mod = 998244353;

template <class T>
T MOD(T& x, int64 p = mod) {
	return x = (x % p + p) % p;
}
template <class T>
T MOD(T&& x, int64 p = mod) {
	return x = (x % p + p) % p;
}

int solution(int nodes, int decorations, vector<vector<int>>& tree) {
    int n = nodes, m = decorations;
    std::vector<int> a = tree[0];
    std::vector e(n + 1, std::vector(0, int()));
    for (int i = 1; i < tree.size(); i++) {
        int u = tree[i][0], v = tree[i][1];
        e[u].push_back(v);
        e[v].push_back(u);
    }
	std::vector f(n + 1, std::vector(m + 1, int64()));
	std::vector g(n + 1, int64());
    auto dfs = [&](auto self, int u, int last) -> void {
		if (a[u]) {
			f[u][a[u]] = 1;
			for (auto v : e[u]) {
				if (v == last) continue;
				self(self, v, u);
				MOD(f[u][a[u]] *= f[v][a[u]] + f[v][0] + g[v]);
			}
		} else {
			f[u][0] = 1;
			for (auto v : e[u]) {
				if (v == last) continue;
				self(self, v, u);
				for (int i = 1; i <= m; i++) {
					MOD(f[u][i] *= f[v][a[v]] + f[v][0] + g[v]);
				}
			}
		}
		for (int i = 1; i <= m; i++) {
			MOD(sum[u] += f[u][i]);
		}
    };
    dfs(dfs, 1, 1);
}

int main() {
    vector<vector<int>> testTree1 = {{1, 0, 0, 0, 0, 2, 3}, {1, 7}, {3, 7}, {2, 1}, {3, 5}, {5, 6}, {6, 4}};
    vector<vector<int>> testTree2 = {{1, 0, 1, 0, 2}, {1, 2}, {1, 5}, {2, 4}, {3, 5}};

    cout << (solution(7, 3, testTree1) == 3) << endl;
    cout << (solution(5, 2, testTree2) == 0) << endl;

    return 0;
}