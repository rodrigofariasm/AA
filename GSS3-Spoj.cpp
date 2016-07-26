#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <cctype>
#include <utility>
#include <algorithm>
#include <math.h>

using namespace std;
#define ll long long
#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define DEBUG(x) { cout << #x << " = " << x << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }
#define NINF -100001
struct node {
	//Soma completa do interval/ soma maxima no intervalo/
	//soma maximo começando pela esquera/ mesma coisa pela direita
	int c, m, e, d;
};
vector<node> A;
vector<node> tree;

node merge(node l, node r){
	node aux;
	aux.c = l.c + r.c;
	aux.e = max(l.e, l.c + r.e);
	aux.d = max(r.d, r.c + l.d);
	aux.m = max(max(r.m, l.d + r.e)   , max(max(aux.c, l.m), max(aux.d, aux.e)));
	return aux;
}

void build(int n, int L, int R){
	int mid = (L+R)/2;
	if(L == R){
		tree[n] = A[L-1];
		return;
	}
	build(n << 1, L, mid);
	build((n << 1) +1, mid+1, R);
	node l = tree[n<<1];
	node r = tree[(n<<1)+1];
	tree[n] = merge(l, r);
}
void debug(int n){
	for(int i = 1; i<= n*2-1; i++){
		DEBUG(tree[i].c);
		DEBUG(tree[i].m);
		DEBUG(tree[i].e);
		DEBUG(tree[i].d);
	}
}

node query(int n, int i, int j, int L, int R){
	if(i > R || j < L){
		node a;
		a.c = 0; a.m = NINF; a.e=NINF; a.d= NINF;
		return a;
	}
	if(L >= i && R <= j) return tree[n];
	node l = query(n*2, i, j , L, (L+R)/2);
	node r = query(n*2+1,i, j,  (L+R)/2 +1, R);
	return merge(l, r);
}

void update(int n, int idx, int value, int l, int r){
  if(idx < l || idx > r) return;
	if(l == r){
	  node aux;
		aux.c = value; aux.m = value; aux.e = value; aux.d = value;
		tree[n] = aux;
		return;
  }

	update(n << 1, idx, value, l, (l+r)/2);
	update((n << 1)+1, idx, value, (l+r)/2+1, r);
	tree[n] = merge(tree[n<<1] , tree[(n<<1)+1]);
}

int main(){
		int n, q, a, op, x, y;
		cin >> n;
		node aux;
		tree.assign(4*n, aux);

		REP(i, n){
			cin >> a;
			aux.c = a;			aux.m = a;			aux.e = a;			aux.d = a;
			A.push_back(aux);
		}
		build(1, 1, n);
		cin >> q;

		REP(i, q){
			cin >> op >> x >> y;
			if(op){
				cout << query(1, x, y, 1, n).m	 << endl;
			}else{
				update(1, x, y, 1, n);
			}
		}

}
