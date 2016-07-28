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
#define LOGMAXN 14

int P[MAXN][LOGMAXN], L[MAXN];
pair<int, long long> T[MAXN];
map< pair< int, int >, long long> pesos;

void LCA(int N){
  int i, j;
  //we initialize every element in P with -1
  for (i = 0; i < N; i++){
  	for (j = 0; 1 << j < N; j++)   P[i][j] = -1;
	}
  //the first ancestor of every node i is T[i]
  for (i = 0; i < N; i++)  P[i][0] = T[i].first;

  //bottom up dynamic programing
  for (j = 1; 1 << j < N; j++){
   for (i = 0; i < N; i++)
	 		if (P[i][j - 1] != -1)
			 	P[i][j] = P[P[i][j - 1]][j - 1];
	}

}
int query(int N, int p, int q){
	int tmp, lg, i;

//if p is situated on a higher level than q then we swap them
	if (L[p] < L[q])
			tmp = p, p = q, q = tmp;

//we compute the value of [log(L[p)]
	for (lg = 1; 1 << lg <= L[p]; lg++);
	lg--;

//we find the ancestor of node p situated on the same level
//with q using the values in P
	for (i = lg; i >= 0; i--)
			if (L[p] - (1 << i) >= L[q])
					p = P[p][i];

	if (p == q)
			return p;

//we compute LCA(p, q) using the values in P
	for (i = lg; i >= 0; i--)
			if (P[p][i] != -1 && P[p][i] != P[q][i])
					p = P[p][i], q = P[q][i];
	return T[p].first;
}

int main(){
	int N, Q, a, c, aux;
	long long b;
	scanf("%d", &N);
	while(N>0){
		L[0] =0;
		FOR(n,1, N-1){
			scanf("%d %lld", &a, &b);
			if(n < a){
				T[a] = make_pair(n, b);
				L[a]
			}
			else T[n] = make_pair(a, b);

	//		pesos.insert(make_pair(make_pair(a,n), b));
	//		pesos.insert(make_pair(make_pair(a,n), b));
		}
		LCA(N);
		REP(i, N){
			REP(j, 3){
				printf("%d ", P[i][j]);
			}
			printf("\n");
		}

		scanf("%d", &Q);
		REP(q, Q){
			scanf("%d %d", &a, &c);
			aux = query(N, a, c);
			DEBUG(aux);
			b = 0;
			while(a != aux){
				//DEBUG(T[a].second);
				b+= T[a].second;
				a = T[a].first;
			}
			a = c;
			while(a != aux){
			//	DEBUG(a);
			//	DEBUG(aux);
				b+= T[a].second;
				a = T[a].first;
			}
			printf("%lld ", b);
		}
		printf("\n");
		scanf("%d", &N);
	}


}
