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


const int maxn=15010;
const int maxm=1010;
const int inf=1e8;
const int mod=1e9+7;

int n,m;
ll C[maxn][maxm];
map<int,int> mp;
void Init(){
	int i,j;
	REP(i, maxn){
		C[i][0]=1;
		for(j=1;j<=i&&j<maxm;j++){
			if(j==i) C[i][j]=1;
			C[i][j]=C[i-1][j]+C[i-1][j-1];
			C[i][j]%=mod;
		}
	}
}
int main(){
    int i,j;
	scanf("%d",&n);
	Init();
	REP(i, n){
		int t;
		scanf("%d",&t);
		for(j=2;j*j<=t;j++){
			int cnt=0;
			while(t%j==0){
				t/=j;
				cnt++;
			}
			mp[j]+=cnt;
		}
		if(t>1) mp[t]++;
	}
	ll ans=1;
	EACH(it, mp){
		int t = it->second;
		ans = (ans * C[t+n-1][n-1]) % mod;
	}
	printf("%I64d\n",ans);
	return 0;
}
