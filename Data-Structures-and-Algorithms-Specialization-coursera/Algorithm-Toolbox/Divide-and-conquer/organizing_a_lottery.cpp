//============================Task===========================================
//You are given a set of points on a line and a set of segments on a line. The goal is to compute, for
//each point, the number of segments that contain this point.
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
void solve()
{
	int s, p;
	cin >> s >> p;
	vector<int> start_points(s);
	vector<int> end_points(s);
	vector<int> points(p);

	for(int i = 0; i < s; ++i)
		cin >> start_points[i] >> end_points[i];
	for(int& i : points)
		cin >> i;

	vector<pair<int, int>> combined;

	for(int i : start_points)
		combined.push_back({i, 0});
	for(int i : points)
		combined.push_back({i, 1});
	for(int i : end_points)
		combined.push_back({i, 2});

	unordered_map<int, int> m;
	sort(combined.begin(), combined.end(), [&](pair<int, int> a, pair<int, int> b){
			if (a.first == b.first)
				return a.second < b.second;
			return a.first < b.first;
			});

	int count = 0;

	for(auto& i : combined)
		if (i.second == 0)
			count++;
		else if (i.second == 2)
			count--;
		else
			m[i.first] = count;

	for(int& i : points)
		cout << m[i] << " ";
	cout << el;
}

//===========================Main=========================================
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	bool multi_input = false;

	if (multi_input)
	{
		int t = 1;
		cin >> t;

		while(t--)
		{
			solve();
		}
	}
	else
	{
		solve();

	}

	cerr << "\nTime taken: " << (float) clock() / CLOCKS_PER_SEC << " seconds" << endl;
}

