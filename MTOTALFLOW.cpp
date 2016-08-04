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
#define INF 1000
#define vi vector<int>
#define MAXN 705


int res[MAXN][MAXN], mf, f, s, t;
vi p;

void augment(int v, int minEdge){

	if(v == s){
		f = minEdge; return;
	}else if(p[v]!= -1){
		augment(p[v], min(minEdge, res[p[v]][v]));
		res[p[v]][v] -= f; res[v][p[v]] += f;
	}
}

int main(){
	char a, b;
	int flow, N;
	s = 'A' - '0'; t = 'Z' - '0';
	scanf("%d\n", &N);

	REP(i, N){
		scanf("%c %c %d\n", &a, &b, &flow);
		res[a-'0'][b-'0'] += flow;
//		res[b-'0'][a-'0'] += flow;
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

	printf("%d\n", mf);
}
