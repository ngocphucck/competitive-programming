//============================Task================================
//https://www.hackerrank.com/challenges/down-to-zero-ii/problem?isFullScreen=true
//
//============================Task================================
#include <bits/stdc++.h>
#include <limits>


using namespace std;



void solver() {
	int n;
	cin >> n;

	queue<int> q;
	int dp[n + 1];
	memset(dp, 0, sizeof(dp));
	q.push(n);

	while(q.front() != 0) {
		int num = q.front();
		q.pop();

		if (dp[num - 1] == 0) {
			dp[num - 1] = dp[num] + 1;
			q.push(num - 1);
		}

		for(int i = 2; i <= int(sqrt(num)); ++i) {
			if (num % i == 0 && dp[num / i] == 0) {
				dp[num / i] = dp[num] + 1;
				q.push(num / i);
			}
		}

	}


	cout << dp[0] << endl;
}


int main() {
	int t;
	cin >> t;
	while(t--)
		solver();

	return 0;
}
