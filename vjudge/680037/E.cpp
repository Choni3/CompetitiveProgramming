/**
 * @tags dp
 * @idea
 *      - the idea here is defining a dp based on the time that has passed
 *      - dp(t) and precomputing the moments where one should start going to some specific fishing rod
 * 		- this works but has problems distinguishing if we are at the center at that time or at some fishing rod
 * 		- this can be solved if we add one parameter indicating if we are on the center or not
 * 		- dp(t, 0) = max(dp(t + 1, 0), dp(t1, 1) + 1) -> where t1 is some fishing rod that i can get in less than (t1 - t) time
 * 		- dp(t, 1) = max(dp(t2, 1) + 1, dp(t + distance to the center)) -> t2 is next time the same fishing rod is bitten again
 * @complexity
 * O(n)
**/
#include <bits/stdc++.h>
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define sz(A) int(A.size())
#define all(A) begin(A),end(A)
#define FIFO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define RAYA cerr << " =========== " << endl
#define DBG(x) cerr << #x << " = " << (x) << endl
#define DBGY(x) cerr << #x << " = " << (x) << ", "
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<pair<ll,ll>> vll;
typedef vector<pair<int,int>> vii;
template <typename T>
ostream & operator <<(ostream &os, const vector<T>&v) {
	os << "[";
	for(int i = 0; i < v.size(); i++) {
		if(i > 0) os << ",";
		os << v[i];
	}
	return os << "]";

}
const int N = 200015;
int dp[N][2];
vi adj[N];
int nxta[N];
vi a, d;
// a -> timing
// d -> distance per timing
vi difs[N];
int n, t;
int dpp(int pos, int center) {
	if(dp[pos][center] != -1) return dp[pos][center];
	if(pos > t) return 0;
	int ans = 0;
	if(center == 0) {
		ans = max(ans, dpp(pos + 1, center));
		for(auto e : adj[pos]) {
			ans = max(ans, dpp(e, 1) + 1);
		}
	}
	else {
		if(nxta[pos] != -1) ans = max(ans, dpp(nxta[pos], 1) + 1);
		ans = max(ans, dpp(pos + d[a[pos]], 0));
	}
	return dp[pos][center] = ans;
}
int main() {
	FIFO;
	memset(nxta, -1, sizeof(nxta));
	memset(dp, -1, sizeof(dp));
	
	cin >> t;
	
	cin >> n;
	a.resize(t + 1);
	d.resize(n);
	for(int i = 1; i <= t; i++) {
		cin >> a[i];
		a[i]--;
		difs[a[i]].pb(i);
	}
	for(int i = 0; i < n; i++) {
		cin >> d[i];
	}
	for(int i = 1; i <= t; i++) {
		int x = d[a[i]];
		int l = i - x;
		int r = i;
		if(l < 0) continue;
		adj[l].pb(r);
	}

	for(int i = 0; i < n; i++) {
		if(difs[i].size() < 2) continue;
		for(int j = 0; j + 1 < difs[i].size(); j++) {
			nxta[difs[i][j]] = difs[i][j + 1];
		}
	}
	cout << dpp(0, 0) << "\n";
	return 0;
}