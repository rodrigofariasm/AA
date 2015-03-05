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
#define MAX 1010

const int M=1e9+7;
int m, n, i, j, ans, a[MAX][MAX], dp[5][MAX][MAX];
int main(){
    cin>>n>>m;
    for(i=1;i<=n;i++)for(j=1;j<=m;j++)scanf("%d",&a[i][j]);
    for(i=n;i;i--)for(j=m;j;j--)
        dp[1][i][j]=a[i][j]+max(dp[1][i+1][j],dp[1][i][j+1]);
	for(i=1;i<=n;i++)for(j=m;j;j--)
        dp[2][i][j]=a[i][j]+max(dp[2][i-1][j],dp[2][i][j+1]);
	for(i=1;i<=n;i++)for(j=1;j<=m;j++)
        dp[3][i][j]=a[i][j]+max(dp[3][i-1][j],dp[3][i][j-1]);
    for(i=n;i;i--)for(j=1;j<=m;j++)
        dp[4][i][j]=a[i][j]+max(dp[4][i+1][j],dp[4][i][j-1]);
	for(i=2;i<n;i++)for(j=2;j<m;j++)
        ans=max(ans,max(dp[1][i+1][j]+dp[3][i-1][j]+dp[2][i][j+1]+dp[4][i][j-1],dp[2][i-1][j]+dp[4][i+1][j]+dp[1][i][j+1]+dp[3][i][j-1]));
	printf("%d\n",ans);

}
