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

const int M=1e9+7;
int n,q,t,a[512],p[512],d[512],v[100100]={1};
int main(){
  cin>>n>>q>>t;
  FOR(i, 1, n) cin>>a[i];
  for(int i=0,x,y;i<q&&cin>>x>>y;++i)p[x]=y,++d[y];
  int c=0;
  for(int i=1;t>=0&&i<=n;++i)if(!d[i]){
    int s=0;
    for(int j=i;t>=0&&j>0;j=p[j]){
      ++c;
      s=(a[j]+=s);
      if(p[j]>0)t-=a[j];
    }
  }
  if(t<0||c<n)cout<<0<<endl;
  else{
    for(int i=1;i<=n;++i)for(int j=a[i];j<=t;++j)if((v[j]+=v[j-a[i]])>=M)v[j]-=M;
    cout<<v[t]<<endl;
  }
}
