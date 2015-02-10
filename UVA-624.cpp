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

int n, total, best=0;
vector<int> a;//numbers 
vector<int> bestSet; 

void backtrack(int t, int i, vector<int> a, vector<int> sol, int soma){
	vector<int> tmp;
	if((soma > best && soma <= total) || (soma == best && sol.size() > bestSet.size())) {
		best = soma;
		bestSet = sol;
	}
	if(soma <= total){
		FOR(j, i, a.size()-1){
			if(soma + a[j] <= t){
				tmp = sol;
				tmp.push_back(a[j]);
				backtrack(t, j+1, a, tmp, soma+a[j]);
			}
		}
	}
}

int main(){
	
	int aux;
	while(scanf("%d %d", &total, &n)!=EOF){
		REP(i, n){
			scanf("%d", &aux);
			a.push_back(aux);
		}
		vector<int> sol;
		backtrack(total, 0, a, sol, 0);
		REP(j, bestSet.size()-1){
			printf("%d ", bestSet[j]);
		}
		printf("%d sum:%d\n", bestSet[bestSet.size()-1], best);
		a.clear();
		bestSet.clear();
		best =0;
	
	}
	return 0;
}
