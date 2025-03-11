#include <bits/stdc++.h>

#define int64 long long
#define endl '\n'

const int64 inf = 1e18;

struct MAT {
	int n;

	std::vector<std::vector<int64> > mat;

	MAT() {n = 0;}

	MAT(int t) {
		n = t;
		mat.resize(n + 1);
		for (int i = 0; i <= n; i++) {
			mat[i].resize(n + 1);
			for (int j = 0; j <= n; j++) {
				mat[i][j] = -1;
			}
		}
	}

	friend MAT operator * (MAT a, MAT b) {
		int n = a.n;
		MAT c(n + 1);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (int k = 1; k <= n; k++) {
					if (a.mat[i][k] == -1 || b.mat[k][j] == -1) continue;
					if (c.mat[i][j] == -1) c.mat[i][j] = a.mat[i][k] + b.mat[k][j];
					else c.mat[i][j] = std::max(c.mat[i][j], a.mat[i][k] + b.mat[k][j]);
				}
			}
		}
		return c;
	}

	friend MAT operator / (MAT a, MAT b) {
		int n = a.n;
		MAT c(n + 1);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (int k = 1; k <= n; k++) {
					if (a.mat[i][k] == -1 || b.mat[k][j] == -1) continue;
					if (c.mat[i][j] == -1) c.mat[i][j] = a.mat[i][k] + b.mat[k][j];
					else c.mat[i][j] = std::min(c.mat[i][j], a.mat[i][k] + b.mat[k][j]);
				}
			}
		}
		return c;
	}
};

int main() {
	int n, m, T;
	std::cin >> n >> m >> T;
	std::vector<MAT> min(40, MAT(n));
	std::vector<MAT> max(40, MAT(n));
	for (int i = 1; i <= m; i++) {
		int u, v;
		int64 t;
		std::cin >> u >> v >> t;
		if (min[0].mat[u][v] == -1) {
			min[0].mat[u][v] = min[0].mat[v][u] = t;
		} else {
			min[0].mat[u][v] = std::min(min[0].mat[u][v], t);
			min[0].mat[v][u] = std::min(min[0].mat[v][u], t);
		}
		if (max[0].mat[u][v] == -1) {
			max[0].mat[u][v] = max[0].mat[v][u] = t;
		} else {
			max[0].mat[u][v] = std::max(max[0].mat[u][v], t);
			max[0].mat[v][u] = std::max(max[0].mat[v][u], t);
		}
	}
	for (int i = 1; 1 << i <= 1e9; i++) {
		max[i] = max[i - 1] * max[i - 1];
	}
	for (int i = 1; 1 << i <= 1e9; i++) {
		min[i] = min[i - 1] / min[i - 1];
	}
	while (T--) {
		int u, v, k;
		std::cin >> u >> v >> k;
		MAT MAX, MIN;
		for (int i = 0; 1 << i <= k; i++) {
			if ((k >> i & 1) == 0) continue;
			if (MAX.n == 0) MAX = max[i];
			else MAX = MAX * max[i];
		}
		for (int i = 0; 1 << i <= k; i++) {
			if ((k >> i & 1) == 0) continue;
			if (MIN.n == 0) MIN = min[i];
			else MIN = MIN / min[i];
		}
		if (MIN.mat[u][v] == -1 || MAX.mat[u][v] == -1) {
			std::cout << -1 << ' ' << -1 << endl;
			continue;
		}
		std::cout << MIN.mat[u][v] << ' ' << MAX.mat[u][v] << endl;
	}
	return 0;
}