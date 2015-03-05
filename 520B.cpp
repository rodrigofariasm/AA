#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define MEMO(A, B) memset(A,B,sizeof(A));
#define FAST ios :: sync_with_stdio(false);
#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define SZ(S) ((int) ((S).size()))
#define DEBUG(x) { cout << #x << " = " << x << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { REP(_,n) cout << a[_] << ' '; cout << endl; }
#define MAX 100010
int tab[10010];
int n, m;

void mark(int pos, int v){
    tab[pos] = min(tab[pos], v);
    if(tab[n] != 10010) return;
    if(pos%2 == 0 && pos/2 > 0 && tab[pos/2] == 10010){
        mark(pos/2, v+1);
    }
    mark(pos+1, min(tab[pos],v)+1);
}

int main(void){
    FAST;
    REP(i, 10010) tab[i] = 10010;
    cin >> n >> m;
    mark(m, 0);

    cout << tab[n]<<endl;
    return 0;
}
