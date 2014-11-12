 // Rodrigo Farias de Macêdo

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

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int tree[1000000];

void build(int node, int b, int e)
  {
      if (b >= e){
      }else{
		if(tree[2*node] == -101)   build(2 * node, b, (b + e) / 2);
        if(tree[2*node+1] == -101) build(2 * node + 1, (b + e) / 2 + 1, e);

          tree[node] = tree[node*2] * tree[node*2+1];
      }
  }
  
void update(int node, int value){
	tree[node] = value;
	while(node !=1){
		node = node/2;
		tree[node] = tree[node*2] * tree[node*2+1];
	}
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
	std::ios_base::sync_with_stdio(false);
	int N, k;
	while(scanf("%d %d", &N, &k)){
			for(int i=0;i<2*N; i++){
				tree[i] = -101;
			}
			for(int i = 0; i<N; i++){
				int entry;
				cin >>entry ;
				if(entry > 0) entry = 1;
				else if(entry < 0) entry = -1;	
				tree[2*N - N + i] = entry;
			}
			build(1, 1, 2*N-1);
			string res = "";
			char st; int x,y;
			for(int i = 0; i < k; i++){
				cout << i << k << endl;
				scanf("%c %d %d", &st, &x, &y);
				
				if(st == 'P'){
					int a = query(1, 1, N, x, y);
					cout << "a "<< a << endl;
					if(a > 0) res+= "+";
					else if(a<0) res+="-";
					else res+="0";
				}
				if(st == 'C'){
					update(x , y);
				}

			
			}
				cout << res << endl;
		
			
	}	
	return 0;
}
