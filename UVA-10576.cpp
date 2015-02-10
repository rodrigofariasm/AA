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

int s, d, somaFinal, somaCinco;
bool somasnegativas;
int total;//maximo superavit

int main(){
	while(scanf("%d %d", &s, &d)!=EOF){
		total = -1;
		somaCinco = -1;
		d = -d;
		REP(bitmask, (1<<12)){
			somasnegativas = true;
			somaFinal = 0;
			REP(i, 12){
				(bitmask & (1<<i)) != 0 ? somaFinal += s : somaFinal += d;
				if(i == 4){
					somaCinco = 0;
					REP(j, 5){
						(bitmask & (1<<j)) != 0 ? somaCinco += s : somaCinco += d;
					}
				}else if(i>4){
					(bitmask & (1 << (i-5))) != 0 ? somaCinco -= s: somaCinco -= d;
					(bitmask & (1 << (i))) != 0 ? somaCinco += s: somaCinco += d;
				}
				if(somaCinco > 0){
					somasnegativas = false;
				} 
			}
			if(somasnegativas){
				total = max(total, somaFinal);
			}
		}
		if(total >= 0){
			printf("%d\n", total);
		}else{
			printf("Deficit\n");
		}
		d =0;
		s =0;
		
		
	}

	
	return 0;
}
