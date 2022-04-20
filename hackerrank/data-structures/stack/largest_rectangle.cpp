//============================Task================================
//https://www.hackerrank.com/challenges/largest-rectangle/problem?isFullScreen=true
//
//O(n)
//============================Task================================
#include <bits/stdc++.h>
#include <string>

using namespace std;


long long int largestRectangle(vector<int>& heights) {
	vector<int> lowerLeftIndex;
	vector<int> lowerRightIndex;

	stack<int> st;

	for(int i = 0; i < heights.size(); ++i) {
		while(!st.empty() && heights[st.top()] >= heights[i])
			st.pop();

		if (st.empty())
			lowerLeftIndex.push_back(-1);

		else 
			lowerLeftIndex.push_back(st.top());

		st.push(i);
	}

	while(!st.empty())
		st.pop();

	for(int i = heights.size() - 1; i >= 0; --i) {
		while(!st.empty() && heights[st.top()] >= heights[i])
			st.pop();

		if (st.empty())
			lowerRightIndex.push_back(heights.size());

		else
			lowerRightIndex.push_back(st.top());

		st.push(i);
	}

	long long int ans = 0;

	for(int i = 0; i < heights.size(); ++i)
		ans = max(ans, (long long int)heights[i] * (lowerRightIndex[heights.size() - i - 1] - lowerLeftIndex[i] - 1));

	return ans;
}

void solve() {
	int n;
	cin >> n;
	vector<int> h(n);

	for(int& i : h)
		cin >> i;

	cout << largestRectangle(h) << endl;
}


int main()
{
	solve();

	return 0;
}
