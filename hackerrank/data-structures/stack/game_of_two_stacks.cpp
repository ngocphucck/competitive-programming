//============================Task================================
//https://www.hackerrank.com/challenges/game-of-two-stacks/problem?isFullScreen=true
//
//Complexity: O(N)
//Solution: prefix sum + array
//============================Task================================
#include <bits/stdc++.h>


using namespace std;


vector<long long int> prefix_suma;
vector<long long int> prefix_sumb;


void solve() {
	long long int n, m, maxSum;
	cin >> n >> m >> maxSum;

	prefix_suma.resize(n + 1);
	prefix_sumb.resize(m + 1);

	prefix_suma[0] = 0;
	prefix_sumb[0] = 0;

	for(int i = 1; i < prefix_suma.size(); ++i) {
		long long int a;
		cin >> a;
		prefix_suma[i] = prefix_suma[i - 1] + a;
	}

	for(int i = 1; i < prefix_sumb.size(); ++i) {
		long long int b;
		cin >> b;
		prefix_sumb[i] = prefix_sumb[i - 1] + b;
	}

	int ans = 0;
	int i = 0;
	int j = prefix_sumb.size() - 1;

	while(true) {
		if (i == prefix_suma.size())
			break;
		if (j == -1)
			break;

		if (prefix_suma[i] + prefix_sumb[j] > maxSum)
			j--;
		else {
			ans = max(ans, i + j);
			i++;
		}
	}

	cout << ans << endl;
}


int main() {
	int t;
	cin >> t;

	while(t--)
		solve();

	return 0;
}

