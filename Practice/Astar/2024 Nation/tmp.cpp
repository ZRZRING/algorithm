#include <bits/stdc++.h>

using int64 = long long;

int main() {
	std::map<int, int> s;
	s[6]++;
	s[3]++;
	std::cout << s.rbegin()->first << ' ' << s.begin()->first << '\n';
}