//============================Task================================
//https://www.hackerrank.com/challenges/maximum-element/problem?isFullScreen=true
//============================Task================================
#include <bits/stdc++.h>
#include <string>

using namespace std;


void solver() {
	int n;
	cin >> n;

	stack<int> stk;
	stack<int> max_stk;

	while(n--) {
		int op;
		cin >> op;

		if (op == 1) {
			int num;
			cin >> num;

			stk.push(num);
			max_stk.push(max_stk.empty() ? num : max(max_stk.top(), num));
		}

		if (op == 2) {
			stk.pop();
			max_stk.pop();
		}

		if (op == 3)
			cout << max_stk.top() << endl;
	}
}


int main()
{
	solver();

	return 0;
}
