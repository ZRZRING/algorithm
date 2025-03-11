#include <bits/stdc++.h>

using int64 = long long;

#define endl '\n'

int main() {
	int n;
	std::cin >> n;
	std::vector<std::string> S(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> S[i];
	}
	int K;
	std::cin >> K;
	int cnt = 0;
	std::string t, ans;
	char ch = getchar();
	std::getline(std::cin, t);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < t.length(); j++) {
			int flag = 0;
			for (int k = 0; k < S[i].length(); k++) {
				if (S[i][k] != t[j + k]) {
					flag = 1;
					break;
				}
			}
			if (flag) continue;
			cnt++;
			t = t.substr(0, j) + "<censored>" + t.substr(j, t.length() - j);
//			std::cout << t << endl;
			t.erase(j + 10, S[i].length());
//			std::cout << t << endl;
		}
	}
	if (cnt >= K) {
		std::cout << cnt << endl;
		std::cout << "He Xie Ni Quan Jia!" << endl;
	} else {
		std::cout << t << endl;
	}
}
