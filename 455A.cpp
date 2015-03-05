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
#define MAX 100100

const int M=1e9+7;
ll N, dp[MAX], cont[MAX];
int main(){
    cin >> N;
    memset(dp,0,sizeof(dp));
    memset(cont,0,sizeof(cont));
    int aux;
    dp[0] = 0;
    FOR(i, 1, N){
        scanf("%d", &aux);
        cont[aux]++;
    }
    dp[1] = cont[1];
    for(int i = 2; i < MAX;i++){
        dp[i] = max(dp[i-1], dp[i-2]+ cont[i]*i);
    }
    cout << dp[MAX-1];

}

