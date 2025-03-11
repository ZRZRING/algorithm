#include<bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0)

using int64 = long long;
using ll = long long;

int main() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::vector b(n, std::vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			std::vector<int> t;
			for (int k = i; k <= j; k++) {
				t.push_back(a[k]);
			}
			std::sort(t.begin(), t.end());
			b[i][j] = t[(t.size() + 1) / 2 - 1];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << b[i][j] << " \n"[j == n - 1];
		}
	}
	std::vector c(n, std::vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			std::vector<int> t;
			for (int k = i; k <= j; k++) {
				for (int l = k; l <= j; l++) {
					t.push_back(b[k][l]);
				}
			}
			std::sort(t.begin(), t.end());
			c[i][j] = t[(t.size() + 1) / 2 - 1];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << c[i][j] << " \n"[j == n - 1];
		}
	}
	std::vector<int> t;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			t.push_back(c[i][j]);
		}
	}
	std::sort(t.begin(), t.end());
	std::cout << t[(t.size() + 1) / 2 - 1] << '\n';
	return 0;
}