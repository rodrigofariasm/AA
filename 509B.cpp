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


int n, k;
int H[101];

int main() {
    scanf("%d %d", &n, &k);
    int mx = -100, mn = 110;
    REP(i, n){
        scanf("%d", &H[i]);
        mx = max(mx, H[i]);
        mn = min(mn, H[i]);
    }
    if(mx - mn - k > 0) cout << "NO" << endl;
    else{
        cout << "YES" << endl;
        REP(j, n){
            int cor = 1;
            REP(h, H[j]){
                if(h > mn) cor++;
                cout << cor << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
