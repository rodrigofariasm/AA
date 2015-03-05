// Rodrigo Farias de Macêdo
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define SZ(S) ((int) ((S).size()))
#define DEBUG(x) { cout << #x << " = " << x << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }

set<int> nodes, visited;
map<int, vector<int> > G;
map<int, int> d;

void visita(int s, int t){
	int aux;
	queue<int> Q;
	Q.push(s);
	d[s] = 0;
	visited.insert(s);
	while(!Q.empty()){
		aux = Q.back();
		Q.pop();
		REP(i, G[aux].size()){
			d[G[aux][i]] = d[aux] + 1;
			if(d[aux] >= t) break;
			visited.insert(G[aux][i]);
			Q.push(G[aux][i]);

		}

	}


}

int main() {
	int n, a, b, s, t, cases = 1;
	cin >> n;
	while(n != 0){
		G.clear();
		d.clear();
		nodes.clear();
		visited.clear();
		REP(i, n){
			cin >> a >> b;
			nodes.insert(a);
			nodes.insert(b);
			G[a].push_back(b);
			G[b].push_back(a);
		}
		while(scanf("%d %d", &s, &t) && s!=0 && t!=0){
			visited.clear();
			visita(s, t);
			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", cases, nodes.size() - visited.size(), s, t);
		}
		cin >> n;
	}
	return 0;
}
