#include <bits/stdc++.h>
#include <ios>


using namespace std;


const int MOD = 1000;
const int M = 705;
int sz[M];


struct BigInt {
	int len, a[55];
	
	BigInt() {
		len = 0;
		memset(a, 0, sizeof(a));
	}

	friend BigInt operator*(const BigInt a, const BigInt b) {
		BigInt ans;
		ans.len = a.len + b.len;
		for(int i = 1; i < a.len; ++i)
			for(int j = 1; j < b.len; ++j) {
				ans.a[i + j - 1] += a.a[i] * b.a[j];
				ans.a[i + j] += ans.a[i + j - 1] / MOD;
				ans.a[i + j - 1] %= MOD;
			}
		if (!ans.a[ans.len]) ans.len--;

		return ans;
	}

	friend BigInt max(const BigInt a, const BigInt b) {
		if (a.len != b.len)
			return a.len > b.len ? a : b;

		for (int i = a.len; i > 0; --i)
			if (a.a[i] != b.a[i])
				return a.a[i] > b.a[i] ? a : b;

		return a;
	}

} dp[M][M];


vector<int> edge[M];

void dfs(int v, int p) {
	sz[v] = 1;
	dp[v][1].a[1] = dp[v][1].len = 1;

	for(int to : edge[v]) {
		if (to == p)
			continue;
		dfs(to, v);
		for(int i = sz[v]; i >= 0; --i)
			for(int j = sz[to]; j >= 0; --j) 
				dp[v][i + j] = max(dp[v][i + j], dp[v][i] * dp[to][j]);
		sz[v] += sz[to];
	}
	dp[v][0].len = dp[v][0].a[1] = 0;
	for(int i = sz[v]; i >= 0; --i) {
		BigInt c;
		c.len = 1;
		c.a[1] = i;

		dp[v][0] = max(dp[v][0], c * dp[v][i]);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

