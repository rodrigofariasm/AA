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
#define PR0(a,n) { REP(_,n) cout << a[_] << ' '; cout << endl; }

ll n, m, mat[110][110], a[110], b[110];

ll gcd(ll a, ll b){ return b == 0 ? a : gcd(b, a%b);}

int main() {
    scanf("%d %d", &n, &m);
    REP(i, n){
        REP(j, m) scanf("%d", &mat[i][j]);
    }
    a[0] = 0;
    REP(i, m) b[i] = mat[0][i];
    FOR(i, 1, n)a[i] = mat[i][0] - b[0];
    ll mx = -1;
    ll g = 0;
    REP(i, n){
        REP(j, m){
             if(a[i]+b[j]-mat[i][j]!= 0){
                g = gcd(g, abs(a[i]+b[j] - mat[i][j]));
             }
             mx = max(mx, mat[i][j]);
        }
    }
    if(g <= mx && g!= 0) printf("NO\n");
    else{
        ll k;
        if(g>mx){
            k = g;
        }else if(g==0){
            k = mx+1;
        }
        printf("YES\n%d\n", k);
        REP(i, n) if(a[i]<0) a[i] += k;
        REP(i, m) if(b[i]<0) b[i] += k;
        PR0(a, n); PR0(b, m);
    }
    return 0;
}
