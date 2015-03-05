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

#define MAX 50
int n, m;
char tab[MAX][MAX];


int main() {
    cin >> n >> m;
    REP(i,n){
        if(i%2 == 0){
            REP(j,m) cout << '#';
        }else if((i/2)%2 == 0){
            REP(j, m-1) cout << '.';
            cout << '#';
        }else{
            cout << '#';
            REP(j, m-1) cout << '.';
        }
        cout << endl;
    }
    return 0;
}
