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


ll getFull(ll F) {
  return 3 * F * (F + 1) / 2 - F;
}

ll getMH(ll n) {
  ll l = 0;
  ll r = 10000000;
  while (l + 1 < r) {
    ll m = (l + r) / 2;
    if (getFull(m) <= n) l = m;
    else r = m;
  }
  return l;
}


int main() {
  ll n; cin >> n;
  ll mx = getMH(n);
  while ((mx + n) % 3) mx--;
  cout << (mx + 3 - 1) / 3;

}
