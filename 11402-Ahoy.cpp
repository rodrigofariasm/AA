#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <cctype>
#include <utility>
#include <bitset>
#include <algorithm>
#include <math.h>
#include <queue>

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

vector<int> tree;
vector<int> lazy;


void build(int n, int L, int R, int s, bitset<1024000> &set){
	int mid = (L+R)/2;
	if(L == R){
		tree[n] = set[s-L];
		return;
	}
	build(n << 1, L, mid, s, set);
	build((n << 1) +1, mid+1, R, s, set);
	int l = tree[n<<1];
	int r = tree[(n<<1)+1];
	tree[n] = l+r;
}

void propagate(int n, int L, int R){
	if(lazy[n] == 1){
		tree[n] = R-L+1;
		if(L!= R) lazy[(n<<1)+1] = lazy[(n<<1)] = 1;
	}else if(lazy[n] == 2){
		tree[n] = 0;
		if(L!= R) lazy[(n<<1)+1] = lazy[(n<<1)] = 2;
	}else{
		tree[n] =  (R-L+1) - tree[n];
		 if(L!=R){
				 if(lazy[n<<1] != 0) lazy[n<<1] = (lazy[n<<1] != 3) ? (lazy[n<<1] == 2)? 1:2: 0 ;
				 else lazy[n<<1] = 3;
				 if(lazy[(n<<1)+1]!=0) lazy[(n<<1)+1] = (lazy[(n<<1)+1] != 3)? (lazy[(n<<1)+1] == 2)? 1:2: 0;
				 else lazy[(n<<1)+1] = 3;
	   }
	}
	lazy[n]=0;
}
int query(int n, int i, int j, int L, int R){
	if(i > R || j < L){
		return 0;
	}
	if(lazy[n] != 0) propagate(n, L, R);
	if(L >= i && R <= j) return tree[n];
	int l = query(n<<1, i, j , L, (L+R)/2);
	int r = query((n<<1)+1,i, j,  (L+R)/2 +1, R);
	return l+r;
}

void update(int n, int i, int j,  int L, int R, int op){
	if(lazy[n] != 0) propagate(n, L, R);
  if(j < L || i > R) return;
	if(L >= i && R <=j){
		if(op == 1){
			tree[n] = R-L+1;
			if(L != R){
					lazy[n<<1] = lazy[(n<<1)+1] =(op);
			}
		}else if(op == 2){
			tree[n] = 0;
			if(L != R){
					lazy[n<<1] = lazy[(n<<1)+1] =(op);
			}
		}else{
			tree[n] = R-L+1 - tree[n];
			if(L != R){
				if(lazy[n<<1] != 0) lazy[n<<1] = (lazy[n<<1] != 3) ? (lazy[n<<1] == 2)? 1:2: 0 ;
				else lazy[n<<1] = 3;
				if(lazy[(n<<1)+1]!=0) lazy[(n<<1)+1] = (lazy[(n<<1)+1] != 3)? (lazy[(n<<1)+1] == 2)? 1:2: 0;
				else lazy[(n<<1)+1] = 3;
			}
		}
		return;
  }
	update(n << 1, i, j, L, (L+R)/2, op);
	update((n << 1)+1, i, j, (L+R)/2+1, R, op);
	tree[n] = tree[n<<1] + tree[(n<<1)+1];
}

void debug(int n){

}
int main(){
	int TC, p, q, rep, a, b;
	char op[3];
	string chain, s;
	scanf("%d", &TC);
	REP(tc, TC){
		printf("Case %d:\n", tc+1);
		chain  = "";
		cin >> p;
		while(p--){
			scanf("  %d", &rep);
			cin>>s;
			REP(i, rep) chain+= s;
		}
		bitset<1024000> set (chain);
		tree.assign(4*chain.size(), 0); lazy.assign(4*chain.size(), 0);
		build(1, 1, chain.size(),chain.size(), set);
	//	DEBUG(chain);
	//	PR(tree, chain.size()*2+1);
		cin >> q;
		int counter = 1;
		REP(i, q){
			cin >> op >> a >> b;
			if(op[0] == 'F')	update(1, a+1, b+1, 1, chain.size(), 1);
			else if(op[0] == 'E')	update(1, a+1, b+1, 1, chain.size(), 2);
			else if(op[0] == 'I')	update(1, a+1, b+1, 1, chain.size(), 3);
			else if(op[0] == 'S'){
				printf("Q%d: %d\n", counter, query(1, a+1, b+1, 1, chain.size()));
				counter++;
			}
		//	PR(tree, chain.size()*2+1);


		}
	}


}
