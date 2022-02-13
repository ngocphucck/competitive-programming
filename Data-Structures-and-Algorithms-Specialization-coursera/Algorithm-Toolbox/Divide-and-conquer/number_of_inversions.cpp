//============================Task===========================================
//The goal in this problem is to count the number of inversions of a given sequence.
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

void merge(vector<int>& arr, int l, int m, int r, int& num_inversions)
{
	vector<int> left_arr(m - l + 1);
	vector<int> right_arr(r - m);
	for(int i = 0; i < m - l + 1; ++i)
		left_arr[i] = arr[i + l];
	for(int i = 0; i < r - m; ++i)
		right_arr[i] = arr[i + m + 1];

	int a = 0;
	int b = 0;

	for(int i = l; i <= r; ++i)
		if(a == m - l + 1)
			arr[i] = right_arr[b++];

		else if (b == r - m)
			arr[i] = left_arr[a++];
		
		else
		{
			if (left_arr[a] <= right_arr[b])
				arr[i] = left_arr[a++];
			else
			{
				arr[i] = right_arr[b++];
				num_inversions += left_arr.size() - a;
			}
		}
}

void merge_sort(vector<int>& arr, int l, int r, int& num_inversions)
{
	if (l >= r)
		return;
	else
	{
		int m = l + (r - l) / 2;
		merge_sort(arr, l, m, num_inversions);
		merge_sort(arr, m + 1, r, num_inversions);
		merge(arr, l, m, r, num_inversions);
	}
}

void solve()
{
	int n;
	cin >> n;
	vector<int> arr(n);

	for(int& i : arr)
		cin >> i;

	int res = 0;
	merge_sort(arr, 0, arr.size() - 1, res);

	cout << res << el;
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

