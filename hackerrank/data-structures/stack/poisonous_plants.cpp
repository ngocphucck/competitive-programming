//============================Task================================
//https://www.hackerrank.com/challenges/poisonous-plants/problem?isFullScreen=true
//============================Task================================
#include <bits/stdc++.h>
#include <string>

using namespace std;


int poisonousPlants(vector<int>& v) {
	stack<int> stk;
	int dp[v.size()];
	int ans = 0;
	
	for(int i = 0; i < v.size(); ++i) {
		dp[i] = 1;
		while(!stk.empty() && v[i] <= v[stk.top()]) {
			dp[i] = max(dp[i], dp[stk.top()] + 1);
			stk.pop();
		}

		if (!stk.empty())
			ans = max(ans, dp[i]);

		stk.push(i);
	}


	return ans;
}


void solve() {
	int n; 
	cin >> n;
	vector<int> v(n);
	for(int& i : v)
		cin >> i;

	cout << poisonousPlants(v) << endl;
}


int main()
{
	solve();

	return 0;
}
