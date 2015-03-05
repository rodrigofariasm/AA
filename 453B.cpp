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
#define MAX 110

const int M=1e9+7;
int p[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53},n,a[128],b[128],s[64],u[128][1<<16],v[128][1<<16];
int main(){
  for(int i=1;i<64;++i)for(int j=0;j<16;++j)if(0==i%p[j])s[i]|=1<<j;
  cin>>n;
  for(int i=0;i<n;++i)cin>>a[i];
  memset(v,0x3f,sizeof(v));
  v[n][0]=0;
  for(int i=n;i-->0;)for(int j=1<<16;j-->0;){
    for(int x=1,y,z;x<64;++x)if(!(s[x]&j)&&(z=v[i+1][j]+abs(x-a[i]))<v[i][y=s[x]|j])u[i][y]=x,v[i][y]=z;
  }
  int t=0;
  for(int i=1<<16;i-->0;)if(v[0][t]>v[0][i])t=i;
  for(int i=0,x;i<n;++i)cout<<(x=u[i][t])<<' ',t^=s[x];
}

