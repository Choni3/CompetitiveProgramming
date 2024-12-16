/**
 * @tags hashing strings ...
 * @idea
 *      - the idea in this problem is get for each letter a hashing of the string
 * 		- this hashing will work mapping the string to an array of zeros and ones for each letter
 * 		- one if the current letter is in that position, zero otherwise
 * 		- having this we can transform every subarray into 26 hashes
 * 		- now we can verify if two subarrays are isomorphic by comparing that we have the same set of 26 hashes for both subarrays
 * @complexity
 * O(n*26)
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
const int N = 200006;
ll hsh[30][N];
int mod = 998244353;
ll pot[N];
ll get_range(int l, int r, int i) {
	ll ans = (hsh[i][r + 1] - hsh[i][l] * pot[r - l + 1]) % mod;
	return (ans + mod) % mod;
}
int main() {
	FIFO;
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;


	pot[0] = 1;
	for(int i = 1; i < N; i++) {
		pot[i] = (pot[i - 1] * 3) % mod;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < 26; j++) {
			hsh[j][i] = hsh[j][i - 1] * 3;
			if(s[i - 1] - 'a' == j) hsh[j][i]++;
			hsh[j][i] %= mod;
		}
	}
	for(int i = 0; i < q; i++) {
		int x, y, l;
		cin >> x >> y >> l;
		x--, y--;
		int l1 = x, r1 = x + l - 1;
		int l2 = y, r2 = y + l - 1;
		vl v1, v2;

		for(int i = 0; i < 26; i++) {
			v1.pb(get_range(l1, r1, i));
			v2.pb(get_range(l2, r2, i));
		}
		sort(all(v1));
		sort(all(v2));
		cout << (v1 == v2 ? "YES" : "NO") << "\n";
	}
	return 0;

}