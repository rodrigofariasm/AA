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

int n, days[110], aux, c;


int main(){
	ios :: sync_with_stdio(false);
    scanf("%d %d", &n, &c);
    int mx = 0;
    REP(i, n){
        scanf("%d", &days[i]);
        if(i > 0){
            aux = days[i-1] - days[i] - c;
            mx = max(mx, aux);
        }
    }
    printf("%d\n",mx);
	return 0;
}

