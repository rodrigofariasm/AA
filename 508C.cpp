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

int m, t, r, x;

int tempo[650];
int ncandles[650], burn;

void acende(int j){
    burn++;
    FOR(i, j+1, j+t){
        ncandles[i]++;
    }
}
int main(){
	ios :: sync_with_stdio(false);
    cin >> m >> t >> r;
    bool flag = false;
    REP(i, m){
        cin >> x;
        tempo[x+300] = 1;
    }
    if(t < r){
        cout << -1 << endl;

    }else{
        int aux;
        REP(i, 650){
            if(tempo[i] == 1){
                aux = r-ncandles[i];
                FOR(j, i-aux, i-1){
                    acende(j);

                }
            }
        }
        cout << burn << endl;
    }


	return 0;
}
