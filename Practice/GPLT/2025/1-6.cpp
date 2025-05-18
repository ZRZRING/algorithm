#include <bits/stdc++.h>

#define IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);

int main() {
	IOS
	int n, m;
	std::cin >> n >> m;
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	while (m--) {
		int opt;
		std::cin >> opt;
		if (opt == 1) {
			int len;
			std::cin >> len;
			std::vector<int> b;
			for (int i = 0; i < len; i++) {
				int x;
				std::cin >> x;
				b.push_back(x);
			}
			std::cin >> len;
			std::vector<int> c;
			for (int i = 0; i < len; i++) {
				int x;
				std::cin >> x;
				c.push_back(x);
			}
			for (int st = 0; st + b.size() <= n; st++) {
				int flag = 1;
				for (int i = st; i < st + b.size(); i++) {
					if (b[i - st] != a[i]) flag = 0;
				}
				if (flag == 1) {
					std::vector<int> d;
					for (int i = 0; i < st; i++) {
						d.push_back(a[i]);
					}
					for (int i = 0; i < c.size(); i++) {
						d.push_back(c[i]);
					}
					for (int i = st + b.size(); i < n; i++) {
						d.push_back(a[i]);
					}
					a = d;
					n = a.size();
					break;
				}
			}
		}
		if (opt == 2) {
			std::vector<int> b;
			b.push_back(a[0]);
			for (int i = 1; i < n; i++) {
				if ((a[i] + a[i - 1]) % 2 == 0) {
					b.push_back((a[i] + a[i - 1]) / 2);
					b.push_back(a[i]);
				} else {
					b.push_back(a[i]);
				}
			}
			a = b;
			n = a.size();
		}
		if (opt == 3) {
			int l, r;
			std::cin >> l >> r;
			std::reverse(a.begin() + l - 1, a.begin() + r);
		}
//		for (int i = 0; i < n; i++) {
//			std::cout << a[i] << " \n"[i == n - 1];
//		}
	}
	for (int i = 0; i < n; i++) {
		std::cout << a[i] << " \n"[i == n - 1];
	}
}
