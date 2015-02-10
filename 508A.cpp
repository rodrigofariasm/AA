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

int n, m, k, x, y;

bool mat[1024][1024];

bool calcula(int a, int b){
    if(mat[a][b-1] && mat[a-1][b-1] && mat[a-1][b] && a > 10 && b > 10) return true;
    if(mat[a][b-1] && mat[a+1][b-1] && mat[a+1][b]&& a < 1010 && b > 10) return true;
    if(mat[a-1][b] && mat[a-1][b+1] && mat[a][b+1] && a > 10 && b < 1010) return true;
    if(mat[a+1][b] && mat[a+1][b+1] && mat[a][b+1] && a < 1010 && b < 1010) return true;
    return false;
}

int main(){
	ios :: sync_with_stdio(false);
    cin >> n >> m >> k;
    bool flag = false;
    REP(i, k){
        cin >> x >> y;
        mat[x+9][y+9] = true;
        if(calcula(x+9, y+9)&& !flag){
          cout << i+1 << endl;
          flag = true;
        }
    }
    if(!flag){
        cout << 0 << endl;
    }

	return 0;
}
