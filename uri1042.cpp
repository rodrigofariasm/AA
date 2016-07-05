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
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  int res[3];
  res[0] = a;
  if (b<a) {
    res[1] = a;
    res[0] = b;
  }else res[1] =b;

  if(c > res[1]) res[2] = c;
  else if(c > res[0]){
    res[2] = res[1];
    res[1] = c;
  }else{
    res[2] = res[1];
    res[1] = res[0];
    res[0] = c;
  }
  printf("%d\n", res[0]);
  printf("%d\n", res[1]);
  printf("%d\n\n", res[2]);
  printf("%d\n", a);
  printf("%d\n", b);
  printf("%d\n", c);
return 0;
}
