//============================Task===========================================
//Find the maximum value of an arithmetic expression by specifying the order of applying its arithmetic
//operations using additional parentheses.
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
	string str;
	cin >> str;
	vector<int> nums;
	vector<char> signs;

	for(char i : str)
		if ('0' <= i && i <= '9')
			nums.push_back(i - '0');
		else
			signs.push_back(i);

	long long int max_arr[nums.size()][nums.size()];
	long long int min_arr[nums.size()][nums.size()];

	for(int i = 0; i < nums.size(); ++i)
		for(int j = 0; j < nums.size(); ++j)
		{
			max_arr[i][j] = numeric_limits<long long int>::min();
			min_arr[i][j] = numeric_limits<long long int>::max();
		}

	for(int i = 0; i < nums.size(); ++i)
	{
		max_arr[i][i] = nums[i];
		min_arr[i][i] = nums[i];
	}

	for(int k = 1; k < nums.size(); ++k)
		for(int i = 0; i < nums.size() - k; ++i)
		{
			int j = k + i;
			for(int s = i; s < j; ++s)
			{
				long long int min_left = min_arr[i][s];
				long long int min_right = min_arr[s+1][j];
				long long int max_left = max_arr[i][s];
				long long int max_right = max_arr[s+1][j];

				if (signs[s] == '+')
				{
					min_arr[i][j] = min(min_left + min_right, min_arr[i][j]);
					max_arr[i][j] = max(max_left + max_right, max_arr[i][j]);
				}
				else if (signs[s] == '-')
				{
					min_arr[i][j] = min(min_left - max_right, min_arr[i][j]);
					max_arr[i][j] = max(max_left - min_right, max_arr[i][j]);
				}
				else
				{
					min_arr[i][j] = min({min_left * min_right, min_left * max_right, max_left * min_right, max_left * max_right, min_arr[i][j]});
					max_arr[i][j] = max({min_left * min_right, min_left * max_right, max_left * min_right, max_left * max_right, max_arr[i][j]});
				}
			}
		}

	cout << max_arr[0][nums.size() - 1] << el;
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

