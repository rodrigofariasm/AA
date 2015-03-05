#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define MEMO(A, B) memset(A,B,sizeof(A));
#define FAST ios :: sync_with_stdio(false);
#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define SZ(S) ((int) ((S).size()))
#define DEBUG(x) { cout << #x << " = " << x << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { REP(_,n) cout << a[_] << ' '; cout << endl; }

ll MOD = 1e9 + 7;
int main(void){
    FAST;
    int n;
    map<char, int> c;
    string s;
    cin >> n;
    cin >> s;
    REP(i, SZ(s)) c[s[i]] +=1;
    int nmax = 0, mx = -1;
    EACH(it, c){
        if(it->second > mx){
            nmax = 1;
            mx = it->second;
        }else if(it->second == mx) nmax++;
    }
    int t = nmax;
    ll result = t;
    REP(i, SZ(s)-1){
        result *= t;
        result %= MOD;
    }
    cout << result << endl;
    return 0;
}
