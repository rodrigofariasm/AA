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
#define MAX 100010


int main(void){
    FAST;
    bool l[26];
    MEMO(l, false);
    string s;
    int aa;
    cin >> aa;
    cin >> s;
    REP(i, SZ(s)){
        (s[i]-0 >=95 ? l[s[i]-97] = true : l[s[i]-65] = true);
    }
    bool a = true;
    REP(i, 26) a &= l[i];
    if(a) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
