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

int n, home[100009], colors[100009], numgames,games, away[100009];


int main(){
	ios :: sync_with_stdio(false);
    scanf("%d", &n);
    numgames = (n-1)*2;
    REP(i, n){
        scanf("%d %d", &home[i], &away[i]);
        colors[home[i]]++;
    }
    REP(i, n){
        games = n-1;
        games += colors[away[i]];
        printf("%d %d\n", games, numgames-games);
    }


	return 0;
}

