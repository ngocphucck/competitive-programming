//============================Task===========================================
//You are given a rooted binary tree. Build and output its in-order, pre-order and post-order traversals.
//============================Libraries and namespaces=======================
#include <algorithm>
#include <bits/stdc++.h>
#include <cctype>
#include <cmath>
#include <functional>
#include <iomanip>
#include <ios>
#include <numeric>
#include <sstream>
#include <string>


using namespace std;


//==========================Macroes===========================================
/* SHORTCUT */
#define sp ' '
#define el '\n'
#define task ""
#define fi first
#define se second
#define pb push_back

/* LOOP */
#define fore(i,e) for(__typeof(e) i = 0; i <= e; ++i)
#define fores(i,e,s) for(__typeof(e) i = 0; i <= e; i+=s)
#define forbe(i,b,e) for(__typeof(e) i = b; i <= e; i++)
#define forbes(i,b,e,s) for(__typeof(e) i = b; i <= e; i+=s)
#define rforb(i,b) for(int i = b; i >= 0; --i)
#define rforbe(i, b, e) for(int i=b; i>=e; --i)

/* ARRAY */
#define sum(a)     ( accumulate ((a).begin(), (a).end(), 0ll) )
#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin() )
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin() )
#define MEMS(x, val) memset(x, val, sizeof(x))

/* DEBUG*/ 
#define dbs(x) cerr<<#x<<" = "<<x<<endl
#define dbf(x) cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<endl

/* FILE OPERATIONS */
#define FILEOP()                        \
{                                       \
    freopen(task".inp", "r", stdin);    \
    freopen(task".out", "w", stdout);   \
}
#define FILEOP_DEBUG()                  \
{                                       \
    freopen(task".inp", "r", stdin);    \
    freopen(task".out", "w", stdout);   \
    freopen(task".err", "w", stderr);   \
}

//=============================Consts======================================
/* CONST*/
const int MOD=1e9 + 7;

//==============================Typedefs===================================
typedef long long int lli;
typedef unsigned long long int ulli;

typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<lli> vlli;
typedef vector<ii> vii;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<vlli> vvlli;
typedef vector<vii> vvii;

//=============================Auxilary functions==========================
void low_str(string& str){fore(i, str.length()) str[i]=tolower(str[i]);}
void up_str(string& str){fore(i, str.length()) str[i]=toupper(str[i]);}
template <typename T> string num_to_str(T num) {ostringstream ostr; ostr << num; return ostr.str();}
string rev_str(string str) {reverse(str.begin(), str.end()); return str;}


//============================Functions===================================
void backtrackInOrder(int n, vector<int>& key, vector<int>& left, vector<int>& right, vector<int>& result) {
	if (n == -1)
		return;
	backtrackInOrder(left[n], key, left, right, result);
	result.push_back(key[n]);
	backtrackInOrder(right[n], key, left, right, result);
}



void backtrackPreOrder(int n, vector<int>& key, vector<int>& left, vector<int>& right, vector<int>& result) {
	if (n == -1)
		return;
	result.push_back(key[n]);
	backtrackPreOrder(left[n], key, left, right, result);
	backtrackPreOrder(right[n], key, left, right, result);
}



void backtrackPostOrder(int n, vector<int>& key, vector<int>& left, vector<int>& right, vector<int>& result) {
	if (n == -1)
		return;
	backtrackPostOrder(left[n], key, left, right, result);
	backtrackPostOrder(right[n], key, left, right, result);
	result.push_back(key[n]);
}

class TreeOrders {
	int n;
	vector<int> key;
	vector<int> left;
	vector<int> right;

	public:
	void read() {
		cin >> n;
		key.resize(n);
		left.resize(n);
		right.resize(n);

		for(int i = 0; i < n; ++i)
			cin >> key[i] >> left[i] >> right[i];
	}

	vector<int> inOrder() {
		vector<int> result;
		backtrackInOrder(0, key, left, right, result);

		return result;
	}

	vector<int> preOrder() {
		vector<int> result;
		backtrackPreOrder(0, key, left, right, result);

		return result;
	}

	vector<int> postOrder() {
		vector<int> result;
		backtrackPostOrder(0, key, left, right, result);

		return result;
	}
};


void print(vector<int> a) {
	for (int i : a)
		cout << i << " ";
	
	cout << el;
}


void solve() {
	TreeOrders treeOrders;
	treeOrders.read();

	print(treeOrders.inOrder());
	print(treeOrders.preOrder());
	print(treeOrders.postOrder());
}

//===========================Main=========================================
int main() {

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	bool multi_input = false;

	if (multi_input) {
	
		int t = 1;
		cin >> t;

		while(t--)
		{
			solve();
		}
	}
	else
		solve();


	cerr << "\nTime taken: " << (float) clock() / CLOCKS_PER_SEC << " seconds" << endl;
}

