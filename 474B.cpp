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

int n, m, worms[100009], aux;

int bst(int val, int l, int r){
    int med = (r+l)/2;
    if(l >= r){
        return l+1;
    }else{
        if(val <= worms[med] ){
            return bst(val, l, med);
        }else{
            return bst(val, med+1, r);
        }

    }


}

int main(){
	ios :: sync_with_stdio(false);
    scanf("%d", &n);
    REP(i, n){
        scanf("%d", &worms[i]);
        if(i>0) worms[i] += worms[i-1];
    }
    scanf("%d", &m);
    REP(i, m){
        scanf("%d", &aux);
        printf("%d\n", bst(aux, 0, n));
    }


	return 0;
}

