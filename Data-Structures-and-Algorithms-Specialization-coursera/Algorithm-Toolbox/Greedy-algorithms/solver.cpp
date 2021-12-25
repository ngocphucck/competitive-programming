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


/* CONST*/
const int MOD=1e9 + 7;


/* DTYPE */
typedef long long int lli;
typedef long int li;
typedef short int si;
typedef vector<lli> vlli;


/* ARRAY */
#define sum(a)     ( accumulate ((a).begin(), (a).end(), 0ll) )
#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin() )
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin() )


/* LOOP */
#define fore(i,e) for(__typeof(e) i = 0; i < e; ++i)
#define fores(i,e,s) for(__typeof(e) i = 0; i < e; i+=s)
#define forbe(i,b,e) for(__typeof(e) i = b; i < e; i++)
#define forbes(i,b,e,s) for(__typeof(e) i = b; i < e; i+=s)
#define rforb(i,b) for(int i = b-1; i >= 0; --i)
#define rforbe(i, b, e) for(int i=b-1; i>=e; --i)


/* STRING */
typedef vector<string> vs;

void low_str(string& str){fore(i, str.length()) str[i]=tolower(str[i]);}
void up_str(string& str){fore(i, str.length()) str[i]=toupper(str[i]);}
template <typename T> string num_to_str(T num) {ostringstream ostr; ostr << num; return ostr.str();}
string rev_str(string str) {reverse(str.begin(), str.end()); return str;}


/* DEBUG */
#define dbs(x) cerr<<#x<<" = "<<x<<endl
#define dbf(x) cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<endl


void solve()
{
	int n;
	int k;
	cin >> n >> k;
	vector<lli> v(n);
	for(lli& i : v)
		cin >> i;

	sort(v.begin(), v.end());
	int neg = 0;

	fore(i, n)
		if (v[i] <= 0)
			neg++;
	int pos = n - neg;
	lli res = 0;
	
	if (abs(v[0]) < abs(v[n-1]))
	{
		int idx;
		if (neg % k == 0)
			idx = neg;
		else 
			idx = min<lli>(n, neg + k - neg % k);
		fore(i, idx)
		{
			if (i % k == 0 )
				res += abs(v[i]) * 2;
		}
		if (neg % k != 0 && pos > 0)
			res += abs(v[idx - 1]) * 2;
		forbe(i, idx, n)
		{
			if (i == n - 1 && (i-idx+1) % k == 0)
				res += abs(v[i]);
			else if (i == n - 1 && (i - idx + 1) != 0)
				res -= abs(v[i]);
			else if ((i-idx+1) % k == 0)
				res += abs(v[i]) * 2;
		}
	}

	else
	{
		sort(v.begin(), v.end(), greater<lli>());
		int idx;
		if (pos % k == 0)
			idx = pos;
		else 
			idx = min<lli>(n, pos + k - pos % k);
		fore(i, idx)
		{
			if (i % k == 0)
				res += abs(v[i]) * 2;
		}
		if (pos % k != 0 && neg > 0)
			res += abs(v[idx - 1]) * 2;
		forbe(i, idx, n)
		{
			if (i == n - 1 && (i - idx + 1) % k != 0)
				res += abs(v[i]);
			else if (i == n - 1 && (i - idx + 1) % k == 0)
				res -= abs(v[i]);
			else if ((i-idx+1) % k == 0)
				res += abs(v[i]) * 2;
		}
	}

	cout << res << '\n';
}


int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	bool multi_input = true;

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

