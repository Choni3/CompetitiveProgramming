#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define v1 2*nodo
#define v2 2*nodo+1
#define me (l+r)/2

const int N = 300005;

struct data{
	ll res, f1, f2;	
	data(){}
	data(ll _res, ll _f1, ll _f2) {
		res = _res, f1 = _f1, f2 = _f2;
	}
};

data tree[4*N];

void build(int nodo, int l, int r) {
	if(l == r) {
		tree[nodo].res = v[l];
		return;
	}
	build(v1, l, me);
	build(v2, me + 1, r);
	// + es cualquier operacion
	tree[nodo].res = (tree[v1].res + tree[v2].res);
}

void push(int nodo, int l, int r) {
	
	if(tree[nodo].lazy == 0) return;
	// update tree[nodo] a partir de la informacion lazy
	
	// si el nodo hijo no es una hoja
	if(l != r){
		// propagar info a los hijos
		tree[v1].lazy = f(tree[nodo].lazy);
 	}
	// limpiar el lazy del nodo
	tree[nodo].f1 = 0, tree[nodo].f2 = 0;
}

void update(int nodo, int l, int r, int lu, int ru) {
	push(nodo, l, r);
	if(l > ru || r < lu) return;
	
	if(l >= lu && r <= ru) {
		// update de los valores lazy
		tree[nodo].lazy = (something);
		push(nodo, l, r);
	}
	
	update(v1, l, me, lu, ru);
	update(v2, me+1, r, lu, ru);
	//colectar informacion de los hijos
	tree[nodo].res = (tree[v1].res + tree[v2].res);
}

ll query(int nodo, int l, int r, int lq, int rq) {
	//push al entrar a la frontera
	push(nodo, l, r);
	if(l > rq || r < lq) return 0;
	if(l >= lq && r <= rq)return tree[nodo].res;
	return (query(v1, l, me, lq, rq) + query(v2, me + 1, r, lq, rq));
}

