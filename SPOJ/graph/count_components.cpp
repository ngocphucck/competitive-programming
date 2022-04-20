#include <bits/stdc++.h>


using namespace std;


vector<vector<int>> adj;


void dfs(int v, vector<bool>& visited) {
	visited[v] = true;
	for(int to : adj[v]) 
		if (!visited[to]) 
			dfs(to, visited);
}


void solve() {
	int n, m;
	cin >> n >> m;
	adj.resize(n);

	for(int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		adj[x - 1].push_back(y - 1);
		adj[y - 1].push_back(x - 1);
	}

	vector<bool> visited(n, false);
	int ans = 0;

	for(int i = 0; i < n; ++i) {
		if (!visited[i]) {
			ans++;
			dfs(i, visited);
		}
	}

	cout << ans << '\n';
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();

	return 0;
}
