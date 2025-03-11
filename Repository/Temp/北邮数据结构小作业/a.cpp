#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

struct TIME {
	string time;
	int h, m, s, cnt;

	TIME() {}

	TIME(string T) {
		time = T;
		h = (time[0] - '0') * 10 + time[1] - '0';
		m = (time[3] - '0') * 10 + time[4] - '0';
		s = (time[6] - '0') * 10 + time[7] - '0';
		cnt = h * 3600 + m * 60 + s;
	}

	TIME(int t) {
		h = t / 3600;
		m = t / 60 % 60;
		s = t % 60;
		cnt = h * 3600 + m * 60 + s;
		if (h < 10) time += "0" + to_string(h);
		else time += to_string(h);
		time += ":";
		if (m < 10) time += "0" + to_string(m);
		else time += to_string(m);
		time += ":";
		if (s < 10) time += "0" + to_string(s);
		else time += to_string(s);
	}
	
	bool operator < (TIME a) {
		return cnt < a.cnt;
	}
};

struct ORDER {
	TIME time;
	int id;

	ORDER() {}

	ORDER(TIME t, int d) {
		time = t;
		id = d;
	}
};

int main() {
	freopen("dict.dic", "r", stdin);
	int n, m;
	cin >> n >> m;
	map<string, int> id;
	vector<int> cost(n + 1), cap(n + 1), tot(n + 1), time(n + 1);
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		id[s] = i;
	}
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> cap[i];
	}
	for (int i = 1; i <= n; i++) {
		time[i] = TIME("07:00:00").cnt;
	}
	int W1, W2;
	cin >> W1 >> W2;
	vector<vector<int>> cb(n + m + 1);
	for (int i = 1; i <= n; i++) {
		cb[i].push_back(i);
	}
	getchar();
	for (int i = 1; i <= m; i++) {
		string s;
		getline(cin, s);
		vector<string> t;
		int l = 0;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == ' ') {
				t.push_back(s.substr(l, j - l));
				l = j + 1;
			}
		}
		t.push_back(s.substr(l));
		id[t[0]] = n + i;
		int CB = id[t[0]];
		for (int j = 1; j < t.size(); j++) {
			cb[CB].push_back(id[t[j]]);
		}
	}
	// for (int i = 1; i <= n + m; i++) {
	// 	std::cout << i << ": ";
	// 	for (auto x : cb[i]) {
	// 		std::cout << x << ' ';
	// 	}
	// 	std::cout << endl;
	// }
	// fclose(stdin);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	// for (auto [x, y] : id) {
	// 	std::cout << y << ' ' << x << ' ';
	// 	if (y <= n) cout << cost[y] << ' ' << cap[y] << ' ';
	// 	std::cout << endl;
	// }
	int k, wait_cnt = 0, lock = 0;
	cin >> k;
	vector<int> wait(k + 1);
	vector<ORDER> order(k + 1);
	vector<queue<int>> q(n + 1);
	vector<TIME> ans(k + 1);
	for (int i = 1; i <= k; i++) {
		string t, S;
		std::cin >> t >> S;
		TIME T(t);
		order[i] = ORDER(T, id[S]);
	}
	for (int i = 25200, j = 1; i < 86400; i++) {
		// std::cout << i << endl;
		for (int j = 1; j <= n; j++) {
			if (tot[j] == cap[j]) {
				time[j] = i;
				continue;
			}
			if (i - time[j] == cost[j]) {
				time[j] = i;
				if (q[j].empty()) {
					tot[j]++;
					continue;
				}
				int x = q[j].front();
				q[j].pop();
				wait[x]--;
				if (wait[x] == 0) {
					ans[x] = TIME(i);
					wait_cnt--;
				}
			}
		}
		if (j <= k && i == order[j].time.cnt) {
			if (lock) {
				ans[j].time = "Fail";
				j++;
				continue;
			}
			for (auto food : cb[order[j].id]) {
				if (tot[food]) {
					tot[food]--;
				} else {
					q[food].push(j);
					wait[j]++;
				}
			}
			if (!wait[j]) {
				ans[j] = TIME(i);
			} else {
				wait_cnt++;
			}
			j++;
		}
		if (wait_cnt > W1) {
			lock = 1;
		}
		if (wait_cnt < W2) {
			lock = 0;
		}
	}
	for (int i = 1; i <= k; i++) {
		cout << ans[i].time << endl;
	}
}