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

int n, m;
int a[1024];//numbers 
int b[1024];
void solve(){
	int sum = 0, aux;
	if(a[1] > a[0]){
		sum++;
		
	}
	FOR(i, 2, n-1){
		aux= 0;
		FORD(j, i-1, 0){
			if(a[i] >= a[j]){
				sum++;
			}
		}
		
	}
	printf("%d\n", sum);
	
}

int main(){
	int TC;
	scanf("%d", &TC);
	int aux;
	
	while(TC--){
		scanf("%d", &n);
		REP(i, n){
			scanf("%d", &aux);
			a[i] = aux;
		}
		solve();
		
	}
	return 0;
}
