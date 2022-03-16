//============================Task===========================================
//You have a program which is parallelized and uses 𝑛 independent threads to process the given list of 𝑚
//jobs. Threads take jobs in the order they are given in the input. If there is a free thread, it immediately
//takes the next job from the list. If a thread has started processing a job, it doesn’t interrupt or stop
//until it finishes processing the job. If several threads try to take jobs from the list simultaneously, the
//thread with smaller index takes the job. For each job you know exactly how long will it take any thread
//to process this job, and this time is the same for all the threads. You need to determine for each job
//which thread will process it and when will it start processing.
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
int parent(int i)
{
	return (i - 1) / 2;
}

int left_child(int i)
{
	return 2 * i + 1;
}

int right_child(int i)
{
	return 2 * i + 2;
}

void shift_down(vector<int>& v, int i, vector<lli>& ending_time)
{
	int min_id = i;
	if (left_child(i) < v.size() && ending_time[v[left_child(i)]] <= ending_time[v[min_id]])
	{
		if (ending_time[v[left_child(i)]] < ending_time[v[min_id]] || v[left_child(i)] < v[min_id])
			min_id = left_child(i);
	}

	if (right_child(i) < v.size() && ending_time[v[right_child(i)]] <= ending_time[v[min_id]])
	{
		if (ending_time[v[right_child(i)]] < ending_time[v[min_id]] || v[right_child(i)] < v[min_id])
			min_id = right_child(i);
	}

	if (min_id != i)
	{
		swap(v[min_id], v[i]);
		shift_down(v, min_id, ending_time);
	}
}

void build_heap(vector<int>& v, vector<lli>& ending_time)
{
	for(int i = v.size() / 2; i >= 0; i--)
		shift_down(v, i, ending_time);
}


void solve()
{
	int n, m;
	cin >> n >> m;

	vector<lli> t(m);
	for(lli& i : t)
		cin >> i;
	
	vector<int> heap(n);
	vector<lli> ending_time(n);
	for(int i = 0; i < n; ++i)
		heap[i] = i;
	
	for(int i = 0; i < min(n, m); ++i)
	{
		cout << i << " " << 0 << el;
		ending_time[i] = t[i];
	}

	if (n >= m)
		return;

	build_heap(heap, ending_time);

	for(int i = n; i < m; ++i)
	{
		cout << heap[0] << " " << ending_time[heap[0]] << el;
		ending_time[heap[0]] += t[i];
		shift_down(heap, 0, ending_time);
	}
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

