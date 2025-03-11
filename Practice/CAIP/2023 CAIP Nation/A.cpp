#include <bits/stdc++.h>

#define int64 long long
#define endl '\n'

int64 read() {
	int64 res = 0; bool sym = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

bool ispower(char x) {
	return x >= 'A' && x <= 'Z';
}

bool islower(char x) {
	return x >= 'a' && x <= 'z';
}

int main() {
	int n = read();
	std::string s;
	std::cin >> s;
	if (s == "yourname") s = "zhangruizhe";
	std::cout << s << endl;
	int len = s.length();
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < len; j++) {
			if (ispower(s[j])) {
				s[j] = (s[j] - 'A' + 1) % 26 + 'A';
			}
			if (islower(s[j])) {
				s[j] = (s[j] - 'a' + 25) % 26 + 'a';
			}
		}
		for (int j = 0; j < len; j++) {
			int x = j; if (isdigit(s[j])) continue;
			if (ispower(s[j])) {
				while (x + 1 < len && ispower(s[x + 1])) x++;
				if (x - j + 1 < 3) continue;
				for (int k = j; k <= x; k++) s[k] += 'a' - 'A'; 
			} else {
				while (x + 1 < len && islower(s[x + 1])) x++;
				if (x - j + 1 < 3) continue;
				for (int k = j; k <= x; k++) s[k] -= 'a' - 'A';
			}
			j = x;
		}
	}
	std::cout << s;
	return 0;
}