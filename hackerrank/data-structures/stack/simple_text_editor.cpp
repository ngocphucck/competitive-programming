//============================Task================================
//https://www.hackerrank.com/challenges/simple-text-editor/problem
//
//O(n)
//============================Task================================
#include <bits/stdc++.h>
#include <string>

using namespace std;


void simpleTextEditor() {
	int q;
	cin >> q;
	stack<int> undoOperator;
	vector<char> undoStorage;
	vector<char> s;

	while(q--) {
		string op;
		cin >> op;

		if (op == "1") {
			string str;
			cin >> str;

			for(char i : str)
				s.push_back(i);

			undoOperator.push(1);
			undoOperator.push(str.length());
		}

		else if (op == "2") {
			int length;
			cin >> length;
			undoOperator.push(2);
			undoOperator.push(length);

			while(length--) {
				undoStorage.push_back(s.back());
				s.pop_back();
			}
		}

		else if (op == "3") {
			int k;
			cin >> k;
			cout << s[k - 1] << endl;
		}

		else {
			int _length = undoOperator.top();
			undoOperator.pop();
			int _op = undoOperator.top();
			undoOperator.pop();

			if (_op == 1) {
				while(_length--)
					s.pop_back();
			}

			else {
				while(_length--) {
					s.push_back(undoStorage.back());
					undoStorage.pop_back();
				}
			}
		}

	}
}


void solve() {
	simpleTextEditor();
}


int main()
{
	solve();

	return 0;
}
