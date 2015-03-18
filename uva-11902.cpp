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

int g[101][101], n, t, lvl;
int reachable[101][101];
int edge[101];

void dfs(int u, int d){
    reachable[lvl][u] = 1;
    REP(i, n){
        if(i != d &&g[u][i]==1 && reachable[lvl][i]==0){
            reachable[lvl][i] = 1;
            dfs(i, d);
        }
    }

}


void DFS(int v){
    if(v!= 0){
        //deslisga arestas
        DFS(0);
        //liga arestas;
    }else{

    }

}

int main() {
	cin>> t;
	while(t--){
        lvl = 0;
        memset(g, 0, sizeof(g[0][0]) * n * n);
        memset(reachable, 0, sizeof(reachable[0][0]) * n * n);
        cin >> n;
        REP(i,n) REP(j, n) cin >> g[i][j];
        dfs(0,-1);
        REP(i, n-1){
            lvl++;
            copy(g[i+1], g[i+1]+n, edge);
            dfs(0,i+1);
        }


	}

	return 0;
}
