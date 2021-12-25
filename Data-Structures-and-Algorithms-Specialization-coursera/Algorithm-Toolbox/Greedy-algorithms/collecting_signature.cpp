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
	cin >> n;
	vector<pair<int, int>> vp(n);

	for(pair<int, int>& i : vp)
		cin >> i.first >> i.second;

	sort(vp.begin(), vp.end(), [&](pair<int, int> x, pair<int, int> y){
			if (x.first < y.first) return true;
			else if (x.first == y.first && x.second < y.second) return true;
			else return false;
			});

	int walk = 0;
	vector<int> res;
	pair<int, int> uni = vp[0];

	while (true)
	{
		while (walk < n - 1 && uni.second >= vp[walk + 1].first)
		{
			walk++;
			uni.first = max(uni.first, vp[walk].first);
			uni.second = min(uni.second, vp[walk].second);
		}
		res.push_back(uni.first);
		if (walk == n - 1)
			break;
		uni = vp[++walk];
	}

	cout << res.size() << '\n';
	for(int i : res)
		cout << i << ' ';
	cout << '\n';
}


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

