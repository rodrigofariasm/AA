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

#define N 100005
int n, b, q;
vector<int> arr;
vector<int> tree;

void build(int node, int L, int R){
	if(L == R){
		tree[node] = arr[L-1];
	}
	else{
		build(node << 1, L, (L+R)/2);
		build((node << 1) + 1, (L+R)/2 + 1, R);
		tree[node] = max(tree[node<<1], tree[(node<<1)+1]);

	}
}

void update(int node, int idx, int val, int L, int R){
	if(L == R){
		tree[node] = val;
	}else{
		if(idx <= (L+R)/2){
			update(node << 1, idx, val, L, (L+R)/2);
		}else{
			update((node << 1)+1, idx, val, (L+R)/2+1, R);
		}
		tree[node] = max(tree[node<<1], tree[(node<<1)+1]);
	}
}

int query(int node, int x, int y, int L, int R){
	if(R < x || L > y) return 0;
	else if(x <= L && R <= y){
		return tree[node];
	}else{
		return max(query(node << 1, x, y, L, (L+R)/2),
		 	query((node << 1)+1, x, y, (L+R)/2+1, R));
	}

}

int main(){
	
	}


	return 0;
}
