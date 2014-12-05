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

const int MN = 1001;
int n, r;
vector<double> l;
int main(){
	ios :: sync_with_stdio(false);
	cin >> n >> r;
	ll aux;
	REP(i,n) {
      	cin >> aux;
       	l.push_back(aux);
    }
    sort(l.begin(), l.begin() + n); 
    double d1, d2, d3 = 0;
    d1 = l[0];
    d2 = r - l[n-1];
    FOR(i, 1, n-1){
    	if(d3 < (l[i] - l[i-1])/2){
    		d3 = (l[i] - l[i-1])/2;
    	}
    }
   // DEBUG(d1);
   // DEBUG(d2);
   // DEBUG(d3);
    d1 = max(d1, d2);
    d1 = max(d1, d3);
    printf("%.9f", d1);
	return 0;
}
