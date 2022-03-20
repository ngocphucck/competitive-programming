//============================Task===========================================
//Given 𝑛 points on a plane, connect them with segments of minimum total length such that there is a
//path between any two points.
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
const double INF = numeric_limits<double>::max();


struct Edge {
	double w = INF;
	int to;
};



double prim(vector<vector<double>>& adj_matrix) {
	double sum_weights = 0;
	vector<bool> selected(adj_matrix.size(), false);
	vector<Edge> min_edge(adj_matrix.size());
	min_edge[0].w = 0;

	for(int i = 0; i < adj_matrix.size(); ++i) {
		int v = -1;

		for(int j = 0; j < adj_matrix.size(); ++j) {
			if (!selected[j] && (v == -1 || min_edge[v].w > min_edge[j].w))
				v = j;
		}

		selected[v] = true;
		sum_weights += min_edge[v].w;

		for(int to = 0; to < adj_matrix.size(); ++to)
			if (adj_matrix[v][to] < min_edge[to].w)
				min_edge[to] = {adj_matrix[v][to], v};
	}

	return sum_weights;
}


void solve() {
	int n;
	cin >> n;
	vector<pair<double, double>> vp(n);
	for(auto& i : vp)
		cin >> i.first >> i.second;

	vector<vector<double>> adj_matrix(n, vector<double>(n, INF));
	for(int i = 0; i < n; ++i)
		for(int j = i + 1; j < n; ++j) {
			adj_matrix[i][j] = sqrt(pow(vp[i].first - vp[j].first, 2) + pow(vp[i].second - vp[j].second, 2));
			adj_matrix[j][i] = adj_matrix[i][j];
		}

	cout << std::setprecision(10) << prim(adj_matrix) << el;
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

