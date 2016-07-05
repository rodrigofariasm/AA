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
  int tc, x, y, a, b;
  scanf("%d", &tc);
  while(tc != 0){
    cin >> x >> y;
    REP(i, tc){
      cin >> a >> b;
      if(a == x || b == y) printf("divisa\n" );
      else if(a < x && b < y) printf("SO\n");
      else if(a > x && b < y) printf("SE\n");
      else if(a < x && b > y) printf("NO\n");
      else printf("NE\n");
    };
    cin >> tc;
  };

return 0;
}
