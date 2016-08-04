#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <string.h>
#include <sstream>
#include <cctype>
#include <utility>
#include <bitset>
#include <algorithm>
#include <math.h>
#include <queue>
#include <map>

using namespace std;
#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define DEBUG(x) { cout << #x << " = " << x << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }
#define NINF -100001
#define vi vector<int>
#define MAXN 100005
#define LOGMAXN 20

struct ponte {
	int o; int d; int p;
};
int P[MAXN][LOGMAXN], W[MAXN][LOGMAXN], L[MAXN], T[MAXN], D[MAXN];
vector<ponte> pontes;
bool vis[MAXN];
vector<int> E[MAXN], V[MAXN];

void buildTree(int nodes){
	bool visited[nodes];
	memset(visited, 0, nodes);
	int N = nodes;
	REP(i, pontes.size()){
			if(!visited[pontes[i].d] || !visited[pontes[i].o]){
				if(!visited[pontes[i].o]){
					N--; visited[pontes[i].o] = true;
				} if(!visited[pontes[i].d]){
					N--; visited[pontes[i].d] = true;
				}
			//	DEBUG(pontes[i].d); DEBUG(pontes[i].o); DEBUG(pontes[i].p);
				E[pontes[i].d].push_back(pontes[i].o);
				E[pontes[i].o].push_back(pontes[i].d);
				V[pontes[i].d].push_back(pontes[i].p);
				V[pontes[i].o].push_back(pontes[i].p);
			if(N==0) break;
		}
	}

}

void dfs(int n, int p, int l){
	vis[n] = true;
  T[n] = p; L[n] = l;
  for(int i = 0; i < E[n].size(); i++){
		if(!vis[E[n][i]]){
			P[E[n][i]][0] =  n;
			D[E[n][i]] = V[n][i];
			W[E[n][i]][0] = V[n][i];
			dfs(E[n][i], n, l+1);
		}
  }
}
bool  comp(ponte p1,ponte p2){  return p1.p > p2.p;}


void preprocess(int N){
  int i, j;
  //we initialize every element in P with -1
  for (i = 0; i < N; i++){
  	for (j = 0; 1 << j < N; j++){
			 W[i][j] = MAXN;
			 P[i][j] = -1;
		}
	}
  dfs(0, -1, 0);
  //the first ancestor of every node i is T[i]
//  for (i = 0; i < N; i++)  P[i][0] = T[i];

  //bottom up dynamic programing
  for (j = 1; 1 << j < N; j++){
   for (i = 0; i < N; i++){
	 		if (P[i][j - 1] != -1){
				P[i][j] = P[P[i][j - 1]][j - 1];
				W[i][j] = min(W[P[i][j - 1]][j-1] , W[i][j-1]);
			}
		}
	}

}
int query(int N, int p, int q){
	int tmp, lg, i;
	int minpath = MAXN;

//if p is situated on a higher level than q then we swap them
	if (L[p] < L[q])
			tmp = p, p = q, q = tmp;

//we compute the value of [log(L[p)]
	for (lg = 0; 1 << lg <= L[p]; lg++);
	lg--;

//we find the ancestor of node p situated on the same level
//with q using the values in P
	for (i = lg; i >= 0; i--){
			if (L[p] - (1 << i) >= L[q]){
				 minpath = min(minpath, W[p][i]);
				 p = P[p][i];
			}
		}
	if (p == q)
			return minpath;
//we compute LCA(p, q) using the values in P
	for (i = lg; i >= 0; i--){
			if (P[p][i] != -1 && P[p][i] != P[q][i]){
					p = P[p][i], q = P[q][i];
					minpath = min(  min(minpath, W[p][i]) , W[q][i] );

			}
		}
		minpath = min(D[p], D[q]);
	return minpath;
}

int main(){
	int N, M, Q, a, b,c, aux;

	while(scanf("%d %d %d", &N, &M, &Q)== 3){
		REP(i, N){
			 E[i].clear();
			 V[i].clear();
			 pontes.clear();
		 }
		memset(vis, false, N);
		ponte element;
		REP(i, M){
			scanf("%d %d %d", &a, &b, &c);
			element.o =a-1; element.d =b-1; element.p=c;
			pontes.push_back(element);
		}
		sort(pontes.begin(), pontes.begin()+M, comp);
		buildTree(N);
		preprocess(N);
/*		REP(i, N){
		REP(j,3){
			printf("%d ",W[i][j]);
		}
			printf("\n");
		}
		REP(i, N){
		REP(j,3){
			printf("%d ",P[i][j]);
		}
			printf("\n");
		}*/
		REP(q, Q){
			scanf("%d %d", &a, &b);
			a--; b--;
			aux = query(N, a, b);
			printf("%d\n", aux);
		}
	}
}
