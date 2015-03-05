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

int n, m;
int main(void){
    cin >> n >> m;
    if(n >= m*2) cout << m << endl;
    else if(m >= n*2) cout << n << endl;
    else{
        int c = 0;
        while(m > 0 && n > 0){
            if(m < n && n>1){
                n-=2; m--; c++;
            }else if(m>=n && m>1){
                m-=2; n--; c++;
            }
            if(n == 1 && m == 1) break;
           // DEBUG(n);
           // DEBUG(m);
        }
        cout << c << endl;
    }
    return 0;
}
