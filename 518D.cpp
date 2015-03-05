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
#define MAX 100010
int main(void){
    int n, t;
    double p;
    cin >> n >> p >> t;
    double DP[n+1][t+1];
    REP(i, t) DP[0][i] = 0;
    FOR(i, 1, n)
    FOR(j, 1, t)
        DP[i][j]=p*(1+DP[i-1][j-1])+(1 - p)*DP[i][j-1];
    printf("%.6lf",DP[n][t]);

    return 0;
}
