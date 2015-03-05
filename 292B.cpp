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
int boy[105], girl[105];
int m, n, a, b, aux;
int main() {
    cin >> n >> m;
    cin >> a;
    REP(i, a){
       cin >> aux;
       boy[aux] = 1;
    }
    cin >> b;
    REP(i, b){
       cin >> aux;
       girl[aux] = 1;
    }
    REP(i, 10000){
        boy[i%n] = girl[i%m] = boy[i%n] || girl[i%m];
    }
    bool ans = true;
    REP(i, n){
        ans &= boy[i];
        if(!ans) break;
    }
    REP(i, m){
        ans &= girl[i];
        if(!ans) break;
    }
    (ans ? cout << "Yes" << endl : cout << "No" << endl);
    return 0;
}
