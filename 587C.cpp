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

int P[MAXN][LOGMAXN], L[MAXN], T[MAXN];
long long W[MAXN];
bool vis[MAXN];
vector<int> E[MAXN], H;
void dfs(int n, int p, int l){
	vis[n] = true;
  T[n] = p; L[n] = l;
  for(int i = 0; i < E[n].size(); i++){
		if(!vis[E[n][i]]){
			P[E[n][i]][0] =  n;
			dfs(E[n][i], n, l+1);
		}
  }
}

void preprocess(int N){
  int i, j;
  //we initialize every element in P with -1
  for (i = 0; i < N; i++){
  	for (j = 0; 1 << j < N; j++)   P[i][j] = -1;
	}
  dfs(0, 0, 0);
  //the first ancestor of every node i is T[i]
  for (i = 0; i < N; i++)  P[i][0] = T[i];

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
	return T[p];
}

vector<int> merge(vector<int> v1, vector<int> v2, int d){
	sort(v1.begin(), v1.begin()+ v1.size());
	sort(v2.begin(), v2.begin()+ v2.size());
	vector<int> res;
	int i =0;int  j=0;
	for(; (i<v1.size() || j < v2.size())&& d > 0; d--){
		DEBUG(i);
		if(i == v1.size()){
			res.push_back(v2[j]); j++;
		}else if(j == v2.size()){
			res.push_back(v1[i]); i++;
		}else if(v1[i] == res[res.size()-1]){
			i++;
			d++;
		}else if(v2[j] == res[res.size()-1]){
			j++;
			d++;
		}else if(v1[i] <= v2[j]){
			res.push_back(v1[i]); i++;
		}else{
			res.push_back(v2[j]); j++;
		}
		DEBUG(i);
	}

	return res;
}

int main(){
	int N, M, Q, a, b,c, aux;
	scanf("%d %d %d", &N, &M, &Q);
	L[0] =0;
	memset(vis, false, N);
	REP(zzz, N-1){
		scanf("%d %d", &a, &b);
		a--; b--;
		E[b].push_back(a);
		E[a].push_back(b);
	}

	REP(i, M){
		scanf("%d", &a);
		H.push_back(a);
	}
//	PR0(H,M);
	preprocess(N);
/*	REP(i, N){
	REP(j,3){
		printf("%d ",P[i][j]);
	}
		printf("\n");
	}*/
	REP(q, Q){
		scanf("%d %d %d", &a, &b,&c);
		a--; b--;
		aux = query(N, a, b);
		vector<int> ret, retau;
		while(a != aux){
			//DEBUG(a);
			if(H[a]> 0 && H[a] < 100005)	ret.push_back(H[a]);
			a = T[a];
		}
		if(H[aux]> 0 && H[aux] < 100004) ret.push_back(H[aux]);
		while(b != aux){
			if(H[b] > 0 && H[b] < 100005) retau.push_back(H[b]);
			b = T[b];
		}
		PR0(ret, ret.size());
		PR0(retau, retau.size());
		ret = merge(ret, retau, c);
	//	PR0(ret, ret.size());
		c = min((int)ret.size(), c) ;
		printf("%d", c);
		for(int i = 0; i< ret.size() && c>0; i++){
			printf(" %d", ret[i]);
			c--;
		}
		printf("\n");
	}
}
