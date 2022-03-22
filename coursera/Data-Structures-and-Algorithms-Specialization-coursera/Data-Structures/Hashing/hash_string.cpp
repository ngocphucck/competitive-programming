//============================Task===========================================
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
struct Query {
	string type, str;
	size_t index;
};


class QueryProcessor {
	private:
		int numBucket;
		map<int, vector<string>> m;

		size_t hashFunction(const string& s) const {
			static const size_t multiplier = 263;
			static const size_t prime = 1000000007;
			unsigned long long hashValue = 0;

			for(int i = s.length() - 1; i >= 0; --i) {
				hashValue = (hashValue * multiplier + s[i]) % prime;
			}

			return hashValue % numBucket;
		}

	public:
		explicit QueryProcessor(int numBucket): numBucket(numBucket) {}

		Query readQuery() const {
			Query query;
			cin >> query.type;
			if (query.type != "check")
				cin >> query.str;
			else
				cin >> query.index;
			
			return query;
		}

		void writeSearchResult(bool wasFound) {
			if (wasFound)
				cout << "no" << el;
			else
				cout << "yes" << el;
		}

		void processQuery(const Query& query) {
			if (query.type == "check") {
				if (m.find(query.index) == m.end())
					cout << el;
				else {
					for(int i = m[query.index].size() - 1; i >= 0; --i)
						cout << m[query.index][i] << " ";
					cout << el;
				}
			}

			else if (query.type == "add") {
				if (find(m[hashFunction(query.str)].begin(), m[hashFunction(query.str)].end(), query.str) == m[hashFunction(query.str)].end())
					m[hashFunction(query.str)].push_back(query.str);
			}

			else if (query.type == "find") {
				writeSearchResult(find(m[hashFunction(query.str)].begin(), m[hashFunction(query.str)].end(), query.str) == m[hashFunction(query.str)].end());
			}

			else {
				auto iter = find(m[hashFunction(query.str)].begin(), m[hashFunction(query.str)].end(), query.str);
				if (iter != m[hashFunction(query.str)].end())
					m[hashFunction(query.str)].erase(iter);
			}
		}

		void processQueries() {
			int n;
			cin >> n;
			for(int i = 0; i < n; ++i)
				processQuery(readQuery());
		}

};


void solve() {
	int numBucket;
	cin >> numBucket;
	QueryProcessor queryProcessor = QueryProcessor(numBucket);
	queryProcessor.processQueries();
}

//===========================Main=========================================
int main() {

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	bool multi_input = false;

	if (multi_input) {
	
		int t = 1;
		cin >> t;

		while(t--)
		{
			solve();
		}
	}
	else
		solve();


	cerr << "\nTime taken: " << (float) clock() / CLOCKS_PER_SEC << " seconds" << endl;
}

