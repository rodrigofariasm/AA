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
int n, q;
vector<int> arr;
vector<pair<int, int> > tree;

pair<int, int> merge(pair<int, int> n1, pair<int, int> n2){
	int a, b;
	if(n2.first > n1.first){
		a = n2.first;
		if(n2.second > n1.first){
			b = n2.second;
		}else{
			b = n1.first;
		}
	}
	else if(n2.first > n1.second){
		a = n1.first;
		b = n2.first;
	}else{
		return n1;
	}
	return make_pair(a, b);
}

void build(int node, int L, int R){
	if(L == R) tree[node] = make_pair(arr[L-1], -1);
	else{
		build(node << 1, L, (L+R)/2);
		build((node << 1) + 1, (L+R)/2 + 1, R);
		tree[node] = merge(tree[node<<1], tree[(node<<1)+1]);

	}
}

void update(int node, int idx, int val, int L, int R){
	if(L == R){
		tree[node] = make_pair(val, -1);
	}else{
		if(idx <= (L+R)/2){
			update(node << 1, idx, val, L, (L+R)/2);
		}else{
			update((node << 1)+1, idx, val, (L+R)/2+1, R);
		}

		tree[node] = merge(tree[node<<1], tree[(node<<1)+1]);
	}
}

pair<int, int> query(int node, int x, int y, int L, int R){
	if(R < x || L > y) return make_pair(-1, -1);
	else if(x <= L && R <= y){
		return tree[node];
	}else{
		return merge(query(node << 1, x, y, L, (L+R)/2),
		 	query((node << 1)+1, x, y, (L+R)/2+1, R));
	}

}

int main(){
	pair<int, int> result;
	cin >> n;
	int a;
	REP(i, n){
		cin >> a;
		arr.push_back(a);
	}
	tree.assign(n*4, make_pair(-1,-1));
	build(1,1, n);
	cin>> q;
	char OP;
	int x, y;
	REP(i, q){
		cin >> OP >> x >> y;
		if(OP == 'U'){
			update(1, x, y, 1, n);
		}else{
			result = query(1, x, y, 1, n);
			printf("%d\n", result.first + result.second);
		}
	}

	return 0;
}
