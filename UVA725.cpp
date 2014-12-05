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

int n, cont;
int main(){
	ios :: sync_with_stdio(false);	
	n = 1;
	cont = 0;
	while(n!= 0){
	
	cin >> n;
	if(n == 0 )break;
	int x, y;
	cont++;
	if(cont>1 )printf("\n");
	int flag = 0;
	for(int i = 1234; i <= 98765/n; i++){
		x = i * n;
		int tmp, used = (i < 10000);
		tmp = x; while(tmp){used |= 1 << (tmp%10); tmp /= 10;}
		tmp = i; while(tmp){used |= 1 << (tmp%10); tmp /= 10;}
		if(used == (1<<10)-1){
			flag = 1;
			printf("%0.5d / %0.5d = %d\n", x, i, n);
		}
	}
	
		
	if(flag == 0){
		cout << "There are no solutions for " << n << "." <<endl;
	}
	
	}
	return 0;
}
