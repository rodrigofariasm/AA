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

#define MAX 100010

int n, a[MAX];
int losts[MAX];
int main(){
    ios::sync_with_stdio(0);
    cin >> n;
    REP(i, n) scanf("%d", &a[i]);
    losts[0] = a[1]; losts[n-1]= a[n-2];
    FOR(i, 1, n-2){
        losts[i] = a[i-1]+a[i+1];
    }



    return 0;
}
