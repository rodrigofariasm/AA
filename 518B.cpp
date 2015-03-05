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

map<int, int> M;



int main(void){
    string s,t;
    int y=0, w=0;
    cin>>s>>t;
    REP(i, SZ(s)) M[s[i]-1]++;
    REP(i, SZ(t)){
        if(M[t[i]-1]>0){
            y++;
            M[t[i]-1]-=1;
            t[i] = '?';
        }
    }
    REP(i, SZ(t)){
        if(M[t[i]-33]>0 ){
            w++;
            M[t[i]-33]--;
        }else if(M[t[i]+31]>0){
            w++;
            M[t[i]+31]--;
        }
    }
    cout << y << " " << w << endl;
    return 0;
}
