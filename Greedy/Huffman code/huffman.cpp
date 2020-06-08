#include <bits/stdc++.h>
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define sz(A) int(A.size())
#define FIFO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(A) begin(A),end(A)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<pair<ll,ll>> vll;
typedef vector<pair<int,int>> vii;
const int N = 500004;
int L[2 * N], R[2 * N];
ll total = 0;
vi ocur; //frecuencias de las letras
int n;
void dfs(int u, int depth) {
	bool can = 0;
	if(u < n) {
		total += 1LL * depth * ocur[u];
		return;
	}
	dfs(L[u], depth + 1);
	dfs(R[u], depth + 1);
}
void huffman() {
    priority_queue<pair<ll, ll>>q;
    int nodo = n;
    for(int i = 0; i < n; i++) {
        q.push(mp(-ocur[i], i));
    }
    for(int i = 0; i < 2 * n + 1; i++) {
        L[i] = 0;
        R[i] = 0;
    }
    while(q.size() != 2) {
        auto e = q.top();
        q.pop();
        auto f = q.top();
        q.pop();
        L[nodo] = (e.second);
        R[nodo] = (f.second);
        q.push(mp(e.first + f.first, nodo++));
    }
    L[nodo] = q.top().second;
    q.pop();
    R[nodo] = q.top().second;
    q.pop();
		
    dfs(nodo, 0);
}
