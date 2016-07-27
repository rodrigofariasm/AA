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

using namespace std;
#define ll long long
#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define DEBUG(x) { cout << #x << " = " << x << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }
#define NINF -100001
#define vi vector<int>
vector< vector< pair< int, ll> > > G;
vi L, O; //level, ocorrence
vector<pair <int, ll> > P;
void dfs(int node, int lvl){
	if(O[node] == -1)	O[node] = (P.size());
	P.push_back(node);
	L.push_back(lvl);
	REP(i, G[node].size()){
		dfs(G[node][i].first, lvl+1);
		P.push_back(node);
		L.push_back(lvl);
	}
	return;
}

ll rmq(int n1, int n2){
	sum = 0;
	for(int i = n1; i <= n2; i++){
		sum +=
	}
	return P[m];
}

int main(){
	int N, Q, a;
	ll b;
	scanf("%d", &N);
	while(N>0){
		printf("Case %d:\n", tc+1);
		scanf("%d", &N);
		vector<pair <int, ll> >  example;
		G.assign(N+1, example );
		O.assign(N+1, -1);
		REP(n, N){
			cin >> a >> b;
			if(n < a)		G[n].push_back(make_pair(a, b));
			else G[a].push_back(make_pair(n, b));
			}
		}
		dfs(0, 0);

		scanf("%d", &Q);
		REP(q, Q){
			cin >> a >> b;
			cout << ((O[a] < O[b]) ? rmq(O[a], O[b]) : rmq(O[b], O[a])) << endl;;
		}
		scanf("%d", &N);
	}


}
