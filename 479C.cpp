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

int n, x, y;
vector< pair<int, int> > ab;

bool pairCompare(const pair<int, int> &a, const pair<int, int> &b){
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int main(){
	ios :: sync_with_stdio(false);
	scanf("%d", &n);
    REP(i, n){
        scanf("%d %d", &x, &y);
        ab.push_back(make_pair(x, y));
    }
    sort(ab.begin(), ab.begin()+n, pairCompare);
    int ans = -1;
    REP(i, n){
        if(ans <= ab[i].second){
            ans = ab[i].second;
        }else ans = ab[i].first;
    }
    cout << ans << endl;


	return 0;
}

