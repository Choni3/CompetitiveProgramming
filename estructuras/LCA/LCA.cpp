int depth[N], st[N][19];
void build() {
	for(int i=1 ; i<19 ; i++) {
		for(int j = 0 ; j<n ; j++) {
			st[j][i] = st[st[j][i-1]][i-1];
		}
	}
}
int LCA(int u, int v) {
	if(depth[u]>depth[v])swap(u,v);
	int r = depth[v]-depth[u];
	for(int i=logN ; i>=0 ; i--) {
		if(r>=(1<<i)){
			r-=(1<<i);
			v=st[v][i];
		}
	}
	if(u==v)return u;
	for(int i=logN ; i>=0 ; i--) {
		if(st[u][i]!=st[v][i]){
			u=st[u][i];
			v=st[v][i];
		}
	}
	return st[u][0];
}
void dfs(){
	//process st[u][0] -- parents
	//st[root][0] = root
}
