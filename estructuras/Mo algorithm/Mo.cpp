
struct query{
	int id,l,r,lca;
	query(){}
	query(const int _id, const int _l, const int _r,const int _lca) {
		id = _id, l = _l, r = _r, lca = _lca;
	}
	bool operator<(query o)const {
		if((l/block_size)!=(o.l/block_size))return l<o.l;
		if((l/block_size)%2==1)return r>o.r;
		else return r<o.r;
	}
};

vector<query>queries;
int ans;

void add(int pos) {
	//process ans with pos
}

void remov(int pos) {
	//process ans without pos
}

void doit() {
	//push_back queries
	block_size = sqrt(q);
	sort(queries.begin(),queries.end());
	int cur_l = 0;
	int cur_r = -1;
	vector<ll>answers(q);
	for(query q : queries) {
		while(cur_l>q.l) {
			cur_l--;
			add(cur_l);
		}
		while(cur_r<q.r) {
			cur_r++;
			add(cur_r);
		}
		while(cur_l<q.l) {
			remov(cur_l);
			cur_l++;
		}
		while(cur_r>q.r) {
			remov(cur_r);
			cur_r--;
		}
		answers[q.id] = ans;
	}
}
