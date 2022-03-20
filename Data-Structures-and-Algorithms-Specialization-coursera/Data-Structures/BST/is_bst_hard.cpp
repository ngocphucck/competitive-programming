//============================Task===========================================
//You are given a binary tree with integers as its keys. You need to test whether it is a correct binary
//search tree. Note that there can be duplicate integers in the tree, and this is allowed. The definition of
//the binary search tree in such case is the following: for any node of the tree, if its key is 𝑥, then for any
//node in its left subtree its key must be strictly less than 𝑥, and for any node in its right subtree its key
//must be greater than or equal to 𝑥. In other words, smaller elements are to the left, bigger elements
//are to the right, and duplicates are always to the right. You need to check whether the given binary
//tree structure satisfies this condition. You are guaranteed that the input contains a valid binary tree.
//That is, it is a tree, and each node has at most two children.
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
struct Node {
	lli key;
	lli left;
	lli right;

	Node(): key(0), left(-1), right(-1) {}

	Node(lli key_, lli left_, lli right_): key(key_), left(left_), right(right_) {}
};


bool backtracking(int n, vector<Node>& tree, lli min, lli max) {
	if (n == -1)
		return true;


	if (tree[n].key < min || tree[n].key > max)
		return false;

	return backtracking(tree[n].left, tree, min, tree[n].key - 1) && backtracking(tree[n].right, tree, tree[n].key, max);
}

bool isBinarySearchTree(vector<Node>& tree) {
	
	if (backtracking(0, tree, INT_MIN, INT_MAX))
		return true;

	return false;
}


void solve() {
	int n;
	cin >> n;

	if (n == 0) {
		cout << "CORRECT" << el;
		return;
	}
	
	vector<Node> tree;
	for(int i = 0; i < n; ++i) {
		Node node;
		cin >> node.key >> node.left >> node.right;

		tree.push_back(node);
	}

	if (isBinarySearchTree(tree))
		cout << "CORRECT" << el;
	else
		cout << "INCORRECT" << el;
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

