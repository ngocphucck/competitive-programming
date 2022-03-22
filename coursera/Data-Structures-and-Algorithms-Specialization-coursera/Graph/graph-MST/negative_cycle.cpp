//============================Task===========================================
//Given an directed graph with possibly negative edge weights and with 𝑛 vertices and 𝑚 edges, check
//whether it contains a cycle of negative weight.
//============================Libraries and namespaces=======================
#include <algorithm>
#include <bits/stdc++.h>
#include <cctype>
#include <cmath>
#include <functional>
#include <iomanip>
#include <ios>
#include <limits>
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
struct Edge {
	int x, y, w;
};


bool checkNegativeCycle(vector<Edge>& edges, int n, int s, vector<int>& dist) {
	dist[s] = 0;
	int flag = -1;

	for(int i = 0; i < n - 1; ++i) {
		flag = -1;
		for(auto edge: edges) {
			if (dist[edge.x] != numeric_limits<int>::max() && dist[edge.x] + edge.w < dist[edge.y]) {
				dist[edge.y] = dist[edge.x] + edge.w;
				flag = 0;
			}
		}
	}

	if (flag == 0)
		return true;
	return false;
}



int checkDisconnectedGraph(vector<Edge>& edges, int n) {
	vector<int> dist(n, numeric_limits<int>::max());
	vector<bool> visited(n, false);
	
	int ans = 0;

	for(int i = 0; i < n; ++i) 
		if (visited[i] == false) {
			if (checkNegativeCycle(edges, n, i, dist)) 
			{
				ans = 1;
				break;
			}

			for(int j = 0; j < n; ++j) {
				if (dist[j] < numeric_limits<int>::max())
					visited[j] = true;
			}

		}

	return ans;
}


void solve() {
	int n, m;
	cin >> n >> m;
	vector<Edge> edges;

	for(int i = 0; i < m; ++i) {
		Edge edge;
		cin >> edge.x >> edge.y >> edge.w;
		edges.push_back(edge);
	}

	cout << checkDisconnectedGraph(edges, n) << el;
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

