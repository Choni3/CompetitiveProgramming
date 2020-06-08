// UVA INTROSPECTIVE CACHING
#include <bits/stdc++.h>
#define pb(x) push_back(x)
const int N = 100004;
int sig[N], last[N];
int caching(){
	FIFO;
	int c, n, a;
	while(cin >> c >> n >> a) {
		for(int i = 0; i < n; i++) {
			last[i] = -1;
		}
		for(int i = 0; i < a; i++) {
			sig[i] = 0;
		}
		vi v;
		for(int i = 0; i < a; i++) {
			int x;
			cin >> x;
			v.pb(x);
			if(last[x] != -1) {
				sig[last[x]] = i;
			}
			last[x] = i;
		}
		for(int i = 0; i < n; i++) {
			if(last[i] != -1)sig[last[i]] = 1000000;
		}
		int cnt = 0;
		set<int>s;
		for(int i = 0; i < a; i++) {
			if(s.find(i) != s.end()) {
				s.erase(i);
				s.insert(sig[i]);
				continue;
			}
			if(s.size() == c) {
				auto it = s.end();
				it--, cnt++;
				s.erase(*it), s.insert(sig[i]);
			}
			else{
				cnt++;
				s.insert(sig[i]);
			}
			
		}
		return cnt;
}
