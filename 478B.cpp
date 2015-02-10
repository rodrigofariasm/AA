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

ll n,m;


int main(){
	ios :: sync_with_stdio(false);
	scanf("%d %d", &n, &m);
    ll kmax = (n-m+1)*(n-m)/2;
    ll r = n%m;
    ll q = n/m;
    ll kmin = (m-r)*(q*(q-1)/2) + r*(q*(q+1)/2);
    cout << kmin << " " << kmax << endl;

	return 0;
}

