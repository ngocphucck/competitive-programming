//============================Task================================
//https://www.hackerrank.com/challenges/queue-using-two-stacks/problem?isFullScreen=true
//============================Task================================
#include <bits/stdc++.h>


using namespace std;


class Queue {
	private:
		stack<int> stk1;
		stack<int> stk2;
	
	public:
		void enqueue(int x) {
			stk1.push(x);
		}

		void dequeue() {
			if (stk2.empty()) {
				while(!stk1.empty()) {
					stk2.push(stk1.top());
					stk1.pop();
				}
			}

			stk2.pop();
		}

		void top() {
			if (stk2.empty()) {
				while(!stk1.empty()) {
					stk2.push(stk1.top());
					stk1.pop();
				}
			}

			cout << stk2.top() << endl;
		}
};


void solver() {
	int q;
	cin >> q;

	Queue queue;
	while(q--) {
		int type;
		cin >> type;

		if (type == 1) {
			int x;
			cin >> x;
			queue.enqueue(x);
		}

		else if (type == 2)
			queue.dequeue();

		else
			queue.top();
	}
}


int main() {
	solver();

	return 0;
}
