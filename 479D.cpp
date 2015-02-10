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

int n, l, x, y, aux, ans;
int A[100009];
map<int, bool> M;

void point(ll val){
    if(val < 0 || val>l) return;
    if(M[val + y] || M[val-y]){
        ans = val; return;
    }
}

int main(){
    cin >> n >> l >> x >> y;

    REP(i, n){
        scanf("%d", &A[i]);
        M[A[i]] = true;

    }

    bool X = false, Y=false;

    REP(i, n){
        X|= M[A[i]+x] || M[A[i]-x];
        Y|= M[A[i]+y] || M[A[i]-y];
    }
    if(X && Y){
      printf("0\n"); return 0;
    }
    if(X || Y){
        printf("1\n");
        (Y ? printf("%d\n", x) : printf("%d\n", y));
        return 0;
    }
    ans = -1;
    REP(i, n){
        point(A[i] + x);
        point(A[i] - x);
    }
    if(ans == -1){
        printf("2\n%d %d\n", x, y);
    }else{
        printf("1\n%d\n", ans);
    }
    return 0;
}
