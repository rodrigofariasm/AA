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

vector<int> tree, arr;

void build(int node, int L, int R){
	if(L == R){
		 tree[node] = arr[L-1];
		 return;
	}
	build(node << 1, L, (L+R)/2);
	build((node << 1) + 1, (L+R)/2 + 1, R);
	tree[node] = max(tree[node<<1], tree[(node<<1)+1]);
}

void update(int node, int idx, int val, int L, int R){
	if ( L > idx || R < idx)   return;
	if(L == R){
		tree[node] = val;
		return;
	}
	update(node << 1, idx, val, L, (L+R)/2);
	update((node << 1)+1, idx, val, (L+R)/2+1, R);

	tree[node] = max(tree[node<<1], tree[(node<<1)+1]);

}

int query(int node, int x, int y, int L, int R){
	if(R < x || L > y) return 0;
	if(L >= x && R <= y){
		return tree[node];
	}
	int p1 = query(node << 1, x, y, L, (L+R)/2);
	int p2 = query((node << 1) + 1, x, y, (L+R)/2+1, R);
	return max(p1,p2);
}

int main(){
	ios_base::sync_with_stdio(false);
	int t,a, x, y, n, q, baloons;
	scanf ("%d", &t);
	REP(test, t){
		printf ("Testcase %d:\n", test);
		scanf ("%d%d", &n, &baloons);
		arr.assign(n, 0);
		tree.assign(n*4, 0);
		REP(i, n){
			scanf ("%d", &arr[i]);
		}

		build(1,1, n);
		scanf ("%d", &q);
		char OP[3];
		REP(i, q){
			scanf ("%s", OP);
			if(OP[0] == 'A'){
				scanf ("%d", &x);
				baloons += x;
			}else{
			scanf ("%d%d", &x, &y);
				if(OP[0] == 'B'){
					update(1, x+1, y, 1, n);
				}else{
					printf ("%d\n", abs(query(1, x+1, y+1, 1, n) - baloons));
				}
			}
		}
		printf ("\n");
	}
	return 0;
}
