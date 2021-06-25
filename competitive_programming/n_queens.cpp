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
#include <vector>


using namespace std;


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
#define fore(i,e) for(__typeof(e) i = 0; i <= e; ++i)
#define fores(i,e,s) for(__typeof(e) i = 0; i <= e; i+=s)
#define forbe(i,b,e) for(__typeof(e) i = b; i <= e; i++)
#define forbes(i,b,e,s) for(__typeof(e) i = b; i <= e; i+=s)
#define rforb(i,b) for(int i = b; i >= 0; --i)
#define rforbe(i, b, e) for(int i=b; i>=e; --i)


/* STRING */
typedef vector<string> vs;

void low_str(string& str){fore(i, str.length()) str[i]=tolower(str[i]);}
void up_str(string& str){fore(i, str.length()) str[i]=toupper(str[i]);}
template <typename T> string num_to_str(T num) {ostringstream ostr; ostr << num; return ostr.str();}
string rev_str(string str) {reverse(str.begin(), str.end()); return str;}


/* DEBUG */
#define dbs(x) cerr<<#x<<" = "<<x<<endl
#define dbf(x) cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<endl


/*======================================================================================================*/

void print(vector<int> queens, int n)
{
	forbe(i, 0, n - 1)
	{
		forbe(j, 0, n - 1)
		{
			if (j == queens[i])
				cout << '*' << " ";
			else
				cout << '-' << " ";
		}
		cout << '\n';
	}
	cout << "\n\n\n";
}


void set_row(int i, int n, vector<int>& queens, vector<bool>& columns, vector<bool>& left_diagnoses, vector<bool>& right_diagnoses)
{
	forbe(j, 0, n - 1)
	{
		if (columns[j] && right_diagnoses[i + j] && left_diagnoses[i - j + n])
		{
			queens[i] = j;
			columns[j] = false;
			right_diagnoses[i + j] = false;
			left_diagnoses[i - j + n] = false;

			if (i == n - 1)
				print(queens, n);
			else
				set_row(i + 1, n, queens, columns, left_diagnoses, right_diagnoses);

			columns[j] = true;
			right_diagnoses[i + j] = true;
			left_diagnoses[i - j + n] = true;
		}
	}
}


void solve()
{
	int n;
	cin >> n;

	vector<int> queens(n);
	vector<bool> columns(n, true);
	vector<bool> left_diagnoses(2 * n + 1, true);
	vector<bool> right_diagnoses(2 * n + 1, true);

	set_row(0, n, queens, columns, left_diagnoses, right_diagnoses);
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

