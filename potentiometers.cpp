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
		if(tree[2*node] == -1)   build(2 * node, b, (b + e) / 2);
        if(tree[2*node+1] == -1) build(2 * node + 1, (b + e) / 2 + 1, e);

          tree[node] = tree[node*2] + tree[node*2+1];
      }
  }
  
void update(int node, int value){
	tree[node] = value;
	while(node !=1){
		node = node/2;
		tree[node] = tree[node*2] + tree[node*2+1];
	}
}
int query(int node, int L, int R, int i, int j){
	if(i > R || j < L) return -1;
	if(L >= i && R <= j) return tree[node];
	int p1 = query(node*2, L, (L+R)/2, i, j);
	int p2 = query(node*2+1, (L+R)/2 +1, R, i, j);
	if (p1 == -1) return p2;
	if (p2 == -1) return p1;
	return p1+p2;
	
}
  
  

int main(){
	std::ios_base::sync_with_stdio(false);
	int N, cases;
	while(scanf("%d", &N) != 0 && N!=0){
			cases++;
			for(int i=0;i<2*N; i++){
				tree[i] = -1;
			}
			for(int i = 0; i<N; i++){
				int entry;
				scanf("%d", &entry);	
				tree[2*N - N + i] = entry;
			}
			build(1, 1, 2*N-1);
			istringstream ss; 
			char res[3]; int x, y;
			printf("Case %d:\n", cases);
			cin >> res;
			while(res[0] != 'E'){
				cin >> x >> y;
				if(res[0] == 'S'){
					update(2*N - N + x, y);
				}else if(res[0] == 'M'){
					printf("%d\n", query(1, 1, N, x, y));
				}
				
			}
	}	
	return 0;
}
