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
	int d[3];
};
vector<int> lazy;
vector<node> tree, A;

node merge(node l, node r){
	node aux;
	aux.d[0] = l.d[0] + r.d[0];
	aux.d[1] = l.d[1] + r.d[1];
	aux.d[2] = l.d[2] + r.d[2];
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

node query(int n, int i, int j, int L, int R){
	if(i > R || j < L){
		node a; a.d[0] = 0; a.d[1] = 0; a.d[2] = 0;
		return a;
	}
	if(lazy[n] != 0){
		node aux;
		aux.d[0] = tree[n].d[(lazy[n]%3 == 0 ? 0 : 3 - (lazy[n]%3))];
		aux.d[1] = tree[n].d[(lazy[n]%3 == 2 ? 2 : !(lazy[n]%3))];
		aux.d[2] = tree[n].d[2 - (lazy[n]) % 3];
		tree[n] = aux;
	      if(L != R)
        {
            lazy[n<<1] += lazy[n];         // Mark child as lazy
            lazy[(n<<1)+1] += lazy[n];    // Mark child as lazy
        }
        lazy[n] = 0;                 // Reset it
    }
	if(L >= i && R <= j) return tree[n];
	node l = query(n<<1, i, j , L, (L+R)/2);
	node r = query((n<<1)+1,i, j,  (L+R)/2 +1, R);
	return merge(l, r);
}

void update(int n, int i, int j,  int L, int R){
	if(lazy[n] != 0){
		node aux;
		aux.d[0] = tree[n].d[(lazy[n]%3 == 0 ? 0 : 3 - (lazy[n]%3))];
		aux.d[1] = tree[n].d[(lazy[n]%3 == 2 ? 2 : !(lazy[n]%3))];
		aux.d[2] = tree[n].d[2 - (lazy[n]) % 3];
		tree[n] = aux;
		if(L != R){
			lazy[n<<1]+= lazy[n];
			lazy[(n<<1)+1]+= lazy[n];
		}
		lazy[n] = 0;
	}
  if(j < L || i > R) return;
	if(L >= i && R <=j){
	  node aux;
		aux.d[0] = tree[n].d[2];
		aux.d[1] = tree[n].d[0];
		aux.d[2] = tree[n].d[1];
		tree[n] = aux;
		if(L != R){
			lazy[n<<1]++;
      lazy[(n<<1)+1]++;
		}
		return;
  }

	update(n << 1, i, j, L, (L+R)/2);
	update((n << 1)+1, i, j, (L+R)/2+1, R);
	tree[n] = merge(tree[n<<1] , tree[(n<<1)+1]);
}
void debug(int n){
	FOR(i,1, n*2-1){
		cout << tree[i].d[0] << " ";
	}
	cout << endl;
	FOR(i,1, n*2-1){
		cout << tree[i].d[1] << " ";
	}

	cout << endl;
	FOR(i,1, n*2-1){
		cout << tree[i].d[2] << " ";
	}
	cout << endl;
	FOR(i,1, n*2-1){
		cout << lazy[i] << " ";
	}
}
int main(){
		int n, q, a, op, x, y;
	  scanf("%d %d", &n, &q);
		node aux;
		tree.assign(4*n, aux); lazy.assign(4*n, 0);
		aux.d[0] = 1;
		aux.d[1] = 0;
		aux.d[2] = 0;
		REP(i, n) A.push_back(aux);

		build(1, 1, n);

		REP(i, q){
			scanf("%d %d %d", &op, &x, &y);
			if(op){
				printf("%d\n", query(1, x+1, y+1, 1, n).d[0]);
			//	debug(n);	cout << endl;
			}else{
				update(1, x+1, y+1, 1, n);
		//		debug(n);cout << endl;

			}
		}

}
