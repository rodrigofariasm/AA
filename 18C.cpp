#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <cctype>
#include <utility>
#include <algorithm>
#include <math.h>

using namespace std;
#define ll long long
#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define SZ(S) ((int) ((S).k()))
#define DEBUG(x) { cout << #x << " = " << x << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }

int main(){
  int x;
  scanf("%d", &x);
  int a[100000], s1 = 0, s2 = 0, r = 0;

  REP(i, x){
    cin >> a[i];
    (i != x-1 ? s1+= a[i] : s2+=a[i]);

  }
  for(int i = x-2; i>=0; i--){
    if(s1==s2) r++;
    s1 -= a[i]; s2 += a[i];

  }


  printf("%d\n", r);
return 0;
}
