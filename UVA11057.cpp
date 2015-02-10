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

int n,  m, aux,idx;
vector<int> b;

int bst(int v, int l, int r){
    if(l == r || l > r){
        if(b[l]==v && l != idx) return l;
        else return -1;
    }else{
        int med = (l+r)/2;
        if(b[med] == v && med != idx) return med;
        if(v < b[med]) bst(v, l, med);
        else bst(v, med+1, r);
    }
}

void solve(){
    sort(b.begin(), b.begin()+n);
    int dif = 1000002, ans;
    REP(i, n){
        idx = i;
        aux = bst(m-b[i], 0, n-1);
        if(aux != -1 && abs(b[i] - b[aux]) < dif){
            ans = b[i];
            dif = abs(b[i] - b[aux]);
        }
    }
    if(m - ans > ans)    printf("Peter should buy books whose prices are %d and %d.\n\n", ans, m-ans);
    else printf("Peter should buy books whose prices are %d and %d.\n\n", m-ans, ans);
}

int main(){
	ios :: sync_with_stdio(false);
	while(scanf("%d", &n) != EOF){
        b.clear();
        REP(i, n){
            scanf("%d", &aux);
            b.push_back(aux);
        }
        scanf("%d", &m);
        solve();
	}
	return 0;
}

