#include <bits/stdc++.h>

using int64 = long long;

template<typename cmp>
struct DELHEAP {
	int64 sum = 0;

	std::priority_queue<int, std::vector<int>, cmp> q, d;

	int size() { return q.size() - d.size(); }

	bool empty() { return size() == 0; }

	void push(int x) { q.push(x); sum += x; }

	void erase(int x) { d.push(x); sum -= x; }

	int top() {
		while (!q.empty() && !d.empty() && q.top() == d.top()) {
			q.pop();
			d.pop();
		}
		return q.top();
	}
	
	void pop() { erase(q.top()); }
};

struct SET_MID {
	DELHEAP<std::less<int>> L;
	DELHEAP<std::greater<int>> R;

	void adjust() {
		while (L.size() > R.size()) {
			R.push(L.top());
			L.pop();
		}
		while (R.size() > L.size()) {
			L.push(R.top());
			R.pop();
		}
	}

	void insert(int x) {
		if (L.empty() || x <= L.top()) {
			L.push(x);
		} else {
			R.push(x);
		}
		adjust();
	}

	void erase(int x) {
		if (x <= L.top()) {
			L.erase(x);
		} else {
			R.erase(x);
		}
		adjust();
	}

	int64 sum() {
		int64 res = R.sum - L.sum;
		if (L.size() > R.size()) {
			res += L.top();
		}
		return res;
	}
};