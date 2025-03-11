#include <bits/stdc++.h>

#define int64 long long
#define PII std::pair<int, int>
#define endl '\n'

int64 read() {
	int64 res = 0; bool sym = 0; char ch = getchar();
	while (!isdigit(ch)) sym |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) res = (res << 3) + (res << 1) + (ch ^ 48), ch = getchar();
	return sym ? -res : res;
}

int main() {
	std::string S, T;
	std::cin >> S >> T;
	int n = S.length(), m = T.length(), next[2][m + 1];
	next[0][0] = 0;
	for (int i = 1, j = 0; i <= m; i++) {
		while (j && T[i] != T[j + 1]) j = next[0][j];
		if (T[i] == T[j + 1]) j++; next[0][i] = j;
	}
	return 0;
}