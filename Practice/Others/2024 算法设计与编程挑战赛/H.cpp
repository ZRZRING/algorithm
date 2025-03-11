#include <bits/stdc++.h>

#define int64 long long
#define endl '\n'

int main() {
	std::string s;
	std::cin >> s;
	int n = s.length();
	for (int i = 3; i < n; i++) {
		std::cout << (int)s[i];
	}
	for (int i = 0; i < 3; i++) {
		std::cout << (int)s[i];
	}
	return 0;
}