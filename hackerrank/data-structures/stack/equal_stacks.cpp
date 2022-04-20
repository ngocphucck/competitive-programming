//============================Task================================
//https://www.hackerrank.com/challenges/equal-stacks/problem?isFullScreen=true
//============================Task================================
#include <bits/stdc++.h>


using namespace std;


int minId(vector<int>& v) {
	int i = 0;
	for(int k = 0; k < v.size() - 1; ++k)
		if (v[k] > v[k + 1])
			i = k + 1;

	return i;
}


int maxId(vector<int>& v) {
	int i = 0;
	for(int k = 0; k < v.size() - 1; ++k)
		if (v[k] < v[k + 1])
			i = k + 1;

	return i;
}


void solve() {
	int n1, n2, n3;
	cin >> n1 >> n2 >> n3;

	vector<vector<int>> vs(3, vector<int>());

	vector<int> height(3, 0);

	while(n1--) {
		int a;
		cin >> a;
		vs[0].push_back(a);
		height[0] += a;
	}

	while(n2--) {
		int a;
		cin >> a;
		vs[1].push_back(a);
		height[1] += a;
	}

	while(n3--) {
		int a;
		cin >> a;
		vs[2].push_back(a);
		height[2] += a;
	}

	for(vector<int>& i : vs)
		reverse(i.begin(), i.end());

	while (true) {
		int m = minId(height);
		int n = maxId(height);

		if (height[m] == height[n]) {
			cout << height[m] << endl;
			break;
		}

		height[n] -= vs[n].back();
		vs[n].pop_back();
	}
}


int main() {
	solve();

	return 0;
}

