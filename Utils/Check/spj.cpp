#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1010;
int _w;

FILE *in, *usr;

int n, blim, b, a[MAXN], p[MAXN], cnt[MAXN];

namespace Tree {
	int head[MAXN], nxt[MAXN<<1], to[MAXN<<1], m;
	void init() {
		memset(head, -1, sizeof head);
	}
	void adde( int u, int v ) {
		to[m] = v, nxt[m] = head[u], head[u] = m++;
		to[m] = u, nxt[m] = head[v], head[v] = m++;
	}
}

void quit( const char *str, int pt ) {
	fprintf(stderr, "%s\n", str);
	fprintf(stdout, "%d\n", pt);
	exit(0);
}

int read() {
	int x;
	if( fscanf(usr, "%d", &x) == -1 )
		quit("Expected a integer", 0);
	return x;
}

bool vis[MAXN];
void dfs( int u, int fa, int id ) {
	using namespace Tree;
	vis[u] = 1;
	if( a[u] != id ) return;
	for( int i = head[u]; ~i; i = nxt[i] ) {
		int v = to[i];
		if( v == fa ) continue;
		dfs(v, u, id);
	}
}

void check() {
	_w = fscanf(in, "%d%d", &n, &blim);
	Tree::init();
	for( int i = 0; i < n-1; ++i ) {
		int u, v;
		_w = fscanf(in, "%d%d", &u, &v);
		Tree::adde(u, v);
	}
	b = read();
	if( b > n ) quit("Too many provinces", 0);
	for( int i = 1; i <= n; ++i ) {
		a[i] = read();
		if( a[i] < 1 || a[i] > b )
			quit("Invalid province id", 0);
		++cnt[a[i]];
	}
	for( int i = 1; i <= b; ++i )
		if( cnt[i] < blim ) quit("Too few cities in a province", 0);
		else if( cnt[i] > blim*3 ) quit("Too many cities in a province", 0);
	for( int i = 1; i <= b; ++i ) {
		p[i] = read();
		if( p[i] < 1 || p[i] > n )
			quit("Invalid capital id", 0);
	}
	for( int i = 1; i <= n; ++i ) {
		memset(vis, 0, sizeof vis);
		dfs(i, 0, a[i]);
		if( !vis[p[a[i]]] )
			quit("City cannot reach its capital", 0);
	}
	quit("Accepted", 100);
}

int main() {
	check();
	return 0;
}
