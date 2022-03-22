//============================Task===========================================
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
double distance(pair<lli, lli> p1, pair<lli, lli> p2)
{
	return sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second));
}

double find_closest_distance(vector<pair<lli, lli>> points, int l, int r)
{
	if (l >= r)
		return numeric_limits<double>::max();
	
	int mid = l + (r - l) / 2;
	double left_distance = find_closest_distance(points, l, mid);
	double right_distance = find_closest_distance(points, mid + 1, r);
	double d = min(left_distance, right_distance);
	int a = 0; 
	int b = 0;

	double mid_x = 0;
	for(int i = l; i <= r; ++i)
		mid_x += points[i].first;
	mid_x = mid_x / (r - l + 1);

	vector<pair<lli, lli>> mid_elements;
	for(int i = l; i <= r; ++i)
		if (abs(points[i].first - mid_x) < d)
			mid_elements.push_back(points[i]);

	sort(mid_elements.begin(), mid_elements.end(), [&](pair<lli, lli>& p1, pair<lli, lli>& p2){
			return p1.second <= p2.second;
			});

	for(int i = 0; i < mid_elements.size(); ++i)
		for(int j = i + 1; j < min<int>(i + 8, mid_elements.size()); ++j)
		{
			if (mid_elements[j].second - mid_elements[i].second > d)
				break;
			d = min(d, distance(mid_elements[i], mid_elements[j]));
		}

	return d;
}

void solve()
{
	int n;
	cin >> n;
	vector<pair<lli, lli>> points(n);
	for(auto& i : points)
		cin >> i.first >> i.second;

	sort(points.begin(), points.end(), [&](pair<lli, lli>& p1, pair<lli, lli>& p2){
			return p1.first <= p2.first;
			});

	cout << fixed << setprecision(4) << find_closest_distance(points, 0, points.size() - 1) << el;
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

