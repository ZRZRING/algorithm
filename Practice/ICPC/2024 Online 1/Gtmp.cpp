#include<bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0)

using int64 = long long;
using ll = long long;

int main() {
	freopen("G.txt", "w", stdout);
	int n = 5;
	std::vector<int> a(n);
	std::iota(a.begin(), a.end(), 0);
	do {
		std::cout << "******************************\n";
		for (int i = 0; i < n; i++) {
			std::cout << a[i] << " \n"[i == n - 1];
		}
		std::cout << '\n';
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
		std::cout << '\n';
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				std::cout << c[i][j] << " \n"[j == n - 1];
			}
		}
		std::vector d(n, std::vector<int>(n));
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				std::vector<int> t;
				for (int k = i; k <= j; k++) {
					for (int l = k; l <= j; l++) {
						if (k == i && l == j) continue;
						t.push_back(b[k][l]);
					}
				}
				std::sort(t.begin(), t.end());
				if (i == j) {
					d[i][j] = b[i][j];	
				} else {
					d[i][j] = t[(t.size() + 1) / 2 - 1];
				}
			}
		}
		std::cout << '\n';
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				std::cout << d[i][j] << " \n"[j == n - 1];
			}
		}
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (c[i][j] != c[i + 1][j] && c[i][j] != c[i][j - 1]) {
					std::cout << "error!\n";
					return 0;
				}
			}
		}
		std::cout << '\n';
		std::vector<int> t;
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				t.push_back(c[i][j]);
			}
		}
		std::sort(t.begin(), t.end());
		std::cout << t[(t.size() + 1) / 2 - 1] << '\n';
		t.clear();
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				t.push_back(b[i][j]);
			}
		}
		std::sort(t.begin(), t.end());
		std::cout << t[(t.size() + 1) / 2 - 1] << '\n';
		std::cout << "******************************\n";
	} while (std::next_permutation(a.begin(), a.end()));
	return 0;
}