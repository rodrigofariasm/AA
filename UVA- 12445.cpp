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

int p, achou;




void backtracking(int bars[], int n, int i, int sum){
	if(n == sum){
		printf("YES\n");
		achou = 1;
		return;
	}else{
		if(sum < n && achou == 0) {
			if( i < p){
				//DEBUG(i);
				backtracking(bars, n, i+1, sum+bars[i]);
				backtracking(bars, n, i+1, sum);
			}
		}
		
	}
	
}


int main(){
	int t, n, aux;
	scanf("%d", &t);
	while(t--){
		int bars[21];
		achou = 0;
		scanf("%d", &n);
		scanf("%d", &p);
		REP(i, p){
			scanf("%d", &aux);
			bars[i] = aux;
		}	
		backtracking(bars, n, 0, 0);
		if(achou != 1){
			printf("NO\n");
		}
		
	}
	
	
	
	return 0;
}
