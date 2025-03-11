#include <bits/stdc++.h>

using int64 = long long;

struct RMQ {
	int n;

	std::vector<std::array<int, 30>> fmin, fmax;

	RMQ(std::vector<int> a) {
		n = a.size() - 1;
		fmin.resize(n + 1);
		fmax.resize(n + 1);
		for (int i = 1; i <= n; i++) {
			fmin[i][0] = fmax[i][0] = a[i];
		}
		for (int i = 1; i < 30; i++) {
			if (1 << i > n) break;
			for (int j = 1; j + (1 << i) - 1 <= n; j++) {
				fmin[j][i] = std::min(fmin[j][i - 1], fmin[j + (1 << i - 1)][i - 1]);
				fmax[j][i] = std::max(fmax[j][i - 1], fmax[j + (1 << i - 1)][i - 1]);
			}
		}
	}

	int max(int l, int r) {
		int k = log(r - l + 1);
		return std::max(fmax[l][k], fmax[r - (1 << k) + 1][k]);
	}

	int min(int l, int r) {
		int k = log(r - l + 1);
		return std::min(fmin[l][k], fmin[r - (1 << k) + 1][k]);
	}
};