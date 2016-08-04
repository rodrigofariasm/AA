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
#define INF 1001
#define vi vector<int>
#define MAXN 101


int res[MAXN][MAXN], mf, f, s, t;
vi p;

void augment(int v, int minEdge){
//	printf("%d %d\n", v, res[p[v]][v] );
	if(v == s){
		f = minEdge; return;
	}else if(p[v]!= -1){
		augment(p[v], min(minEdge, res[p[v]][v]));
		res[p[v]][v] -= f; res[v][p[v]] += f;
	}
}

int main(){
	int N;
	scanf("%d\n", &N);
	int a,b, flow, c; int TC = 1;
	while(N > 0){
		scanf("%d %d %d\n", &s, &t, &c);
		s--; t--;
		REP(i, c){
			scanf("%d %d %d\n", &a, &b, &flow);
			a--; b--;
			res[a][b] += flow;
			res[b][a] += flow;
		}

		mf =0;
		while(1){
			f = 0;
			vi dist(MAXN, INF); dist[s] = 0;
			queue<int> q; q.push(s);
			p.assign(MAXN, -1);
			while(!q.empty()){
				int u = q.front(); q.pop();
				if(u == t) break;
				for(int v = 0; v < MAXN; v++){
					if(res[u][v] > 0 && dist[v] == INF)
						dist[v] = dist[u]+1, q.push(v), p[v] = u;
				}
			}
			augment(t, INF);
		//	DEBUG(f);
			if(f==0) break;
			mf+=f;
		}
		printf("Network %d\nThe bandwidth is %d.\n\n", TC, mf);
		TC++;
		memset(res, 0, sizeof(res[0][0]) * MAXN * MAXN);
	//	PR0(res[t], MAXN);
		scanf("%d\n", &N);
	}
}
