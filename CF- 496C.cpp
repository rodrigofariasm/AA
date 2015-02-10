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
bitset<100> del;
int n, m;
int val[100][100];

void solve(int col, vector<int> idx){
	if(col >= m) return;
	vi prox[200];
	bool flag = true;
	//DEBUG(col);
	//PR0(idx, idx.size());
	int anterior = val[idx[0]][col];
	prox[val[idx[0]][col]].push_back(idx[0]);
	FOR(i, 1, idx.size()-1){
		if(val[idx[i]][col] < anterior){
			 del[col] = 1;
			 solve(col+1, idx);
			 flag = false;
		}
		prox[val[idx[i]][col]].push_back(idx[i]);
		anterior = val[idx[i]][col];
	}
	if(flag){
		REP(i, 200){
			if(prox[i].size() > 0){
				solve(col+1, prox[i]);
			}
		}	
	}
	
}

int main(){
	
	scanf("%d %d", &n, &m);
	string c;
	REP(i, n){
		cin >> c;
		REP(j, m){
			val[i][j] = c[j];
		}	
		
	}
	vi idx;
	REP(i, n){
		idx.push_back(i);
	}
	solve(0, idx);
	int res  = 0;
	REP(i, m){
		if(del[i] == 1) res++;
	}
	cout << res << endl;

	
	return 0;
}
