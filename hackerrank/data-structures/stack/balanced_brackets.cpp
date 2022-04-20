//============================Task================================
//https://www.hackerrank.com/challenges/balanced-brackets/problem?isFullScreen=true
//============================Task================================
#include <bits/stdc++.h>


using namespace std;


bool checkBalanced(string& s) {
	stack<char> stk;
	bool ans = true;
	
	for(char i : s) {
		if (i == '(' || i == '{' || i == '[')
			stk.push(i);

		else if (i == ')' && (stk.empty() || stk.top() != '(')) {
			ans = false;
			break;
		}

		else if (i == ']' && (stk.empty() || stk.top() != '[')) {
			ans = false;
			break;
		}

		else if (i == '}' && (stk.empty() || stk.top() != '{')) {
			ans = false;
			break;
		}
		
		else
			stk.pop();
	}

	if (!stk.empty())
		ans = false;

	return ans;
} 


void solver() {
	int n; 
	cin >> n;

	while(n--) {
		string s;
		cin >> s;
		
		cout << (checkBalanced(s) ? "YES\n" : "NO\n");
	}
}


int main() {
	solver();

	return 0;
}
