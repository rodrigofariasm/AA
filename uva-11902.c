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

int g[101][101], n, t;

void DFS(int s){
	int aux;
	queue<int> Q;
	Q.push(s);
	visited[s] = 0;
	while(!Q.empty()){
		aux = Q.front();
		Q.pop();
		REP(i, G[aux].size()){
		    if(!visited.count(G[aux][i])){
                visited[G[aux][i]]=visited[aux]+1;
                Q.push(G[aux][i]);
		    }
		}
    }
}

int main() {
	cin>> t;
	while(t--){
        memset(g, 0, sizeof(g[0][0]) * n * n);
        cin >> n;
        REP(i,n) REP(j, n) cin >> g[i][j];


	}

	return 0;
}
