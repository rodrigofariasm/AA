// Rodrigo Farias de Macêdo

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define EACHR(it,a) for(__typeof(a.rbegin()) it = a.rbegin(); it != a.rend(); ++it)
#define SZ(S) ((int) ((S).size()))
#define DEBUG(x) { cout << #x << " = " << x << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }
typedef vector<int> vi;


bitset<110> colored;
int color[110];
vector<vi> A;
int tc, n, k, best;
vi bestSolution;

void solve(int u) {
	if (u == n) {
		int b = 0, w = 0;
		for (int i = 0; i < n; i++) {
			if (color[i] == 0)
				b++;
			else
				w++;
		}
		if (b > best) {
			best = b;
			bestSolution.clear();
			for (int i = 0; i < n; i++) {
				if (color[i] == 0)
					bestSolution.push_back(i);
			}
		}
		return;
	}
	bool canPaint = true;
	REP(i, A[u].size()) {
		int v = A[u][i];
		if (colored[v] && color[v] == 0) {
			canPaint = false;
			break;
		}
	}
	colored.set(u);
	if (canPaint) {
		color[u] = 0;
		solve(u + 1);
	}
	color[u] = 1;
	solve(u + 1);
	colored.reset(u);
}

int main() {
	int u, v;

	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d", &n, &k);

		A.assign(n, vi());
		colored.reset();
		best = -1;
		REP(i,k){
			scanf("%d %d", &u, &v);
			u--;
			v--;
			A[u].push_back(v);
			A[v].push_back(u);
		}

		solve(0);

		printf("%d\n", best);
		REP(i, bestSolution.size()){
			printf("%d", bestSolution[i] + 1);
			if (i < (int) bestSolution.size() - 1)
				printf(" ");
		}
		printf("\n");
	}

	return 0;
}
