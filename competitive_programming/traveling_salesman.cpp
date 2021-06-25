#include <algorithm>
#include <bits/stdc++.h>
#include <cctype>
#include <climits>
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

void travel(int i, int** graph, vector<int>& path, vector<int>& best_path, vector<bool>& free, vector<int>& path_cost, int& min_cost)
{
	forbe(j, 2, best_path.size())	
	{
		if (free[j - 1] && graph[path[i - 1] - 1][j - 1] < INT_MAX)
		{
			path[i] = j;
			path_cost[i] = path_cost[i - 1] + graph[path[i - 1] - 1][j - 1];

			if (path_cost[i] < min_cost)
			{
				if (i == best_path.size() - 1)
				{
					int cost = path_cost[i] + graph[path[i] - 1][0];
					if (cost < min_cost)
					{
						min_cost = cost;
						best_path = path;
					}
				}

				else
				{
					free[j - 1] = false;
					travel(i + 1, graph, path, best_path, free, path_cost, min_cost);
					free[j - 1] = true;
				}
			}
		}
	}
}


void solve()
{
	int n, m;
	cin >> n >> m;

	int** graph = new int*[m];
	fore(i, m - 1)
	{
		graph[i] = new int[m];
		fore(j, m - 1)
		{
			if (i == j)
				graph[i][j] = 0;
			else
				graph[i][j] = INT_MAX;
		}
	}

	fore(i, m - 1)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a - 1][b - 1] = c;
		graph[b - 1][a - 1] = c;
	}

	vector<int> path(n);
	vector<int> best_path(n);
	vector<bool> free(n, true);
	vector<int> path_cost(n);
	int min_cost = INT_MAX;
	path[0] = 1;
	free[0] = false;
	path_cost[0] = 0;

	travel(1, graph, path, best_path, free, path_cost, min_cost);

	fore(i, n - 1)
		cout << path[i] << " -> ";
	cout << path[0] << '\n';
	cout << "Cost: " << min_cost;
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

