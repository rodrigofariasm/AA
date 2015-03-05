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
int pos[MAX], a[MAX];
int n, m , k, app;
int main(void){
    cin >> n >> m >> k;
    FOR(i,1, n){
        cin >> a[i];
        pos[a[i]] = i;
    }
    ll ans = 0;
    FOR(i,1, m){
        cin >> app;
        if(pos[app]%k == 0) ans+= pos[app]/k;
        else ans += pos[app]/k + 1;
        if(pos[app]!=1){
            pos[app]--;
            int aux = a[pos[app]];
            a[pos[app]] = app;
            pos[aux]++;
            a[pos[aux]] = aux;
        }
    }
    cout << ans << endl;
    return 0;
}
