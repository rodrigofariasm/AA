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


int n, m, c, d, k;
const int mod = 1e9 + 7;
void solve(){
    if(n*m <= k){
        cout << 0 << endl;
        return;
    }else{
        cout << (c<n*d ? min( ( max(0,n*m-k)+n-1)/n*c , max(0,n*m-k)/n*c+max(0,n*m-k)%n*d ) : max(0,n*m-k)*d);
    }

}


int main(){
    ios::sync_with_stdio(0);
    cin >> c >> d >> n >> m >> k;
    solve();



    return 0;
}
