const int N = 1005;
vi adj[N];
int pl[N], pr[N];
bool vis[N], visR[N];// Lado 1, Lado 2
int n, m; // n --> L, m --> R

bool dfs(int x) {
	if(vis[x])return false;
	vis[x] = 1;
	for(auto y : adj[x]) {
		visR[y] = 1;
		if(pr[y] == -1 || dfs(pr[y])) {
			pl[x] = y;
			pr[y] = x;
			return true;
		}
	}
	return false;
}

void greedyinit(){
	memset(pl, -1, sizeof(pl));
	memset(pr, -1, sizeof(pr));
	for(int i = 0; i < n; i++) {
		if(pl[i] == -1) {
			for(auto j : adj[i]) {
				if(pr[j] == -1) {
					pl[i] = j;
					pr[j] = i;
					break;
				}
			}
		}
	}
}

void FordFulkerson() {
	bool found = 1;
	while(found) {
		found = 0;
		memset(vis, 0, sizeof(vis));
		for(int i = 0; i < n; i++) {
			if(pl[i] == -1) {
				if(dfs(i)) {
					found = 1;
					break;
				}
			}
		}
	}
}

void Kuhn() {
	for(int i = 0; i < n; i++) {
		if(pl[i] == -1){
			memset(vis, 0, sizeof(vis));
			dfs(i);
		}
	}
}
