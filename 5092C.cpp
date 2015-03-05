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
#define MAX 343

int ans[MAX] = {};
int anSize = 0;

void makeAns() {
    FORD(i,anSize,0){
        cout << ans[i];
    }
    cout << endl;
}
void increase(int dif) {
    REP(i, MAX){
        while(dif > 0 && ans[i] < 9) {
            dif--;
            ans[i]++;
        }
        if (i > anSize) anSize = i;

        if (dif <= 0) break;
    }
}

void decrease(int &dif) {
    REP(i, MAX){
        if (i > anSize) anSize = i;
        if (dif > 0 && ans[i] < 9) {
            dif--;
            ans[i]++;
            increase(dif);
            break;
        }
        dif += ans[i];
        ans[i] = 0;
    }
}

void solve(int dif) {
    if (dif > 0) {
        increase(dif);
    } else if (dif <= 0) {
        decrease(dif);
    }
    makeAns();
}

int main() {
    int n, aux;
    int N[305];
    scanf("%d", &n);

    N[0] = 0;
    FOR(i,1,n){
        scanf("%d", &aux);
        N[i] = aux;
        solve(N[i]-N[i-1]);
    }
    return 0;
}
