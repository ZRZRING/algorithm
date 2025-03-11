#include <bits/stdc++.h>

#define int64 long long
#define endl '\n'

inline int64 read() {
	bool sym = 0; int64 res = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

const int N = 2e5 + 10, mod = 998244353, inf = 0x3f3f3f3f;

int main() {
	int T = read();
	while (T--) {
		int n = read(), k = read();
		std::vector<std::string> S(n);
		for (int i = 0; i < n; i++) std::cin >> S[i];
		if (n * k % 100 != 0) {printf("error\n"); continue;}
		auto zout = [&](int t) {
			std::vector<std::string> T;
			n *= t; T.resize(n);
			for (int i = 0; i < n; i++) T[i].resize(n);
			for (int i = 0; i < n / t; i++) {
				for (int j = 0; j < n / t; j++) {
					for (int x = 0; x < t; x++) {
						for (int y = 0; y < t; y++) {
							T[i * t + x][j * t + y] = S[i][j];
						}
					}
				}
			}
			S.clear(); S = T;
		};
		auto zin = [&](int t) -> bool {
			std::vector<std::string> T;
			n /= t; T.resize(n);
			for (int i = 0; i < n; i++) T[i].resize(n);
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					for (int x = 0; x < t; x++) {
						for (int y = 0; y < t; y++) {
							if (S[i * t + x][j * t + y] != S[i * t][j * t]) return 1;
						}
					}
					T[i][j] = S[i * t][j * t];
				}
			}
			S.clear(); S = T; return 0;
		};
		if (k == 200) zout(2);
		if (k == 175) {
			if (zin(4)) {printf("error\n"); continue;} zout(7);
		}
		if (k == 150) {
			if (zin(2)) {printf("error\n"); continue;} zout(3);
		}
		if (k == 125) {
			if (zin(4)) {printf("error\n"); continue;} zout(5);
		}
		for (int i = 0; i < n; i++) std::cout << S[i] << '\n';
	}
	return 0;
}
