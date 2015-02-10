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

struct node{
	vector<int> adn; //nós adjacentes
};

node A[128];
int TC, n, e; //testcases, nós e arestas
vector<int> bestNodes;

bool valid(int node, int status[]){
	vector<int> tmp = A[node].adn;
	REP(i, tmp.size()){
		if(status[tmp[i]] == 2) return false;
	}
	return true;
}

void backtrack(int node, int status[], vector<int> blackNodes){
	if(blackNodes.size()>bestNodes.size()){
		bestNodes = blackNodes;
	}
	REP(i, n){
		if(status[i] == 0 && valid(i, status)){
			status[i] = 2;
			blackNodes.push_back(i+1);
			vector<int> tmp = A[i].adn;
			REP(j, tmp.size()){
				status[tmp[j]] = 1;
			}
	
			backtrack(i, status, blackNodes);
		}
	}
	
	
	
}

int main(){
	scanf("%d", &TC);
	int a, b;
	int state[128]; //0-SemCor 1-Branco 2-Preto
	while(TC--){
		scanf("%d %d", &n , &e);
		while(e--){
			scanf("%d %d", &a, &b);
			a--; b--;
			A[a].adn.push_back(b);
			A[b].adn.push_back(a);
			
		}
		memset(state, 0, 512);
		vector<int> blacknodes;
		backtrack(0, state, blacknodes); //chamadas backtrack, apenas pro vertice 1 e seus adjacentes.
		printf("%d\n", bestNodes.size());
		REP(i, bestNodes.size()-1) printf("%d ", bestNodes[i]);
		printf("%d\n", bestNodes[bestNodes.size()-1]);
		bestNodes.clear();
		REP(i, n) A[i].adn.clear();
	}
	return 0;
}
