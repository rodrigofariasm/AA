 // Rodrigo Farias de Mac�do

#include <string>
#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <utility>
#include <iterator>
#include <math.h>
#include <set>
#include <map>
#include <vector>
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

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vector<int> tree, arr;

void build(int node, int b, int e){
    if (b == e){
      tree[node] = arr[b-1];

    }else{
      build(2 * node, b, (b + e) / 2);
      build(2 * node + 1, (b + e) / 2 + 1, e);
      tree[node] = tree[node*2] * tree[node*2+1];
    }

  }

void update(int node, int idx, int value, int l, int r){
  if(idx < l || idx > r) return;
	if(l == r){
    if(value > 0) tree[node] = 1;
    else if(value < 0) tree[node] = -1;
    else tree[node] = 0;
    return;
  }

	update(node << 1, idx, value, l, (l+r)/2);
	update((node << 1)+1, idx, value, (l+r)/2+1, r);
	tree[node] = tree[node<<1] * tree[(node<<1)+1];
}

int query(int node, int L, int R, int i, int j){
	if(i > R || j < L) return 2;
	if(L >= i && R <= j) return tree[node];
	int p1 = query(node*2, L, (L+R)/2, i, j);
	int p2 = query(node*2+1, (L+R)/2 +1, R, i, j);
	if (p1 == 2) return p2;
	if (p2 == 2) return p1;
	return p1*p2;

}

int main(){
	ios_base::sync_with_stdio(false);
	int N, k;
	while(cin >> N){
      cin >> k;
      tree.assign(N*4, 2);
      arr.assign(N, 0);
			for(int i = 0; i<N; i++){
				int entry;
				cin >>entry ;
				if(entry > 0) entry = 1;
				else if(entry < 0) entry = -1;
				arr[i] = entry;
			}
			build(1, 1, N);
			char st; int x,y;
			for(int i = 0; i < k; i++){
				cin >> st >> x >> y;
				if(st == 'P'){
					int a = query(1, 1, N, x, y);
          if(a > 0) cout <<  "+";
					else if(a<0) cout << "-";
					else cout << "0";
				}
				if(st == 'C'){
					update(1, x , y, 1 , N);

				}
			}
    		cout << endl;


	}
	return 0;
}
