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
	lli a, b;
	cin >> a >> b;
	lli mul = a * b;
	while (b != 0)
	{
		a %= b;
		swap<lli>(a, b);
	}
	
	cout << mul / a << '\n';
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

