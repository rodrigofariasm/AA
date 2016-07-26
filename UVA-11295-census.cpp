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

int A[510][510];
pair<int, int> tree[510][2500];


pair<int, int> merge(pair<int, int> l, pair<int, int> r){
	return make_pair(max(l.first, r.first), min(l.second, r.second));
}

void build(int tidx, int n, int L, int R){
	int mid = (L+R)/2;
	if(L == R){
		tree[tidx][n].first = tree[tidx][n].second  = A[tidx-1][L-1];
		return;
	}
	build(tidx, n << 1, L, mid);
	build(tidx, (n << 1) +1, mid+1, R);
	pair<int, int> l = tree[tidx][n<<1];
	pair<int, int> r = tree[tidx][(n<<1)+1];
	tree[tidx][n].first = max(l.first, r.first);
	tree[tidx][n].second = min(l.second, r.second);
}

pair<int, int>  query(int tidx, int n, int i, int j, int L, int R){
	if(i > R || j < L){
		return make_pair((1 << 31), (1 << 30));
	}
	if(L >= i && R <= j) return tree[tidx][n];
	pair<int, int> l = query(tidx, n*2, i, j , L, (L+R)/2);
	pair<int, int> r = query(tidx, n*2+1,i, j,  (L+R)/2 +1, R);
	return merge(l, r);
}

void update(int tidx, int n, int idx, int value, int l, int r){
  if(idx < l || idx > r) return;
	if(l == r){
	  tree[tidx][n].first = tree[tidx][n].second = value;
		return;
  }
	update(tidx, n << 1,     idx, value, l, (l+r)/2);
	update(tidx, (n << 1)+1, idx, value, (l+r)/2+1, r);
	tree[tidx][n] = merge(tree[tidx][n<<1] , tree[tidx][(n<<1)+1]);
}

int main(){
		int n, q, a, x1, x2, y1, y2;
		char op;
		cin >> n;

		REP(i, n){
			REP(j, n){
					scanf("%d", &A[i][j]);
			}
		}
		for(int i = 1; i <= n; i++){
			build(i, 1, 1, n);
		}

		cin >> q;
		int maximo, minimo;

		REP(i, q){
			cin >> op;
			if(op == 'q'){
				maximo = (1 << 31); minimo = (1 << 30);
				cin >> x1 >> y1 >> x2 >> y2;
				pair<int, int> aux;
				for(int j = x1; j<= x2; j++){
					aux = query(j, 1, y1, y2, 1, n);
		//			DEBUG(aux.first);
	//				DEBUG(aux.second);
					maximo = max(aux.first, maximo);
					minimo = min(aux.second, minimo);
				}
				printf("%d %d\n", maximo, minimo);
			}else{
				cin >> x1 >> x2 >> y1;
				update(x1, 1, x2, y1, 1, n);
			}
		}
		return 0;
}
